/*
 * flash.c
 *
 *  Created on: 2023. 1. 5.
 *      Author: USER
 */
#include "flash.h"

#define FLASH_SECTOR_MAX 8

typedef struct
{
  uint32_t addr;
  uint32_t legnth;
}flash_tbl_t;

const flash_tbl_t flash_tbl[FLASH_SECTOR_MAX] =
{
  {0x08000000, 16384},
  {0x08004000, 16384},
  {0x08008000, 16384},
  {0x0800C000, 16384},
  {0x08010000, 65536},
  {0x08020000, 131072},
  {0x08040000, 131072},
  {0x08060000, 131072}
};

bool flashInit(void)
{

}
bool flashErase(uint32_t addr, uint32_t length)
{

}
bool flashWrite(uint32_t addr, uint8_t *p_data, uint32_t length)
{

}
bool flashRead(uint32_t addr, uint8_t *p_data, uint32_t length)
{

}
