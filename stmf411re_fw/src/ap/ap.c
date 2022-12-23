

#include "ap.h"




void apInit(void)
{
	uartOpen(_DEF_UART1, 57600);
	uartOpen(_DEF_UART2, 115200);
}

void apMain(void)
{
	uint32_t pre_time;

	pre_time = millis();
	while (1)
	{
		if(millis() - pre_time >= 500)
		{
			pre_time = millis();
			ledToggle(_DEF_LED1);

			uartPrintf(_DEF_UART1, "Uart1 %d\n", millis());
		}
	}
}
