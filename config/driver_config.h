/*
 * driver_config.h
 *
 *  Created on: Aug 31, 2010
 *      Author: nxp28548
 */

#ifndef DRIVER_CONFIG_H_
#define DRIVER_CONFIG_H

#include <LPC11xx.h>

#define CONFIG_ENABLE_DRIVER_CRP						1
#define CONFIG_CRP_SETTING_NO_CRP						1

#define CONFIG_ENABLE_DRIVER_UART						1
#define CONFIG_UART_DEFAULT_UART_IRQHANDLER				1
#define CONFIG_UART_ENABLE_INTERRUPT					1

#define CONFIG_ENABLE_DRIVER_GPIO						1
#define CONFIG_GPIO_DEFAULT_PIOINT0_IRQHANDLER                                  1

#define SSP_NUM			1

#define CONFIG_ENABLE_DRIVER_SSP    1
#define ENABLE_SSP_INTERRUPT        0

/* reset pin */
#define reset_port      1
#define reset_pin       0

/* data/command# pin */
#define dc_port         2
#define dc_pin          4


//#define CONFIG_ENABLE_DRIVER_PRINTF                     1

 /* DRIVER_CONFIG_H_ */
#endif
