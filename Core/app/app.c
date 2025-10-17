#include "app.h"
#include "FreeRTOS.h"
#include "cmsis_os2.h"

#include "driver_led.h"
#include "driver_log.h"
#include "driver_sd_fs.h"

#include "lcd_ili9341.h"
#include "touch_xpt2046.h"

#include "hal_delay.h"
#include "hal_gpio.h"

#include "main.h"
#include "tim.h"

// #include "gui_guider.h"
// #include "events_init.h"


static const hal_delay_interface_t *hal_delay = NULL;
static const hal_gpio_interface_t *hal_gpio = NULL;
static const driver_log_interface_t *logger = NULL;
static const driver_led_interface_t *led = NULL;
static const driver_touch_interface_t *touch = NULL;
static const driver_lcd_interface_t *lcd = NULL;
static const driver_fs_interface_t *fs = NULL;

static __IO uint8_t FS_INIT_OK = 0;

void app_sys_init(void) {
  // 抽象层接口获取
  hal_delay = hal_delay_get_interface();
  hal_gpio = hal_gpio_get_interface();

  logger = driver_log_get_interface();
  logger->init();

  fs = driver_fs_get_interface();
  fs->init();

  led = driver_led_get_interface();
  led->init();

  lcd = driver_lcd_get_interface();
  touch = driver_touch_get_interface();
}

void app_default_task(void) {
  lcd->init();
  lcd->set_dir(1); // 设置显示方向：0-竖屏、1-横屏
  lcd->string(58, 8, "Waiting for FS init", 24, WHITE, BLACK);
  hal_delay->delay_ms(100);
  while (!FS_INIT_OK) {
    hal_delay->delay_ms(100);
  }

  touch->init(lcd->xlcd->width, lcd->xlcd->height, lcd->xlcd->dir);


  
  // setup_ui(&guider_ui);
  // events_init(&guider_ui);

  // lv_init();
  // lv_port_disp_init();
  // lv_port_indev_init();
  // lv_port_fs_init(); // 初始化FATFS文件系统接口

  HAL_TIM_Base_Start_IT(&htim6);

  uint32_t last_wake = hal_delay->get_tick();
  for (;;) {
    // lv_timer_handler();

    if (hal_gpio->read(KEY1_GPIO_Port, KEY1_Pin) == 1) {
      printf("KEY1 pressed, start calibration\r\n");
      // 进入触摸屏校准（校准完成后会自动重启）
      touch->re_cali();
    }

    // 每5ms执行一次循环
    hal_delay->delay_ms_until(&last_wake, 5);
  }
}

void app_led_task(void) {
  if (!led)
    return;
  led->set_blink_period(500);
  for (;;) {
    if (led->auto_blink_enabled) {
      led->toggle();
    }
    hal_delay->delay_ms(led->blink_period_ms);
  }
}

void app_led_r_task(void) {
  for (;;) {
    hal_gpio->toggle(LED_RED_GPIO_Port, LED_RED_Pin);
    // log_info("red led toggle");
    hal_delay->delay_ms(100);
  }
}

void app_log_task(void) {
  if (!logger) {
    return;
  }
  for (;;) {
    logger->process_queue();
    // hal_delay->delay_ms(100);
  }
}

void app_sd_task(void) {
  fs->init_fs(0);
  // fs->create_multi_file_demo(NULL, 100); // NULL表示根目录，创建20个文件
  // fs->create_directory("/temp");
  // fs->create_multi_file_demo("/temp", 200); // NULL表示根目录，创建20个文件
  // fs->show_partition_info();
  // fs->demo_filesystem();
  fs->show_directory_tree(NULL);
  FS_INIT_OK = 1;
  // fs->show_all_file_contents(NULL);
  for (;;) {
    hal_delay->delay_ms(1000);
    hal_gpio->toggle(LED_RED_GPIO_Port, LED_RED_Pin);
  }
}
