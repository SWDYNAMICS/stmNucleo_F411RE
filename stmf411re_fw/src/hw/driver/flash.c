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
  uint32_t length;
}flash_tbl_t;

static bool flashInSector(uint16_t sector_num, uint32_t addr, uint32_t length);

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
  return true;
}
bool flashErase(uint32_t addr, uint32_t length)
{
  bool ret = false;
  HAL_StatusTypeDef status;
  FLASH_EraseInitTypeDef init;
  uint32_t sector_error;

  status = HAL_FLASHEx_Erase(&init, &sector_error);
  //YOUTUBE 31:58 END POINT

  return ret;
}
bool flashWrite(uint32_t addr, uint8_t *p_data, uint32_t length)
{

}
bool flashRead(uint32_t addr, uint8_t *p_data, uint32_t length)
{

}
bool flashInSector(uint16_t sector_num, uint32_t addr, uint32_t length)
{
  bool ret = false;

  uint32_t sector_start;
  uint32_t sector_end;
  uint32_t flash_start;
  uint32_t flash_end;

  sector_start = flash_tbl[sector_num].addr;
  sector_end   = flash_tbl[sector_num].addr + flash_tbl[sector_num].length - 1;
  flash_start  = addr;
  flash_end    = addr + length - 1;

  if(sector_start >= flash_start && sector_start <= flash_end)
  {
    ret = true;
  }
  if(sector_end >= flash_start && sector_end <= flash_end)
  {
    ret = true;
  }
  if(flash_start >= sector_start && flash_start <= sector_end)
  {
    ret = true;
  }
  if(flash_end >= sector_start && flash_end <= sector_end)
  {
    ret = true;
  }
  return ret;
}







