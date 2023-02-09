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

	if(RCC->CSR == (1<<26))
	{
		rtcBackupRegWrite(0, rtcBackupRegRead(0) + 1);
		delay(500);
		/* due to multiple input */
		reset_count = rtcBackupRegRead(0);
		/* one count increase itself */
	}
	rtcBackupRegWrite(0, 0);

	if(reset_count !=2)
	{
	  /*if not bl, jump*/
	  void (**jump_func)() = (void (**)())(0x8008000 + 4);/*except 4byte of _estack pointer*/

	  if((uint32_t)*jump_func != 0xFFFFFFFF)
	  {
	    /*fw data exists*/
	    HAL_RCC_DeInit();
	    HAL_DeInit();
	    for(int i=0; i<8; i++)
	    {
	      NVIC->ICER[i] = 0xFFFFFFFF;
	      __DSB();
	      __ISB();
	    }
	    SysTick->CTRL = 0;

	    (*jump_func)();
	  }
	}

	return ret;
}
uint32_t resetGetCount(void)
{
	return reset_count;
}

