/*
* Copyright 2025 NXP
* NXP Proprietary. This software is owned or controlled by NXP and may only be used strictly in
* accordance with the applicable license terms. By expressly accepting such terms or by downloading, installing,
* activating and/or otherwise using the software, you are agreeing that you have read, and that you agree to
* comply with and are bound by, such license terms.  If you do not agree to be bound by the applicable license
* terms, then you may not retain, install, activate or otherwise use the software.
*/

#include "events_init.h"
#include <stdio.h>
#include "lvgl.h"

#if LV_USE_GUIDER_SIMULATOR && LV_USE_FREEMASTER
#include "freemaster_client.h"
#endif

static uint32_t ui_led_slider_period_val = 500;
static bool ui_led_cb_blink_checked = 0;
static bool ui_led_cb_sta_checked = 0;

static void ui_main_btn_pwr_event_handler (lv_event_t *e)
{
    lv_event_code_t code = lv_event_get_code(e);
    switch (code) {
    case LV_EVENT_CLICKED:
    {
        break;
    }
    default:
        break;
    }
}

static void ui_main_btn_IO_event_handler (lv_event_t *e)
{
    lv_event_code_t code = lv_event_get_code(e);
    switch (code) {
    case LV_EVENT_CLICKED:
    {
        ui_load_scr_animation(&guider_ui, &guider_ui.ui_IO, guider_ui.ui_IO_del, &guider_ui.ui_main_del, setup_scr_ui_IO, LV_SCR_LOAD_ANIM_MOVE_LEFT, 200, 0, false, true);
        break;
    }
    default:
        break;
    }
}

static void ui_main_btn_comm_event_handler (lv_event_t *e)
{
    lv_event_code_t code = lv_event_get_code(e);
    switch (code) {
    case LV_EVENT_CLICKED:
    {
        ui_load_scr_animation(&guider_ui, &guider_ui.ui_comm, guider_ui.ui_comm_del, &guider_ui.ui_main_del, setup_scr_ui_comm, LV_SCR_LOAD_ANIM_MOVE_LEFT, 200, 0, false, true);
        break;
    }
    default:
        break;
    }
}

static void ui_main_btn_led_event_handler (lv_event_t *e)
{
    lv_event_code_t code = lv_event_get_code(e);
    switch (code) {
    case LV_EVENT_CLICKED:
    {
        ui_load_scr_animation(&guider_ui, &guider_ui.ui_led, guider_ui.ui_led_del, &guider_ui.ui_main_del, setup_scr_ui_led, LV_SCR_LOAD_ANIM_MOVE_LEFT, 200, 0, false, true);
        break;
    }
    default:
        break;
    }
}

static void ui_main_btn_storage_event_handler (lv_event_t *e)
{
    lv_event_code_t code = lv_event_get_code(e);
    switch (code) {
    case LV_EVENT_CLICKED:
    {
        ui_load_scr_animation(&guider_ui, &guider_ui.ui_storage, guider_ui.ui_storage_del, &guider_ui.ui_main_del, setup_scr_ui_storage, LV_SCR_LOAD_ANIM_MOVE_LEFT, 200, 0, false, true);
        break;
    }
    default:
        break;
    }
}

static void ui_main_btn_settings_event_handler (lv_event_t *e)
{
    lv_event_code_t code = lv_event_get_code(e);
    switch (code) {
    case LV_EVENT_CLICKED:
    {
        ui_load_scr_animation(&guider_ui, &guider_ui.ui_settings, guider_ui.ui_settings_del, &guider_ui.ui_main_del, setup_scr_ui_settings, LV_SCR_LOAD_ANIM_MOVE_LEFT, 200, 0, false, true);
        break;
    }
    default:
        break;
    }
}

void events_init_ui_main (lv_ui *ui)
{
    lv_obj_add_event_cb(ui->ui_main_btn_pwr, ui_main_btn_pwr_event_handler, LV_EVENT_ALL, ui);
    lv_obj_add_event_cb(ui->ui_main_btn_IO, ui_main_btn_IO_event_handler, LV_EVENT_ALL, ui);
    lv_obj_add_event_cb(ui->ui_main_btn_comm, ui_main_btn_comm_event_handler, LV_EVENT_ALL, ui);
    lv_obj_add_event_cb(ui->ui_main_btn_led, ui_main_btn_led_event_handler, LV_EVENT_ALL, ui);
    lv_obj_add_event_cb(ui->ui_main_btn_storage, ui_main_btn_storage_event_handler, LV_EVENT_ALL, ui);
    lv_obj_add_event_cb(ui->ui_main_btn_settings, ui_main_btn_settings_event_handler, LV_EVENT_ALL, ui);
}

static void ui_settings_btn_home_event_handler (lv_event_t *e)
{
    lv_event_code_t code = lv_event_get_code(e);
    switch (code) {
    case LV_EVENT_CLICKED:
    {
        ui_load_scr_animation(&guider_ui, &guider_ui.ui_main, guider_ui.ui_main_del, &guider_ui.ui_settings_del, setup_scr_ui_main, LV_SCR_LOAD_ANIM_MOVE_RIGHT, 200, 0, false, true);
        break;
    }
    default:
        break;
    }
}

void events_init_ui_settings (lv_ui *ui)
{
    lv_obj_add_event_cb(ui->ui_settings_btn_home, ui_settings_btn_home_event_handler, LV_EVENT_ALL, ui);
}

static void ui_storage_event_handler (lv_event_t *e)
{
    lv_event_code_t code = lv_event_get_code(e);
    switch (code) {
    case LV_EVENT_CLICKED:
    {
        break;
    }
    default:
        break;
    }
}

static void ui_storage_btn_next_event_handler (lv_event_t *e)
{
    lv_event_code_t code = lv_event_get_code(e);
    switch (code) {
    case LV_EVENT_CLICKED:
    {
        break;
    }
    default:
        break;
    }
}

static void ui_storage_btn_prev_event_handler (lv_event_t *e)
{
    lv_event_code_t code = lv_event_get_code(e);
    switch (code) {
    case LV_EVENT_CLICKED:
    {
        break;
    }
    default:
        break;
    }
}

static void ui_storage_btn_home_event_handler (lv_event_t *e)
{
    lv_event_code_t code = lv_event_get_code(e);
    switch (code) {
    case LV_EVENT_CLICKED:
    {
        ui_load_scr_animation(&guider_ui, &guider_ui.ui_main, guider_ui.ui_main_del, &guider_ui.ui_storage_del, setup_scr_ui_main, LV_SCR_LOAD_ANIM_MOVE_RIGHT, 200, 0, false, true);
        break;
    }
    default:
        break;
    }
}

void events_init_ui_storage (lv_ui *ui)
{
    lv_obj_add_event_cb(ui->ui_storage, ui_storage_event_handler, LV_EVENT_ALL, ui);
    lv_obj_add_event_cb(ui->ui_storage_btn_next, ui_storage_btn_next_event_handler, LV_EVENT_ALL, ui);
    lv_obj_add_event_cb(ui->ui_storage_btn_prev, ui_storage_btn_prev_event_handler, LV_EVENT_ALL, ui);
    lv_obj_add_event_cb(ui->ui_storage_btn_home, ui_storage_btn_home_event_handler, LV_EVENT_ALL, ui);
}

static void ui_comm_list_comm_item3_event_handler (lv_event_t *e)
{
    lv_event_code_t code = lv_event_get_code(e);
    switch (code) {
    case LV_EVENT_PRESSED:
    {
        ui_load_scr_animation(&guider_ui, &guider_ui.ui_comm_RC, guider_ui.ui_comm_RC_del, &guider_ui.ui_comm_del, setup_scr_ui_comm_RC, LV_SCR_LOAD_ANIM_MOVE_BOTTOM, 200, 0, false, true);
        break;
    }
    default:
        break;
    }
}

static void ui_comm_btn_home_event_handler (lv_event_t *e)
{
    lv_event_code_t code = lv_event_get_code(e);
    switch (code) {
    case LV_EVENT_CLICKED:
    {
        ui_load_scr_animation(&guider_ui, &guider_ui.ui_main, guider_ui.ui_main_del, &guider_ui.ui_comm_del, setup_scr_ui_main, LV_SCR_LOAD_ANIM_MOVE_RIGHT, 200, 0, false, true);
        break;
    }
    default:
        break;
    }
}

void events_init_ui_comm (lv_ui *ui)
{
    lv_obj_add_event_cb(ui->ui_comm_list_comm_item3, ui_comm_list_comm_item3_event_handler, LV_EVENT_ALL, ui);
    lv_obj_add_event_cb(ui->ui_comm_btn_home, ui_comm_btn_home_event_handler, LV_EVENT_ALL, ui);
}

static void ui_comm_RC_btn_back_event_handler (lv_event_t *e)
{
    lv_event_code_t code = lv_event_get_code(e);
    switch (code) {
    case LV_EVENT_PRESSED:
    {
        ui_load_scr_animation(&guider_ui, &guider_ui.ui_comm, guider_ui.ui_comm_del, &guider_ui.ui_comm_RC_del, setup_scr_ui_comm, LV_SCR_LOAD_ANIM_MOVE_TOP, 200, 0, false, true);
        break;
    }
    default:
        break;
    }
}

void events_init_ui_comm_RC (lv_ui *ui)
{
    lv_obj_add_event_cb(ui->ui_comm_RC_btn_back, ui_comm_RC_btn_back_event_handler, LV_EVENT_ALL, ui);
}

static void ui_IO_btn_home_event_handler (lv_event_t *e)
{
    lv_event_code_t code = lv_event_get_code(e);
    switch (code) {
    case LV_EVENT_CLICKED:
    {
        ui_load_scr_animation(&guider_ui, &guider_ui.ui_main, guider_ui.ui_main_del, &guider_ui.ui_IO_del, setup_scr_ui_main, LV_SCR_LOAD_ANIM_MOVE_RIGHT, 200, 0, false, true);
        break;
    }
    default:
        break;
    }
}

void events_init_ui_IO (lv_ui *ui)
{
    lv_obj_add_event_cb(ui->ui_IO_btn_home, ui_IO_btn_home_event_handler, LV_EVENT_ALL, ui);
}

static void ui_led_event_handler (lv_event_t *e)
{
    lv_event_code_t code = lv_event_get_code(e);
    switch (code) {
    case LV_EVENT_SCREEN_LOAD_START:
    {
        // 加载LED闪烁使能值
        if(ui_led_cb_blink_checked)
            lv_obj_add_state(guider_ui.ui_led_cb_blink, LV_STATE_CHECKED);

        // 加载LED当前状态
        // ui_led_cb_sta_checked = ; // 读取LED状态
        if(ui_led_cb_sta_checked)
            lv_obj_add_state(guider_ui.ui_led_cb_sta, LV_STATE_CHECKED);

        // 加载LED闪烁间隔值
        lv_slider_set_value(guider_ui.ui_led_slider_period, ui_led_slider_period_val, LV_ANIM_OFF);
        char buf[5];
        lv_snprintf(buf, sizeof(buf), "%4d", ui_led_slider_period_val);  // 格式化为4位数
        lv_label_set_text(guider_ui.ui_led_label_period, buf);


        break;
    }
    default:
        break;
    }
}

static void ui_led_slider_period_event_handler (lv_event_t *e)
{
    lv_event_code_t code = lv_event_get_code(e);
    switch (code) {
    case LV_EVENT_VALUE_CHANGED:
    {
        lv_obj_t *slider = lv_event_get_target(e);
        ui_led_slider_period_val = lv_slider_get_value(slider);
        char buf[5];
        lv_snprintf(buf, sizeof(buf), "%4d", ui_led_slider_period_val);  // 格式化为4位数
        lv_label_set_text(guider_ui.ui_led_label_period, buf);
        LV_LOG_USER("LED blink period: %d", ui_led_slider_period_val);
        break;
    }
    default:
        break;
    }
}

static void ui_led_cb_sta_event_handler (lv_event_t *e)
{
    lv_event_code_t code = lv_event_get_code(e);
    switch (code) {
    case LV_EVENT_CLICKED:
    {
        lv_obj_t * status_obj = lv_event_get_target(e);
        int status = lv_obj_get_state(status_obj) & LV_STATE_CHECKED ? true : false;
        if(status) {
            ui_led_cb_sta_checked = 1;
        } else {
            ui_led_cb_sta_checked = 0;
        }
        LV_LOG_USER("LED status: %d", ui_led_cb_sta_checked);
        break;
    }
    default:
        break;
    }
}

static void ui_led_cb_blink_event_handler (lv_event_t *e)
{
    lv_event_code_t code = lv_event_get_code(e);
    switch (code) {
    case LV_EVENT_CLICKED:
    {
        lv_obj_t * status_obj = lv_event_get_target(e);
        int status = lv_obj_get_state(status_obj) & LV_STATE_CHECKED ? true : false;
        if(status) {
            ui_led_cb_blink_checked = 1;
        } else {
            ui_led_cb_blink_checked = 0;
        }
        LV_LOG_USER("LED auto blink: %d", ui_led_cb_blink_checked);
        break;
    }
    default:
        break;
    }
}

static void ui_led_btn_home_event_handler (lv_event_t *e)
{
    lv_event_code_t code = lv_event_get_code(e);
    switch (code) {
    case LV_EVENT_CLICKED:
    {
        ui_load_scr_animation(&guider_ui, &guider_ui.ui_main, guider_ui.ui_main_del, &guider_ui.ui_led_del, setup_scr_ui_main, LV_SCR_LOAD_ANIM_MOVE_RIGHT, 200, 0, false, true);
        break;
    }
    default:
        break;
    }
}

void events_init_ui_led (lv_ui *ui)
{
    lv_obj_add_event_cb(ui->ui_led, ui_led_event_handler, LV_EVENT_ALL, ui);
    lv_obj_add_event_cb(ui->ui_led_slider_period, ui_led_slider_period_event_handler, LV_EVENT_ALL, ui);
    lv_obj_add_event_cb(ui->ui_led_cb_sta, ui_led_cb_sta_event_handler, LV_EVENT_ALL, ui);
    lv_obj_add_event_cb(ui->ui_led_cb_blink, ui_led_cb_blink_event_handler, LV_EVENT_ALL, ui);
    lv_obj_add_event_cb(ui->ui_led_btn_home, ui_led_btn_home_event_handler, LV_EVENT_ALL, ui);
}


void events_init(lv_ui *ui)
{

}
