/*
 * reset.c
 *
 *  Created on: 2022. 12. 20.
 *      Author: USER
 */

#include "reset.h"
#include "rtc.h"

static uint32_t reset_count = 0;

bool resetInit(void)
{
	bool ret = true;

	if(RCC->CSR & (1<<26))
	{
		rtcBackupRegWrite(0, rtcBackupRegRead(0) + 1);
		delay(500);
		/* due to multiple input */
		reset_count = rtcBackupRegRead(0);
		/* one count increase itself */
	}
	rtcBackupRegWrite(0, 0);
	return ret;
}
uint32_t resetGetCount(void)
{
	return reset_count;
}

