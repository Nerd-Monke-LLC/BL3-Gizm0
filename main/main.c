#include <stdio.h>
#include <stdbool.h>
#include <unistd.h>
#include "driver/gpio.h"
#include "hal/gpio_types.h"
#include "soc/gpio_num.h"

#define BLINK_GPIO GPIO_NUM_2

void app_main(void)
{
	static uint8_t led_state = 0;
	
	// Initializing GPIO2 as output
	gpio_set_direction(BLINK_GPIO, GPIO_MODE_DEF_OUTPUT);
	
	while (true) {
		
        printf("Hello from app_main!\n");
        sleep(1);
		
		/* Toggle the LED state */
		led_state = !led_state;
		
		gpio_set_level(BLINK_GPIO, led_state);
		
    }
}
