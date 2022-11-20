/*
 * led.c
 *
 *  Created on: 2022. 11. 20.
 *      Author: 이승우
 */


#include "led.h"
#include "hw_def.h"

typedef struct
{
	GPIO_TypeDef * port;
	uint32_t pin;
	GPIO_PinState on_state;
	GPIO_PinState off_state;
}led_tbl_t;

led_tbl_t led_tbl[3]=//LED_MAX_CHANNEL
{
	{GPIOA, GPIO_PIN_5, GPIO_PIN_SET, GPIO_PIN_RESET}
};

bool ledInit(void)
{
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
