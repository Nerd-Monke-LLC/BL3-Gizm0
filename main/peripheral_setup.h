/*
 * peripheral_setup.h
 *
 *  Created on: Mar 4, 2026
 *      Author: Paul
 */

#ifndef MAIN_PERIPHERAL_SETUP_H_
#define MAIN_PERIPHERAL_SETUP_H_

// GPIO Defines
#define BLINK_GPIO GPIO_NUM_2


// I2C Defines
#define I2C_MASTER_SCL_IO	GPIO_NUM_22	// GPIO Master Clock
#define I2C_MASTER_SDA_IO	GPIO_NUM_21	// GPIO Master Data
#define I2C_MASTER_NUM		0 			// I2C Interface
#define I2C_MASTER_FREQ_HZ	400000		// I2C master clock frequency
#define I2C_MASTER_TX_BUF_DISABLE	0	// I2C master doesn't need buffer
#define I2C_MASTER_RX_BUF_DISABLE	0	// I2C master doesn't need buffer
#define I2C_MASTER_TIMEOUT_MS		1000


//Prototypes
void peripheral_setup(void);

#endif /* MAIN_PERIPHERAL_SETUP_H_ */
