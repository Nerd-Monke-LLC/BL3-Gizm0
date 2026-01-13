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

#define BLINK_GPIO GPIO_NUM_2

static const char *TAG = "i2c-simple-example";

#define I2C_MASTER_SCL_IO                                                      \
	GPIO_NUM_22 /*!< GPIO number used for I2C master clock */
#define I2C_MASTER_SDA_IO                                                      \
	GPIO_NUM_21 /*!< GPIO number used for I2C master data  */
#define I2C_MASTER_NUM                                                         \
	0 /*!< I2C master i2c port number, the number of i2c peripheral interfaces \
		 available will depend on the chip */
#define I2C_MASTER_FREQ_HZ 400000	/*!< I2C master clock frequency */
#define I2C_MASTER_TX_BUF_DISABLE 0 /*!< I2C master doesn't need buffer */
#define I2C_MASTER_RX_BUF_DISABLE 0 /*!< I2C master doesn't need buffer */
#define I2C_MASTER_TIMEOUT_MS 1000

char buffer[10];
float num = 12.34;

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

void app_main(void)
{
	static uint8_t led_state = 0;
	
	// Initializing GPIO2 as output
	gpio_set_direction(BLINK_GPIO, GPIO_MODE_DEF_OUTPUT);

	ESP_ERROR_CHECK(i2c_master_init());
	ESP_LOGI(TAG, "I2C initialized successfully");

	lcd_init();
	lcd_clear();

	lcd_put_cur(0, 0);
	lcd_send_string("Hello world!");

	lcd_put_cur(1, 0);
	lcd_send_string("from ESP32");

	while (true) {
		
        printf("Hello from app_main!\n");
        sleep(1);
		
		/* Toggle the LED state */
		led_state = !led_state;
		
		gpio_set_level(BLINK_GPIO, led_state);
		
    }
}
