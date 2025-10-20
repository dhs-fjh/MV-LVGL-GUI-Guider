/*
* Copyright 2025 NXP
* NXP Proprietary. This software is owned or controlled by NXP and may only be used strictly in
* accordance with the applicable license terms. By expressly accepting such terms or by downloading, installing,
* activating and/or otherwise using the software, you are agreeing that you have read, and that you agree to
* comply with and are bound by, such license terms.  If you do not agree to be bound by the applicable license
* terms, then you may not retain, install, activate or otherwise use the software.
*/

/*********************
 *      INCLUDES
 *********************/
#include <stdio.h>
#include <string.h>
#include "lvgl.h"
#include "gui_guider.h"
#include "ui_fs.h"

#ifdef _WIN32
#include <windows.h>
#include <direct.h>
#else
#include <dirent.h>
#include <sys/stat.h>
#include <unistd.h>
#endif

/*********************
 *      DEFINES
 *********************/

/*********************
 *      TYPEDEFS
 *********************/
typedef struct {
    char name[MAX_FILENAME_LENGTH];
    bool is_dir;
} file_entry_t;

/*********************
 *  STATIC VARIABLES
 *********************/
static file_entry_t file_list[256];  // Max 256 files
static uint16_t total_files = 0;
static uint16_t current_page = 0;
static uint16_t total_pages = 0;
static char current_path[MAX_PATH_LENGTH] = "C:/";
static uint32_t init_count = 0;  // Track initialization count for debugging
static bool is_initialized = false;  // Track if FS is currently initialized
static lv_ui *current_ui = NULL;  // Track current UI instance

/*********************
 *  STATIC PROTOTYPES
 *********************/
static void scan_directory(const char *path);
static void update_file_list_ui(lv_ui *ui);
static void update_page_label(lv_ui *ui);

/*********************
 *   GLOBAL FUNCTIONS
 *********************/

/**
 * Initialize file system browser
 */
void ui_fs_init(lv_ui *ui)
{
    init_count++;
    LV_LOG_USER("fs_init: %d", init_count);

    if (!ui) {
        LV_LOG_ERROR("fs_init: NULL ui");
        return;
    }

    // Store current UI instance
    current_ui = ui;
    is_initialized = true;

    // Scan root directory
    scan_directory(current_path);

    // Calculate total pages
    total_pages = (total_files + MAX_FILES_PER_PAGE - 1) / MAX_FILES_PER_PAGE;
    if (total_pages == 0) total_pages = 1;

    current_page = 0;

    LV_LOG_USER("fs_init: files=%d pages=%d", total_files, total_pages);

    // Update UI
    update_file_list_ui(ui);
    update_page_label(ui);

    LV_LOG_USER("fs_init: OK");
}

/**
 * Cleanup file system browser resources
 */
void ui_fs_cleanup(void)
{
    LV_LOG_USER("fs_cleanup: %d", init_count);

    if (!is_initialized) {
        return;
    }

    // Mark as not initialized FIRST to prevent any pending operations
    is_initialized = false;
    current_ui = NULL;

    // Reset all static variables
    total_files = 0;
    current_page = 0;
    total_pages = 0;

    LV_LOG_USER("fs_cleanup: OK");
}

/**
 * Navigate to previous page
 */
void ui_fs_prev_page(lv_ui *ui)
{
    if (!is_initialized) {
        LV_LOG_WARN("ui_fs_prev_page: not initialized");
        return;
    }

    if (current_page > 0) {
        current_page--;
        update_file_list_ui(ui);
        update_page_label(ui);
    }
}

/**
 * Navigate to next page
 */
void ui_fs_next_page(lv_ui *ui)
{
    if (!is_initialized) {
        LV_LOG_WARN("ui_fs_next_page: not initialized");
        return;
    }

    if (current_page < total_pages - 1) {
        current_page++;
        update_file_list_ui(ui);
        update_page_label(ui);
    }
}

/**
 * Refresh the file list
 */
void ui_fs_refresh(lv_ui *ui)
{
    if (!is_initialized) {
        LV_LOG_WARN("ui_fs_refresh: not initialized");
        return;
    }

    scan_directory(current_path);
    total_pages = (total_files + MAX_FILES_PER_PAGE - 1) / MAX_FILES_PER_PAGE;
    if (total_pages == 0) total_pages = 1;

    if (current_page >= total_pages) {
        current_page = total_pages - 1;
    }

    update_file_list_ui(ui);
    update_page_label(ui);
}

/*********************
 *   STATIC FUNCTIONS
 *********************/

/**
 * Scan directory and populate file list
 */
static void scan_directory(const char *path)
{
    total_files = 0;

    if (!path || path[0] == '\0') {
        LV_LOG_ERROR("scan_dir: invalid path");
        return;
    }

    LV_LOG_USER("scan_dir: %s", path);

#ifdef _WIN32
    WIN32_FIND_DATAA find_data;
    HANDLE hFind;
    char search_path[MAX_PATH_LENGTH];

    snprintf(search_path, sizeof(search_path), "%s*", path);

    hFind = FindFirstFileA(search_path, &find_data);
    if (hFind == INVALID_HANDLE_VALUE) {
        LV_LOG_WARN("scan_dir: open failed %lu", GetLastError());
        return;
    }

    do {
        // Skip "." and ".."
        if (strcmp(find_data.cFileName, ".") == 0 ||
            strcmp(find_data.cFileName, "..") == 0) {
            continue;
        }

        // Add to file list
        if (total_files < 256) {
            strncpy(file_list[total_files].name, find_data.cFileName, MAX_FILENAME_LENGTH - 1);
            file_list[total_files].name[MAX_FILENAME_LENGTH - 1] = '\0';
            file_list[total_files].is_dir = (find_data.dwFileAttributes & FILE_ATTRIBUTE_DIRECTORY) != 0;
            total_files++;
        }
    } while (FindNextFileA(hFind, &find_data) != 0 && total_files < 256);

    FindClose(hFind);
    LV_LOG_USER("scan_dir: found %d", total_files);

#else
    DIR *dir;
    struct dirent *entry;
    struct stat st;
    char full_path[MAX_PATH_LENGTH];

    dir = opendir(path);
    if (!dir) {
        return;
    }

    while ((entry = readdir(dir)) != NULL && total_files < 256) {
        // Skip "." and ".."
        if (strcmp(entry->d_name, ".") == 0 ||
            strcmp(entry->d_name, "..") == 0) {
            continue;
        }

        // Get file stat
        snprintf(full_path, sizeof(full_path), "%s%s", path, entry->d_name);
        if (stat(full_path, &st) == 0) {
            strncpy(file_list[total_files].name, entry->d_name, MAX_FILENAME_LENGTH - 1);
            file_list[total_files].name[MAX_FILENAME_LENGTH - 1] = '\0';
            file_list[total_files].is_dir = S_ISDIR(st.st_mode);
            total_files++;
        }
    }

    closedir(dir);
#endif
}

/**
 * Update file list UI
 */
static void update_file_list_ui(lv_ui *ui)
{
    if (!is_initialized || !ui || !ui->ui_storage) {
        LV_LOG_WARN("update_list: skip");
        return;
    }

    lv_obj_t *list_items[] = {
        ui->ui_storage_list_files_item0,
        ui->ui_storage_list_files_item1,
        ui->ui_storage_list_files_item2,
        ui->ui_storage_list_files_item3,
        ui->ui_storage_list_files_item4,
        ui->ui_storage_list_files_item5,
        ui->ui_storage_list_files_item6,
        ui->ui_storage_list_files_item7,
        ui->ui_storage_list_files_item8,
        ui->ui_storage_list_files_item9
    };

    uint16_t start_idx = current_page * MAX_FILES_PER_PAGE;

    for (int i = 0; i < MAX_FILES_PER_PAGE; i++) {
        if (!list_items[i]) {
            continue;
        }

        uint16_t file_idx = start_idx + i;

        if (file_idx < total_files) {
            // Get button label
            lv_obj_t *label = lv_obj_get_child(list_items[i], 1);
            if (label) {
                lv_label_set_text(label, file_list[file_idx].name);
            }

            // Update icon
            lv_obj_t *icon = lv_obj_get_child(list_items[i], 0);
            if (icon) {
                if (file_list[file_idx].is_dir) {
                    lv_label_set_text(icon, LV_SYMBOL_DIRECTORY);
                } else {
                    lv_label_set_text(icon, LV_SYMBOL_FILE);
                }
            }

            // Show item
            lv_obj_clear_flag(list_items[i], LV_OBJ_FLAG_HIDDEN);
        } else {
            // Hide unused items
            lv_obj_add_flag(list_items[i], LV_OBJ_FLAG_HIDDEN);
        }
    }
}

/**
 * Update page label
 */
static void update_page_label(lv_ui *ui)
{
    if (!is_initialized || !ui || !ui->ui_storage_label_page) {
        return;
    }

    char page_text[16];
    snprintf(page_text, sizeof(page_text), "%d/%d", current_page + 1, total_pages);
    lv_label_set_text(ui->ui_storage_label_page, page_text);
}
