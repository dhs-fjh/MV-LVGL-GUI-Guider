/*
* Copyright 2023 NXP
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
#include "lvgl.h"
#include "custom.h"
#include "ui_fs.h"

/*********************
 *      DEFINES
 *********************/

/**********************
 *      TYPEDEFS
 **********************/

/**********************
 *  STATIC PROTOTYPES
 **********************/
static void custom_storage_btn_prev_handler(lv_event_t *e);
static void custom_storage_btn_next_handler(lv_event_t *e);
static void custom_storage_btn_home_handler(lv_event_t *e);
static void custom_screen_monitor_timer(lv_timer_t *timer);

/**********************
 *  STATIC VARIABLES
 **********************/
static lv_ui *global_ui = NULL;
static lv_obj_t *last_screen = NULL;
static bool storage_initialized = false;

/**
 * Custom initialization - called once at startup
 */
void custom_init(lv_ui *ui)
{
    /* Add your codes here */
    global_ui = ui;

    // Create timer to monitor screen changes (100ms interval)
    // lv_timer_create(custom_screen_monitor_timer, 100, ui);

    LV_LOG_USER("custom_init: ready, monitoring screen changes");
}

/**
 * Storage page setup - called from "The custom code" section in setup_scr_ui_storage.c
 * Add event handlers and initialize file browser here
 */
void custom_storage_setup(lv_ui *ui)
{
    LV_LOG_USER("custom_storage_setup start");

    // Add event handlers for prev/next buttons
    lv_obj_add_event_cb(ui->ui_storage_btn_prev, custom_storage_btn_prev_handler, LV_EVENT_CLICKED, ui);
    lv_obj_add_event_cb(ui->ui_storage_btn_next, custom_storage_btn_next_handler, LV_EVENT_CLICKED, ui);
    lv_obj_add_event_cb(ui->ui_storage_btn_home, custom_storage_btn_home_handler, LV_EVENT_CLICKED, ui);

    // Initialize file browser
    custom_storage_init(ui);

    LV_LOG_USER("custom_storage_setup done");
}

/**
 * Initialize file system browser on storage page
 */
void custom_storage_init(lv_ui *ui)
{
    LV_LOG_USER("custom_storage_init");
    ui_fs_init(ui);
}

/**
 * Cleanup file system browser when leaving storage page
 * Call this from storage home button handler in generated code
 */
void custom_storage_cleanup(void)
{
    LV_LOG_USER("custom_storage_cleanup");
    ui_fs_cleanup();
}

/**
 * Navigate to previous page in file browser
 * Call this from prev button handler in generated code
 */
void custom_storage_prev_page(lv_ui *ui)
{
    ui_fs_prev_page(ui);
}

/**
 * Navigate to next page in file browser
 * Call this from next button handler in generated code
 */
void custom_storage_next_page(lv_ui *ui)
{
    ui_fs_next_page(ui);
}

/**********************
 *   STATIC FUNCTIONS - Event handlers
 **********************/

static void custom_storage_btn_prev_handler(lv_event_t *e)
{
    lv_ui *ui = (lv_ui *)lv_event_get_user_data(e);
    custom_storage_prev_page(ui);
}

static void custom_storage_btn_next_handler(lv_event_t *e)
{
    lv_ui *ui = (lv_ui *)lv_event_get_user_data(e);
    custom_storage_next_page(ui);
}

static void custom_storage_btn_home_handler(lv_event_t *e)
{
    lv_ui *ui = (lv_ui *)lv_event_get_user_data(e);
    LV_LOG_USER("Storage home button clicked, cleanup");
    custom_storage_cleanup();
    storage_initialized = false;
    // Note: Navigation is handled by GUI Guider's event handler
}

static void custom_screen_monitor_timer(lv_timer_t *timer)
{
    lv_ui *ui = (lv_ui *)timer->user_data;
    lv_obj_t *current_screen = lv_scr_act();

    // Detect screen change
    if (current_screen != last_screen) {
        LV_LOG_USER("Screen changed: %p -> %p", last_screen, current_screen);
        last_screen = current_screen;

        // Check if switched to storage screen
        if (ui && current_screen == ui->ui_storage && !storage_initialized) {
            LV_LOG_USER("Storage screen detected, initializing");
            custom_storage_setup(ui);
            storage_initialized = true;
        }
        // Check if left storage screen
        else if (storage_initialized && current_screen != ui->ui_storage) {
            LV_LOG_USER("Left storage screen, cleanup");
            custom_storage_cleanup();
            storage_initialized = false;
        }
    }
}

