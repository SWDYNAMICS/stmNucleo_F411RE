#include "ap.h"

void apInit(void) {

}

void apMain(void) {
	while (1) {
		ledOn(_DEF_LED1);
		delay(500);
		ledOff(_DEF_LED1);
		delay(500);

		ledToggle(_DEF_LED1);
		delay(20);
		ledToggle(_DEF_LED1);
		delay(20);
		ledToggle(_DEF_LED1);
		delay(20);
	}
}
