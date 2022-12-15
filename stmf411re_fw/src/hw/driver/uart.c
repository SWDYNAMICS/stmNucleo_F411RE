/*
 * uart.c
 *
 *  Created on: 2022. 12. 13.
 *      Author: USER
 */
#include "uart.h"
#include "cdc.h"

static bool is_open[UART_MAX_CHANNEL];

bool uartInit(void)
{
	for(int i = 0; i < UART_MAX_CHANNEL; i++)
	{
		is_open[i] = false;
	}
	return false;
}

bool uartOpen(uint8_t ch, uint32_t baud)
{
	bool ret = false;

	switch(ch)
	{
		case _DEF_UART1:
			is_open[ch] = true;
			ret = true;
			break;
	}

	return ret;
}
uint32_t uartAvailable(uint8_t ch)
{
	uint32_t ret = 0;

	switch(ch)
	{
		case _DEF_UART1: // 첫번째 채널 uart -> 1. cdc 추
			ret = cdcAvailable();
			break;
	}

	return ret;
}
uint8_t uartRead(uint8_t ch)
{
	uint8_t ret;

	switch(ch)
	{
		case _DEF_UART1:
			ret = cdcRead();
			break;
	}

	return ret;
}
uint32_t uartWrite(uint8_t ch, uint8_t *pData, uint32_t length)
{
	uint32_t ret;

	switch(ch)
		{
			case _DEF_UART1:
				ret = cdcWrite(pData, length);
				break;
		}

	return ret;
}
/*
 * 복습할 것 가변인자...*/
uint32_t uartPrint(uint8_t ch, char* fmt, ...)
{
	char buf[256]; // string 처리를 위한 버퍼
	va_list args;
	int len;
	uint32_t ret;


	va_start(args, fmt); 									// 가변인자 처리 시작
	len = vsnprintf(buf, 256, fmt, args); //-> 버퍼에 해당 내용을 write

	ret = uartWrite(ch, (uint8_t *)buf, len);

	va_end(args);

	return ret;
}
uint32_t uartGetBaud(uint8_t ch)
{
	//bridge mode make, real uart need to know baudrate
	uint32_t ret = 0;
	switch(ch)
	{
		case _DEF_UART1:
			return cdcGetBaud();
			break;
	}
	return ret;
}



/**
 * warning 은 최대한 없도록 FW를 설계할 것.
 * */





