

#include "ap.h"
#include "qbuffer.h"



void apInit(void)
{
}

void apMain(void)
{
	uint32_t pre_time;

	pre_time = millis();
	while (1)
	{
		if(millis() - pre_time >= 100)
		{
			pre_time = millis();
			ledToggle(_DEF_LED1);
		}
	}
}














