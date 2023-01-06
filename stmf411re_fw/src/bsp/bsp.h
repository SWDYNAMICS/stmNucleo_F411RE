/*
 * bsp.h
 *
 *  Created on: Nov 13, 2022
 *      Author: 이승우
 */

#ifndef SRC_BSP_BSP_H_
#define SRC_BSP_BSP_H_

#include "def.h"
#define _USE_LOG_PRINT

#ifdef _USE_LOG_PRINT
#define logPrintf(fmt, ...)     printf(fmt, ##__VA_ARGS__)/*variable format*/
#else
#define logPrintf(fmt, ...)
#endif
#include "stm32f4xx_hal.h"
#include "usb_device.h"

void bspInit(void);
void delay(uint32_t ms);
uint32_t millis(void);

void Error_Handler(void);
#endif /* SRC_BSP_BSP_H_ */
