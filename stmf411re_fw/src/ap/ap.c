

#include "ap.h"




void apInit(void)
{

}

void apMain(void)
{
	uint32_t pre_time;
	uint32_t pre_baud;

	pre_baud = uartGetBaud(_DEF_UART1);
	pre_time = millis();


	while (1)
	{
		if(millis() - pre_time >= 500)
		{
			pre_time = millis();
			ledToggle(_DEF_LED1);
		}

		if(uartAvailable(_DEF_UART1) > 0 )
		{
			uint8_t rx_data;

			rx_data = uartRead(_DEF_UART1);

			uartPrint(_DEF_UART1, "RX_DATA = %c , 0x%x\n", rx_data, rx_data);
		}
		if(pre_baud != uartGetBaud(_DEF_UART1))
		{
			pre_baud = uartGetBaud(_DEF_UART1);
			uartPrint(_DEF_UART1, "Changed buad rate: %d \n", uartGetBaud(_DEF_UART1));
		}
	}
}
