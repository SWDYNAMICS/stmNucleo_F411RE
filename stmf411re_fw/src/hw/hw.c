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
  cliInit();

  rtcInit();
  resetInit();
  ledInit();
  usbInit();
  uartInit();
  flashInit();

}
