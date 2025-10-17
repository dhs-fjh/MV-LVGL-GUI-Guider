/**
 * @file lv_port_disp.c
 * @brief LVGL Display Driver Port for ILI9341
 */

#if 1

/*********************
 *      INCLUDES
 *********************/
#include "lv_port_disp.h"
#include "../../Core/config/display_config.h"
#include "../../src/drivers/display/lcd_ili9341.h"
#include <stdbool.h>

/*********************
 *      DEFINES
 *********************/
#ifndef MY_DISP_HOR_RES
#define MY_DISP_HOR_RES SCREEN_HEIGHT  // 320 (横屏模式)
#endif

#ifndef MY_DISP_VER_RES
#define MY_DISP_VER_RES SCREEN_WIDTH   // 240 (横屏模式)
#endif

/**********************
 *      TYPEDEFS
 **********************/

/**********************
 *  STATIC PROTOTYPES
 **********************/
static void disp_init(void);
static void disp_flush(lv_disp_drv_t *disp_drv, const lv_area_t *area, lv_color_t *color_p);

/**********************
 *  STATIC VARIABLES
 **********************/
static const driver_lcd_interface_t *lcd = NULL;

/**********************
 *      MACROS
 **********************/

/**********************
 *   GLOBAL FUNCTIONS
 **********************/

void lv_port_disp_init(void) {
  /*-------------------------
   * Initialize your display
   * -----------------------*/
  disp_init();

  /*-----------------------------
   * Create a buffer for drawing
   *----------------------------*/

  /**
   * LVGL requires a buffer where it internally draws the widgets.
   * Later this buffer will passed to your display driver's `flush_cb` to copy
   * its content to your display. The buffer has to be greater than 1 display row
   *
   * There are 3 buffering configurations:
   * 1. Create ONE buffer:
   *      LVGL will draw the display's content here and writes it to your display
   *
   * 2. Create TWO buffer:
   *      LVGL will draw the display's content to a buffer and writes it your display.
   *      You should use DMA to write the buffer's content to the display.
   *      It will enable LVGL to draw the next part of the screen to the other
   *      buffer while the data is being sent form the first buffer. It makes
   *      rendering and flushing parallel.
   *
   * 3. Double buffering
   *      Set 2 screens sized buffers and set disp_drv.full_refresh = 1.
   *      This way LVGL will always provide the whole rendered screen in
   *      `flush_cb` and you only need to change the frame buffer's address.
   */

  /* Example for 1) */
  static lv_disp_draw_buf_t draw_buf_dsc_1;
  static lv_color_t buf_1[MY_DISP_HOR_RES * 10]; /*A buffer for 10 rows*/
  lv_disp_draw_buf_init(&draw_buf_dsc_1, buf_1, NULL,
                        MY_DISP_HOR_RES * 10); /*Initialize the display buffer*/

  /* Example for 2) */
  // static lv_disp_draw_buf_t draw_buf_dsc_2;
  // static lv_color_t buf_2_1[MY_DISP_HOR_RES * 10];  /*A buffer for 10 rows*/
  // static lv_color_t buf_2_2[MY_DISP_HOR_RES * 10];  /*Another buffer for 10 rows*/
  // lv_disp_draw_buf_init(&draw_buf_dsc_2, buf_2_1, buf_2_2, MY_DISP_HOR_RES * 10);

  /* Example for 3) also set disp_drv.full_refresh = 1 below*/
  // static lv_disp_draw_buf_t draw_buf_dsc_3;
  // static lv_color_t buf_3_1[MY_DISP_HOR_RES * MY_DISP_VER_RES]; /*A screen sized buffer*/
  // static lv_color_t buf_3_2[MY_DISP_HOR_RES * MY_DISP_VER_RES]; /*Another screen sized buffer*/
  // lv_disp_draw_buf_init(&draw_buf_dsc_3, buf_3_1, buf_3_2, MY_DISP_VER_RES * MY_DISP_HOR_RES);

  /*-----------------------------------
   * Register the display in LVGL
   *----------------------------------*/

  static lv_disp_drv_t disp_drv;        /*Descriptor of a display driver*/
  lv_disp_drv_init(&disp_drv);          /*Basic initialization*/

  /*Set up the functions to access to your display*/

  /*Set the resolution of the display*/
  disp_drv.hor_res = MY_DISP_HOR_RES;
  disp_drv.ver_res = MY_DISP_VER_RES;

  /*Used to copy the buffer's content to the display*/
  disp_drv.flush_cb = disp_flush;

  /*Set a display buffer*/
  disp_drv.draw_buf = &draw_buf_dsc_1;

  /*Required for Example 3)*/
  // disp_drv.full_refresh = 1;

  /*Finally register the driver*/
  lv_disp_drv_register(&disp_drv);
}

/**********************
 *   STATIC FUNCTIONS
 **********************/

/*Initialize your display and the required peripherals.*/
static void disp_init(void) {
  lcd = driver_lcd_get_interface();
  /*LCD initialization is already done in app.c*/
}

volatile bool disp_flush_enabled = true;

/* Enable updating the screen (the flushing process) when disp_flush() is called by LVGL */
void disp_enable_update(void) {
  disp_flush_enabled = true;
}

/* Disable updating the screen (the flushing process) when disp_flush() is called by LVGL */
void disp_disable_update(void) {
  disp_flush_enabled = false;
}

/*Flush the content of the internal buffer the specific area on the display
 *You can use DMA or any hardware acceleration to do this operation in the
 *background but 'lv_disp_flush_ready()' has to be called when finished.*/
static void disp_flush(lv_disp_drv_t *disp_drv, const lv_area_t *area,
                       lv_color_t *color_p) {
  if (disp_flush_enabled) {
    /*The most simple case (but also the slowest) to put all pixels to the
     * screen one-by-one*/
#if 0
    int32_t x;
    int32_t y;
    for(y = area->y1; y <= area->y2; y++) {
        for(x = area->x1; x <= area->x2; x++) {
            /*Put a pixel to the display. For example:*/
            /*put_px(x, y, *color_p)*/
            lcd->draw_point(x, y, color_p->full);
            color_p++;
        }
    }
#else
    /* Use hardware flush function for better performance */
    lcd->flush(area->x1, area->y1, area->x2, area->y2, (uint16_t *)color_p);
#endif
  }

  /*IMPORTANT!!!
   *Inform the graphics library that you are ready with the flushing*/
  lv_disp_flush_ready(disp_drv);
}

#else /*Enable this file at the top*/

/*This dummy typedef exists purely to silence -Wpedantic.*/
typedef int keep_pedantic_happy;
#endif
