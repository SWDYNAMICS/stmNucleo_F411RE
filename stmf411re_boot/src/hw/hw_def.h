/*
 * hw_def.h
 *
 *  Created on: Nov 13, 2022
 *      Author: 이승우
 *      hardware 모듈들이 공통으로 쓰는 정의들
 */

#ifndef SRC_HW_HW_DEF_H_
#define SRC_HW_HW_DEF_H_

#include "def.h"
#include "bsp.h"

#define _USE_HW_USB
//#define _USE_HW_CDC
#define _USE_HW_RTC
#define _USE_HW_RESET
#define _USE_HW_FLASH

#define _USE_HW_LED
#define 		 HW_LED_MAX_CH					  1

//#define _USE_HW_UART
//#define 	   HW_UART_MAX_CH					  2

#endif /* SRC_HW_HW_DEF_H_ */
