/*
 * uart.c
 *
 *  Created on: 2022. 12. 13.
 *      Author: USER
 */
#include "uart.h"
#include "cdc.h"

UART_HandleTypeDef huart1;

static bool is_open[UART_MAX_CHANNEL];

bool uartInit(void)
{
	for(int i = 0; i < UART_MAX_CHANNEL; i++)
	{
		is_open[i] = false;
	}
	return false;
}

bool uartOpen(uint8_t ch, uint32_t baud)
{
	bool ret = false;

	switch(ch)
	{
		case _DEF_UART1:
			is_open[ch] = true;
			ret = true;
			break;

		case _DEF_UART2:
			huart1.Instance 					= USART1;
			huart1.Init.BaudRate 			= 115200;
			huart1.Init.WordLength		= UART_WORDLENGTH_8B;
			huart1.Init.StopBits 			= UART_STOPBITS_1;
			huart1.Init.Parity 				= UART_PARITY_NONE;
			huart1.Init.Mode 					= UART_MODE_TX_RX;
			huart1.Init.HwFlowCtl 		= UART_HWCONTROL_NONE;
			huart1.Init.OverSampling 	= UART_OVERSAMPLING_16;
			if (HAL_UART_Init(&huart1) != HAL_OK)
			{
				ret = false;
			}
			else
			{
				ret = true;
				is_open[ch] = true;
			}
			break;
	}

	return ret;
}
uint32_t uartAvailable(uint8_t ch)
{
	uint32_t ret = 0;

	switch(ch)
	{
		case _DEF_UART1: // 첫번째 채널 uart -> 1. cdc 추
			ret = cdcAvailable();
			break;

	}

	return ret;
}
uint8_t uartRead(uint8_t ch)
{
	uint8_t ret;

	switch(ch)
	{
		case _DEF_UART1:
			ret = cdcRead();
			break;
	}

	return ret;
}
uint32_t uartWrite(uint8_t ch, uint8_t *pData, uint32_t length)
{
	uint32_t ret;
	HAL_StatusTypeDef status;

	switch(ch)
		{
			case _DEF_UART1:
				ret = cdcWrite(pData, length);
				break;

			case _DEF_UART2:
				status = HAL_UART_Transmit(&huart1, pData, length, 100);
				if(status == HAL_OK)
				{
					ret = length;
				}
				break;
		}

	return ret;
}
/*
 * 복습할 것 가변인자...*/
uint32_t uartPrintf(uint8_t ch, char* fmt, ...)
{
	char buf[256]; // string 처리를 위한 버퍼
	va_list args;
	int len;
	uint32_t ret;


	va_start(args, fmt); 									// 가변인자 처리 시작
	len = vsnprintf(buf, 256, fmt, args); //-> 버퍼에 해당 내용을 write

	ret = uartWrite(ch, (uint8_t *)buf, len);

	va_end(args);

	return ret;
}
uint32_t uartGetBaud(uint8_t ch)
{
	//bridge mode make, real uart need to know baudrate
	uint32_t ret = 0;
	switch(ch)
	{
		case _DEF_UART1:
			return cdcGetBaud();
			break;
	}
	return ret;
}







void HAL_UART_MspInit(UART_HandleTypeDef* uartHandle)
{

  GPIO_InitTypeDef GPIO_InitStruct = {0};
  if(uartHandle->Instance==USART1)
  {
  /* USER CODE BEGIN USART1_MspInit 0 */

  /* USER CODE END USART1_MspInit 0 */
    /* USART1 clock enable */
    __HAL_RCC_USART1_CLK_ENABLE();

    __HAL_RCC_GPIOA_CLK_ENABLE();
    /**USART1 GPIO Configuration
    PA9     ------> USART1_TX
    PA10     ------> USART1_RX
    */
    GPIO_InitStruct.Pin = GPIO_PIN_9|GPIO_PIN_10;
    GPIO_InitStruct.Mode = GPIO_MODE_AF_PP;
    GPIO_InitStruct.Pull = GPIO_NOPULL;
    GPIO_InitStruct.Speed = GPIO_SPEED_FREQ_VERY_HIGH;
    GPIO_InitStruct.Alternate = GPIO_AF7_USART1;
    HAL_GPIO_Init(GPIOA, &GPIO_InitStruct);

    /* USART1 interrupt Init */
    HAL_NVIC_SetPriority(USART1_IRQn, 0, 0);
    HAL_NVIC_EnableIRQ(USART1_IRQn);
  /* USER CODE BEGIN USART1_MspInit 1 */

  /* USER CODE END USART1_MspInit 1 */
  }
}

void HAL_UART_MspDeInit(UART_HandleTypeDef* uartHandle)
{

  if(uartHandle->Instance==USART1)
  {
  /* USER CODE BEGIN USART1_MspDeInit 0 */

  /* USER CODE END USART1_MspDeInit 0 */
    /* Peripheral clock disable */
    __HAL_RCC_USART1_CLK_DISABLE();

    /**USART1 GPIO Configuration
    PA9     ------> USART1_TX
    PA10     ------> USART1_RX
    */
    HAL_GPIO_DeInit(GPIOA, GPIO_PIN_9|GPIO_PIN_10);

    /* USART1 interrupt Deinit */
    HAL_NVIC_DisableIRQ(USART1_IRQn);
  /* USER CODE BEGIN USART1_MspDeInit 1 */

  /* USER CODE END USART1_MspDeInit 1 */
  }
}

/**
 * warning 은 최대한 없도록 FW를 설계할 것.
 * */





