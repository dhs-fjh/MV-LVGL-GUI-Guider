/*
* Copyright 2025 NXP
* NXP Proprietary. This software is owned or controlled by NXP and may only be used strictly in
* accordance with the applicable license terms. By expressly accepting such terms or by downloading, installing,
* activating and/or otherwise using the software, you are agreeing that you have read, and that you agree to
* comply with and are bound by, such license terms.  If you do not agree to be bound by the applicable license
* terms, then you may not retain, install, activate or otherwise use the software.
*/

#ifndef __UI_FS_H_
#define __UI_FS_H_
#ifdef __cplusplus
extern "C" {
#endif

#include "gui_guider.h"

#define MAX_FILES_PER_PAGE 10
#define MAX_PATH_LENGTH 256
#define MAX_FILENAME_LENGTH 64

/**
 * Initialize file system browser for the storage page
 * @param ui Pointer to the UI structure
 */
void ui_fs_init(lv_ui *ui);

/**
 * Cleanup file system browser resources
 * Call this before the storage page is deleted
 */
void ui_fs_cleanup(void);

/**
 * Navigate to previous page
 * @param ui Pointer to the UI structure
 */
void ui_fs_prev_page(lv_ui *ui);

/**
 * Navigate to next page
 * @param ui Pointer to the UI structure
 */
void ui_fs_next_page(lv_ui *ui);

/**
 * Refresh the file list display
 * @param ui Pointer to the UI structure
 */
void ui_fs_refresh(lv_ui *ui);

#ifdef __cplusplus
}
#endif
#endif /* __UI_FS_H_ */
