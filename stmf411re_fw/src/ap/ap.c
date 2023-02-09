

#include "ap.h"
#include "qbuffer.h"

static void threadLed(void const *argument);

void apInit(void)
{
	uartOpen(_DEF_UART1, 57600);
	uartOpen(_DEF_UART2, 57600);


	cliOpen(_DEF_UART1, 57600);
	osThreadDef(threadLed, threadLed, _HW_DEF_RTOS_THREAD_PRI_LED, 0, _HW_DEF_RTOS_THREAD_MEM_LED);
	if(osThreadCreate(osThread(threadLed),NULL) != NULL)
	{
	  logPrintf("threadLed \t\t:OK \r\n");
	}
	else
	{
	  logPrintf("threadLed \t\t:FAIL \r\n");
	}
}

void apMain(void)
{
	while (1)
	{
		cliMain();
		delay(1);
	}
}

static void threadLed(void const *argument)
{
  UNUSED(argument);
  while(1)
  {
    ledToggle(_DEF_LED1);
    delay(500);
  }
}







































