/*
 * led.c
 *
 *  Created on: 2022. 11. 20.
 *      Author: 이승우
 */


#include "led.h"
//#include "hw_def.h"
#include "cli.h"


typedef struct
{
	GPIO_TypeDef * port;
	uint32_t pin;
	GPIO_PinState on_state;
	GPIO_PinState off_state;
}led_tbl_t;

led_tbl_t led_tbl[LED_MAX_CHANNEL]=//LED_MAX_CHANNEL
{
	{GPIOC, GPIO_PIN_13, GPIO_PIN_SET, GPIO_PIN_RESET}
};

#ifdef _USE_HW_CLI
typedef struct
{
  uint16_t   argc;
  char     **argv; /*2차원 배열이라고 보면됨*/

  /* input data type exchange */
  int32_t  (*getData)(uint8_t index);
  float    (*getFloat)(uint8_t index);
  char    *(*getStr)(uint8_t index);
  bool     (*isStr)(uint8_t index, char *p_str);
}cli_args_t;

static void cliLed(cli_args_t *args);
#endif

bool ledInit(void)
{
	bool ret = true;
	GPIO_InitTypeDef GPIO_InitStruct = {0};

	__HAL_RCC_GPIOA_CLK_ENABLE();

	GPIO_InitStruct.Mode = GPIO_MODE_OUTPUT_PP;
	GPIO_InitStruct.Pull = GPIO_NOPULL;
	GPIO_InitStruct.Speed = GPIO_SPEED_FREQ_LOW;

	for(int i = 0; i < LED_MAX_CHANNEL; i++)
	{
		ledOff(i);
		GPIO_InitStruct.Pin = led_tbl[i].pin;
		HAL_GPIO_Init(led_tbl[i].port, &GPIO_InitStruct);
	}
#ifdef _USE_HW_CLI
	cliAdd("led", cliLed);
#endif
	return ret;
}
void ledOn(uint8_t ch)
{
	HAL_GPIO_WritePin(led_tbl[ch].port, led_tbl[ch].pin, led_tbl[ch].on_state);
}
void ledOff(uint8_t ch)
{
	HAL_GPIO_WritePin(led_tbl[ch].port, led_tbl[ch].pin, led_tbl[ch].off_state);
}
void ledToggle(uint8_t ch)
{
	HAL_GPIO_TogglePin(led_tbl[ch].port, led_tbl[ch].pin);
}
#ifdef _USE_HW_CLI
static void cliLed(cli_args_t *args) /*reason why?? prototype is static but declare is not*/
{
  bool ret = false;
  if(args->argc == 3 && args->isStr(0, "toggle") == true)
  {
    uint8_t  led_ch;
    uint32_t toggle_time;
    uint32_t pre_time;

    led_ch      = (uint8_t)args->getData(1);
    toggle_time = (uint32_t)args->getData(2);

    if(led_ch > 0)
    {
      led_ch--;
    }

    pre_time = millis();
    while(cliKeepLoop())
    {
      if(millis() - pre_time > toggle_time)
      {
        pre_time = millis();
        ledToggle(led_ch);
      }
    }
  }
  if(ret != true)
  {
    cliPrintf("Led toggle ch[1~%d] time_ms \n", LED_MAX_CHANNEL);
  }
}

#endif









