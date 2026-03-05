/*
 * peripheral_setup.c
 *
 *  Created on: Mar 4, 2026
 *      Author: Paul
 */

 #include <stdio.h>
 #include <stdbool.h>
 #include <unistd.h>
 
 // ESP
 #include "esp_log.h"
 // GPIO
 #include "driver/gpio.h"
 #include "hal/gpio_types.h"
 #include "soc/gpio_num.h"
 //I2C
 #include "driver/i2c.h"
 //LCD
 #include "LCD1609_PCF8574.h"
 
 #include "peripheral_setup.h"
 
 
 static const char *TAG = "i2c";

 
 /**
  * @brief i2c master initialization
  */
  
 static esp_err_t i2c_master_init(void) {
 	int i2c_master_port = I2C_MASTER_NUM;

 	i2c_config_t conf = {
 		.mode = I2C_MODE_MASTER,
 		.sda_io_num = I2C_MASTER_SDA_IO,
 		.scl_io_num = I2C_MASTER_SCL_IO,
 		.sda_pullup_en = GPIO_PULLUP_ENABLE,
 		.scl_pullup_en = GPIO_PULLUP_ENABLE,
 		.master.clk_speed = I2C_MASTER_FREQ_HZ,
 	};

 	i2c_param_config(i2c_master_port, &conf);

 	return i2c_driver_install(i2c_master_port, conf.mode,
 							  I2C_MASTER_RX_BUF_DISABLE,
 							  I2C_MASTER_TX_BUF_DISABLE, 0);
 }
 
 
 //
 
void peripheral_setup(void){
	// Initializing GPIO2 as output
	gpio_set_direction(BLINK_GPIO, GPIO_MODE_DEF_OUTPUT);

	ESP_ERROR_CHECK(i2c_master_init());
	ESP_LOGI(TAG, "I2C initialized successfully");

	lcd_init();
	lcd_clear();
}
 