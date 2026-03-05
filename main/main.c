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


void app_main(void)
{
	static uint8_t led_state = 0;
	
	peripheral_setup();
	
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
