/*
* Copyright 2025 NXP
* NXP Proprietary. This software is owned or controlled by NXP and may only be used strictly in
* accordance with the applicable license terms. By expressly accepting such terms or by downloading, installing,
* activating and/or otherwise using the software, you are agreeing that you have read, and that you agree to
* comply with and are bound by, such license terms.  If you do not agree to be bound by the applicable license
* terms, then you may not retain, install, activate or otherwise use the software.
*/

#include "lvgl.h"
#include <stdio.h>
#include "gui_guider.h"
#include "events_init.h"
#include "widgets_init.h"
#include "custom.h"



void setup_scr_ui_comm_RC(lv_ui *ui)
{
    //Write codes ui_comm_RC
    ui->ui_comm_RC = lv_obj_create(NULL);
    lv_obj_set_size(ui->ui_comm_RC, 320, 240);
    lv_obj_set_scrollbar_mode(ui->ui_comm_RC, LV_SCROLLBAR_MODE_OFF);

    //Write style for ui_comm_RC, Part: LV_PART_MAIN, State: LV_STATE_DEFAULT.
    lv_obj_set_style_bg_opa(ui->ui_comm_RC, 0, LV_PART_MAIN|LV_STATE_DEFAULT);

    //Write codes ui_comm_RC_table_1
    ui->ui_comm_RC_table_1 = lv_table_create(ui->ui_comm_RC);
    lv_table_set_col_cnt(ui->ui_comm_RC_table_1,3);
    lv_table_set_row_cnt(ui->ui_comm_RC_table_1,6);
    lv_table_set_cell_value(ui->ui_comm_RC_table_1,0,0,"Name");
    lv_table_set_cell_value(ui->ui_comm_RC_table_1,1,0,"Apple");
    lv_table_set_cell_value(ui->ui_comm_RC_table_1,2,0,"Banana");
    lv_table_set_cell_value(ui->ui_comm_RC_table_1,3,0,"Citron");
    lv_table_set_cell_value(ui->ui_comm_RC_table_1,4,0,"Name");
    lv_table_set_cell_value(ui->ui_comm_RC_table_1,5,0,"Name");
    lv_table_set_cell_value(ui->ui_comm_RC_table_1,0,1,"Price");
    lv_table_set_cell_value(ui->ui_comm_RC_table_1,1,1,"$1");
    lv_table_set_cell_value(ui->ui_comm_RC_table_1,2,1,"$2");
    lv_table_set_cell_value(ui->ui_comm_RC_table_1,3,1,"$3");
    lv_table_set_cell_value(ui->ui_comm_RC_table_1,4,1,"Price");
    lv_table_set_cell_value(ui->ui_comm_RC_table_1,5,1,"Price");
    lv_table_set_cell_value(ui->ui_comm_RC_table_1,0,2,"title");
    lv_table_set_cell_value(ui->ui_comm_RC_table_1,1,2,"0");
    lv_table_set_cell_value(ui->ui_comm_RC_table_1,2,2,"0");
    lv_table_set_cell_value(ui->ui_comm_RC_table_1,3,2,"0");
    lv_table_set_cell_value(ui->ui_comm_RC_table_1,4,2,"title");
    lv_table_set_cell_value(ui->ui_comm_RC_table_1,5,2,"title");
    lv_obj_set_pos(ui->ui_comm_RC_table_1, -24, 42);
    lv_obj_set_scrollbar_mode(ui->ui_comm_RC_table_1, LV_SCROLLBAR_MODE_OFF);

    //Write style for ui_comm_RC_table_1, Part: LV_PART_MAIN, State: LV_STATE_DEFAULT.
    lv_obj_set_style_pad_top(ui->ui_comm_RC_table_1, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_pad_bottom(ui->ui_comm_RC_table_1, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_pad_left(ui->ui_comm_RC_table_1, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_pad_right(ui->ui_comm_RC_table_1, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_bg_opa(ui->ui_comm_RC_table_1, 255, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_bg_color(ui->ui_comm_RC_table_1, lv_color_hex(0xffffff), LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_bg_grad_dir(ui->ui_comm_RC_table_1, LV_GRAD_DIR_NONE, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_border_width(ui->ui_comm_RC_table_1, 2, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_border_opa(ui->ui_comm_RC_table_1, 255, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_border_color(ui->ui_comm_RC_table_1, lv_color_hex(0xd5dee6), LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_border_side(ui->ui_comm_RC_table_1, LV_BORDER_SIDE_FULL, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_radius(ui->ui_comm_RC_table_1, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_shadow_width(ui->ui_comm_RC_table_1, 0, LV_PART_MAIN|LV_STATE_DEFAULT);

    //Write style for ui_comm_RC_table_1, Part: LV_PART_ITEMS, State: LV_STATE_DEFAULT.
    lv_obj_set_style_text_color(ui->ui_comm_RC_table_1, lv_color_hex(0x393c41), LV_PART_ITEMS|LV_STATE_DEFAULT);
    lv_obj_set_style_text_font(ui->ui_comm_RC_table_1, &lv_font_montserratMedium_16, LV_PART_ITEMS|LV_STATE_DEFAULT);
    lv_obj_set_style_text_opa(ui->ui_comm_RC_table_1, 255, LV_PART_ITEMS|LV_STATE_DEFAULT);
    lv_obj_set_style_text_align(ui->ui_comm_RC_table_1, LV_TEXT_ALIGN_CENTER, LV_PART_ITEMS|LV_STATE_DEFAULT);
    lv_obj_set_style_bg_opa(ui->ui_comm_RC_table_1, 0, LV_PART_ITEMS|LV_STATE_DEFAULT);
    lv_obj_set_style_border_width(ui->ui_comm_RC_table_1, 3, LV_PART_ITEMS|LV_STATE_DEFAULT);
    lv_obj_set_style_border_opa(ui->ui_comm_RC_table_1, 255, LV_PART_ITEMS|LV_STATE_DEFAULT);
    lv_obj_set_style_border_color(ui->ui_comm_RC_table_1, lv_color_hex(0xd5dee6), LV_PART_ITEMS|LV_STATE_DEFAULT);
    lv_obj_set_style_border_side(ui->ui_comm_RC_table_1, LV_BORDER_SIDE_FULL, LV_PART_ITEMS|LV_STATE_DEFAULT);
    lv_obj_set_style_pad_top(ui->ui_comm_RC_table_1, 10, LV_PART_ITEMS|LV_STATE_DEFAULT);
    lv_obj_set_style_pad_bottom(ui->ui_comm_RC_table_1, 10, LV_PART_ITEMS|LV_STATE_DEFAULT);
    lv_obj_set_style_pad_left(ui->ui_comm_RC_table_1, 10, LV_PART_ITEMS|LV_STATE_DEFAULT);
    lv_obj_set_style_pad_right(ui->ui_comm_RC_table_1, 10, LV_PART_ITEMS|LV_STATE_DEFAULT);

    //Write codes ui_comm_RC_label_tittle
    ui->ui_comm_RC_label_tittle = lv_label_create(ui->ui_comm_RC);
    lv_label_set_text(ui->ui_comm_RC_label_tittle, "RC Data View");
    lv_label_set_long_mode(ui->ui_comm_RC_label_tittle, LV_LABEL_LONG_WRAP);
    lv_obj_set_pos(ui->ui_comm_RC_label_tittle, 70, 15);
    lv_obj_set_size(ui->ui_comm_RC_label_tittle, 180, 30);

    //Write style for ui_comm_RC_label_tittle, Part: LV_PART_MAIN, State: LV_STATE_DEFAULT.
    lv_obj_set_style_border_width(ui->ui_comm_RC_label_tittle, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_radius(ui->ui_comm_RC_label_tittle, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_text_color(ui->ui_comm_RC_label_tittle, lv_color_hex(0x000000), LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_text_font(ui->ui_comm_RC_label_tittle, &lv_font_montserratMedium_16, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_text_opa(ui->ui_comm_RC_label_tittle, 255, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_text_letter_space(ui->ui_comm_RC_label_tittle, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_text_line_space(ui->ui_comm_RC_label_tittle, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_text_align(ui->ui_comm_RC_label_tittle, LV_TEXT_ALIGN_CENTER, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_bg_opa(ui->ui_comm_RC_label_tittle, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_pad_top(ui->ui_comm_RC_label_tittle, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_pad_right(ui->ui_comm_RC_label_tittle, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_pad_bottom(ui->ui_comm_RC_label_tittle, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_pad_left(ui->ui_comm_RC_label_tittle, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_shadow_width(ui->ui_comm_RC_label_tittle, 0, LV_PART_MAIN|LV_STATE_DEFAULT);

    //Write codes ui_comm_RC_btn_back
    ui->ui_comm_RC_btn_back = lv_btn_create(ui->ui_comm_RC);
    ui->ui_comm_RC_btn_back_label = lv_label_create(ui->ui_comm_RC_btn_back);
    lv_label_set_text(ui->ui_comm_RC_btn_back_label, "" LV_SYMBOL_LEFT " ");
    lv_label_set_long_mode(ui->ui_comm_RC_btn_back_label, LV_LABEL_LONG_WRAP);
    lv_obj_align(ui->ui_comm_RC_btn_back_label, LV_ALIGN_CENTER, 0, 0);
    lv_obj_set_style_pad_all(ui->ui_comm_RC_btn_back, 0, LV_STATE_DEFAULT);
    lv_obj_set_width(ui->ui_comm_RC_btn_back_label, LV_PCT(100));
    lv_obj_set_pos(ui->ui_comm_RC_btn_back, 5, 5);
    lv_obj_set_size(ui->ui_comm_RC_btn_back, 40, 30);

    //Write style for ui_comm_RC_btn_back, Part: LV_PART_MAIN, State: LV_STATE_DEFAULT.
    lv_obj_set_style_bg_opa(ui->ui_comm_RC_btn_back, 255, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_bg_color(ui->ui_comm_RC_btn_back, lv_color_hex(0xff0027), LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_bg_grad_dir(ui->ui_comm_RC_btn_back, LV_GRAD_DIR_NONE, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_border_width(ui->ui_comm_RC_btn_back, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_radius(ui->ui_comm_RC_btn_back, 5, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_shadow_width(ui->ui_comm_RC_btn_back, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_text_color(ui->ui_comm_RC_btn_back, lv_color_hex(0xffffff), LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_text_font(ui->ui_comm_RC_btn_back, &lv_font_montserratMedium_16, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_text_opa(ui->ui_comm_RC_btn_back, 255, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_text_align(ui->ui_comm_RC_btn_back, LV_TEXT_ALIGN_CENTER, LV_PART_MAIN|LV_STATE_DEFAULT);

    //The custom code of ui_comm_RC.


    //Update current screen layout.
    lv_obj_update_layout(ui->ui_comm_RC);

    //Init events for screen.
    events_init_ui_comm_RC(ui);
}
