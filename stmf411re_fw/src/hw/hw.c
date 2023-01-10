/*
 * hw.c
 *
 *  Created on: 2022. 11. 16.
 *      Author: USER
 */

#include "hw.h"

void hwInit()
{
  bspInit();
  rtcInit();

  resetInit();
  ledInit();
  usbInit();
  uartInit();
  flashInit();
}
