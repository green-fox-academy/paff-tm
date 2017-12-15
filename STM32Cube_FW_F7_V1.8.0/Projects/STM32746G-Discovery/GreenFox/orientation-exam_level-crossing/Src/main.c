/**
 ******************************************************************************
 * @file    Templates/Src/main.c
 * @author  MCD Application Team
 * @version V1.0.3
 * @date    22-April-2016
 * @brief   STM32F7xx HAL API Template project
 ******************************************************************************
 * @attention
 *
 * <h2><center>&copy; COPYRIGHT(c) 2016 STMicroelectronics</center></h2>
 *
 * Redistribution and use in source and binary forms, with or without modification,
 * are permitted provided that the following conditions are met:
 *   1. Redistributions of source code must retain the above copyright notice,
 *      this list of conditions and the following disclaimer.
 *   2. Redistributions in binary form must reproduce the above copyright notice,
 *      this list of conditions and the following disclaimer in the documentation
 *      and/or other materials provided with the distribution.
 *   3. Neither the name of STMicroelectronics nor the names of its contributors
 *      may be used to endorse or promote products derived from this software
 *      without specific prior written permission.
 *
 * THIS SOFTWARE IS PROVIDED BY THE COPYRIGHT HOLDERS AND CONTRIBUTORS "AS IS"
 * AND ANY EXPRESS OR IMPLIED WARRANTIES, INCLUDING, BUT NOT LIMITED TO, THE
 * IMPLIED WARRANTIES OF MERCHANTABILITY AND FITNESS FOR A PARTICULAR PURPOSE ARE
 * DISCLAIMED. IN NO EVENT SHALL THE COPYRIGHT HOLDER OR CONTRIBUTORS BE LIABLE
 * FOR ANY DIRECT, INDIRECT, INCIDENTAL, SPECIAL, EXEMPLARY, OR CONSEQUENTIAL
 * DAMAGES (INCLUDING, BUT NOT LIMITED TO, PROCUREMENT OF SUBSTITUTE GOODS OR
 * SERVICES; LOSS OF USE, DATA, OR PROFITS; OR BUSINESS INTERRUPTION) HOWEVER
 * CAUSED AND ON ANY THEORY OF LIABILITY, WHETHER IN CONTRACT, STRICT LIABILITY,
 * OR TORT (INCLUDING NEGLIGENCE OR OTHERWISE) ARISING IN ANY WAY OUT OF THE USE
 * OF THIS SOFTWARE, EVEN IF ADVISED OF THE POSSIBILITY OF SUCH DAMAGE.
 *
 ******************************************************************************
 */

/* Includes ------------------------------------------------------------------*/
#include "main.h"
#include <string.h>
#include "define.h"

/** @addtogroup STM32F7xx_HAL_Examples
 * @{
 */

/** @addtogroup Templates
 * @{
 */

/* Private typedef -----------------------------------------------------------*/
typedef enum {
	STATE_OPEN,
	STATE_SECURING,
	STATE_SECURED,
	STATE_OPENING
}StateType;

/* Private define ------------------------------------------------------------*/
#define TIM3_OPEN_COUNTER 		8000 - 1	// 0,5 Hz 	50%
#define TIM3_SECURING_COUNTER 	4000 - 1	// 1 hz		50%
#define TIM3_OPENING_COUNTER	TIM3_SECURING_COUNTER

#define TIM2_SECURING_COUNTER 	40000 - 1	// 5 sec
#define TIM2_OPENING_COUNTER 	48000 - 1	// 6 sec

/* Private macro -------------------------------------------------------------*/
/* Private variables ---------------------------------------------------------*/
UART_HandleTypeDef uart_handle;
TIM_HandleTypeDef TIM1_Handle;
TIM_HandleTypeDef TIM2_Handle;
TIM_HandleTypeDef TIM3_Handle;

TIM_OC_InitTypeDef sConfig;

StateType state = STATE_OPEN;
int led_status = 1;
int led_on = 1;

/* Private function prototypes -----------------------------------------------*/
#ifdef __GNUC__
/* With GCC/RAISONANCE, small printf (option LD Linker->Libraries->Small printf
 set to 'Yes') calls __io_putchar() */
#define PUTCHAR_PROTOTYPE int __io_putchar(int ch)
#else
#define PUTCHAR_PROTOTYPE int fputc(int ch, FILE *f)
#endif /* __GNUC__ */

void UART_Init();

void BarrierClose();
void BarrierOpen();

void TIM3_Config();					//LED blinking
void TIM3_IRQHandler();
void HAL_TIM_PeriodElapsedCallback(TIM_HandleTypeDef *htim);

void TIM2_Config();					//time measure
void TIM2_IRQHandler();

void EXTI15_10_IRQHandler();		//BushButton
void HAL_GPIO_EXTI_Callback(uint16_t GPIO_Pin);

static void System_Init(void);
static void SystemClock_Config(void);
static void Error_Handler(void);
static void MPU_Config(void);
static void CPU_CACHE_Enable(void);

/* Private functions ---------------------------------------------------------*/

/**
 * @brief  Main program
 * @param  None
 * @retval None
 */
int main(void) {
	/* Add your application code here
	 */
	System_Init();

	UART_Init();
	//TIM1_Config();
	TIM2_Config();
	TIM3_Config();

	BSP_PB_Init(BUTTON_KEY, BUTTON_MODE_EXTI);
	HAL_NVIC_SetPriority(KEY_BUTTON_EXTI_IRQn, 0x0E, 0x00);
	HAL_NVIC_EnableIRQ(KEY_BUTTON_EXTI_IRQn);

	BSP_LED_Init(LED_GREEN);


	printf("\n----------------------WELCOME--------------------\r\n");
	printf("**********in STATIC level-crossing EXAM**********\r\n\n");

	printf("Open\n");

	while (1)
	{

	}

}

void UART_Init()
{
	uart_handle.Init.BaudRate 	= 115200;
	uart_handle.Init.WordLength = UART_WORDLENGTH_8B;
	uart_handle.Init.StopBits 	= UART_STOPBITS_1;
	uart_handle.Init.Parity		= UART_PARITY_NONE;
	uart_handle.Init.HwFlowCtl 	= UART_HWCONTROL_NONE;
	uart_handle.Init.Mode 		= UART_MODE_TX_RX;
	BSP_COM_Init(COM1, &uart_handle);
}


void BarrierClose()
{
	if (state == STATE_OPEN) {
		TIM2_Handle.Init.Period = TIM2_SECURING_COUNTER;
	  	HAL_TIM_Base_Init(&TIM2_Handle);
		HAL_TIM_Base_Start_IT(&TIM2_Handle);
	}
}

void BarrierOpen()
{
	if (state == STATE_SECURED) {
		TIM2_Handle.Init.Period = TIM2_OPENING_COUNTER;
	  	HAL_TIM_Base_Init(&TIM2_Handle);
		HAL_TIM_Base_Start_IT(&TIM2_Handle);
	}
}

void TIM3_Config()
{
	__HAL_RCC_TIM3_CLK_ENABLE();

	TIM3_Handle.Instance 			= TIM3;
	TIM3_Handle.Channel				= TIM_CHANNEL_1;
	TIM3_Handle.Init.CounterMode	= TIM_COUNTERMODE_UP;
	TIM3_Handle.Init.ClockDivision  = TIM_CLOCKDIVISION_DIV1;
	TIM3_Handle.Init.Period			= TIM3_OPEN_COUNTER;
	TIM3_Handle.Init.Prescaler		= 13500;
  	HAL_TIM_Base_Init(&TIM3_Handle);
  	HAL_TIM_Base_Start_IT(&TIM3_Handle);

  	/*
  	sConfig.OCMode       = TIM_OCMODE_ACTIVE;
  	sConfig.Pulse		 = 2000;
  	HAL_TIM_OC_ConfigChannel(&TIM3_Handle, &sConfig, TIM_CHANNEL_1);
  	HAL_TIM_OC_Start_IT(&TIM3_Handle, TIM_CHANNEL_1);
	*/

	HAL_NVIC_SetPriority(TIM3_IRQn, 0x0F, 0x0);
	HAL_NVIC_EnableIRQ(TIM3_IRQn);
}

void TIM3_IRQHandler()
{
	HAL_TIM_IRQHandler(&TIM3_Handle);
}

void HAL_TIM_PeriodElapsedCallback(TIM_HandleTypeDef *htim)
{
	if (htim->Instance == TIM3) {
		if (led_on == 1) {
			if (led_status == 1) {
				BSP_LED_Off(LED_GREEN);
				led_status = 0;
			} else {
				BSP_LED_On(LED_GREEN);
				led_status = 1;
			}
		} else {
			BSP_LED_Off(LED_GREEN);
		}

	} else if (htim->Instance == TIM2) {
		switch (state) {
		case STATE_SECURING:
			//HAL_TIM_Base_Stop_IT(&TIM3_Handle);
			led_on = 0;
			state = STATE_SECURED;
			printf("Secured\n");
			break;

		case STATE_SECURED:
			//HAL_TIM_Base_Start_IT(&TIM2_Handle);
			led_on = 1;
			TIM3_Handle.Init.Period =  TIM3_OPENING_COUNTER;
		  	HAL_TIM_Base_Init(&TIM3_Handle);
			HAL_TIM_Base_Start_IT(&TIM3_Handle);
			state = STATE_OPENING;
			printf("Opening\n");
			break;

		case STATE_OPENING:
			HAL_TIM_Base_Stop_IT(&TIM2_Handle);
			TIM3_Handle.Init.Period =  TIM3_OPEN_COUNTER;
		  	HAL_TIM_Base_Init(&TIM3_Handle);
			HAL_TIM_Base_Start_IT(&TIM3_Handle);
			state = STATE_OPEN;
			printf("Open\n");
			break;

		case STATE_OPEN:
			HAL_TIM_Base_Start_IT(&TIM2_Handle);
			TIM3_Handle.Init.Period = TIM3_SECURING_COUNTER;
		  	HAL_TIM_Base_Init(&TIM3_Handle);
			HAL_TIM_Base_Start_IT(&TIM3_Handle);
			state = STATE_SECURING;
			printf("Securing\n");
			break;
		}
	}
}

void TIM2_Config()
{
	__HAL_RCC_TIM2_CLK_ENABLE();

	TIM2_Handle.Instance 			= TIM2;
	TIM2_Handle.Channel				= TIM_CHANNEL_1;
	TIM2_Handle.Init.CounterMode	= TIM_COUNTERMODE_UP;
	TIM2_Handle.Init.ClockDivision  = TIM_CLOCKDIVISION_DIV1;
	TIM2_Handle.Init.Period			= 8000;
	TIM2_Handle.Init.Prescaler		= 13500;

	HAL_NVIC_SetPriority(TIM2_IRQn, 0x0F, 0x0);
	HAL_NVIC_EnableIRQ(TIM2_IRQn);
}

void TIM2_IRQHandler()
{
	HAL_TIM_IRQHandler(&TIM2_Handle);
}

void EXTI15_10_IRQHandler()
{
	HAL_GPIO_EXTI_IRQHandler(KEY_BUTTON_PIN);
}

void HAL_GPIO_EXTI_Callback(uint16_t GPIO_Pin)
{
	if (GPIO_Pin == KEY_BUTTON_PIN) {
		if (state == STATE_OPEN) {
			BarrierClose();
		} else if (state == STATE_SECURED) {
			BarrierOpen();
		}
	}
}


static void System_Init(void)
{
	/* This project template calls firstly two functions in order to configure MPU feature
	 and to enable the CPU Cache, respectively MPU_Config() and CPU_CACHE_Enable().
	 These functions are provided as template implementation that User may integrate
	 in his application, to enhance the performance in case of use of AXI interface
	 with several masters. */

	/* Configure the MPU attributes as Write Through */
	MPU_Config();

	/* Enable the CPU Cache */
	CPU_CACHE_Enable();

	/* STM32F7xx HAL library initialization:
	 - Configure the Flash ART accelerator on ITCM interface
	 - Configure the Systick to generate an interrupt each 1 msec
	 - Set NVIC Group Priority to 4
	 - Low Level Initialization
	 */
	HAL_Init();

	/* Configure the System clock to have a frequency of 216 MHz */
	SystemClock_Config();
}

/**
 * @brief  CPU L1-Cache enable.
 * @param  None
 * @retval None
 */
static void CPU_CACHE_Enable(void) {
	/* Enable I-Cache */
	SCB_EnableICache();

	/* Enable D-Cache */
	SCB_EnableDCache();
}

/**
 * @brief  Retargets the C library printf function to the USART.
 * @param  None
 * @retval None
 */
PUTCHAR_PROTOTYPE {
	/* Place your implementation of fputc here */
	/* e.g. write a character to the EVAL_COM1 and Loop until the end of transmission */
	HAL_UART_Transmit(&uart_handle, (uint8_t *) &ch, 1, 0xFFFF);

	return ch;
}

/**
 * @brief  System Clock Configuration
 *         The system Clock is configured as follow :
 *            System Clock source            = PLL (HSE)
 *            SYSCLK(Hz)                     = 216000000
 *            HCLK(Hz)                       = 216000000
 *            AHB Prescaler                  = 1
 *            APB1 Prescaler                 = 4
 *            APB2 Prescaler                 = 2
 *            HSE Frequency(Hz)              = 25000000
 *            PLL_M                          = 25
 *            PLL_N                          = 432
 *            PLL_P                          = 2
 *            PLL_Q                          = 9
 *            VDD(V)                         = 3.3
 *            Main regulator output voltage  = Scale1 mode
 *            Flash Latency(WS)              = 7
 * @param  None
 * @retval None
 */
static void SystemClock_Config(void) {
	RCC_ClkInitTypeDef RCC_ClkInitStruct;
	RCC_OscInitTypeDef RCC_OscInitStruct;

	/* Enable HSE Oscillator and activate PLL with HSE as source */
	RCC_OscInitStruct.OscillatorType = RCC_OSCILLATORTYPE_HSE;
	RCC_OscInitStruct.HSEState = RCC_HSE_ON;
	RCC_OscInitStruct.HSIState = RCC_HSI_OFF;
	RCC_OscInitStruct.PLL.PLLState = RCC_PLL_ON;
	RCC_OscInitStruct.PLL.PLLSource = RCC_PLLSOURCE_HSE;
	RCC_OscInitStruct.PLL.PLLM = 25;
	RCC_OscInitStruct.PLL.PLLN = 432;
	RCC_OscInitStruct.PLL.PLLP = RCC_PLLP_DIV2;
	RCC_OscInitStruct.PLL.PLLQ = 9;
	if (HAL_RCC_OscConfig(&RCC_OscInitStruct) != HAL_OK) {
		Error_Handler();
	}

	/* activate the OverDrive to reach the 216 Mhz Frequency */
	if (HAL_PWREx_EnableOverDrive() != HAL_OK) {
		Error_Handler();
	}

	/* Select PLL as system clock source and configure the HCLK, PCLK1 and PCLK2
	 clocks dividers */
	RCC_ClkInitStruct.ClockType = (RCC_CLOCKTYPE_SYSCLK | RCC_CLOCKTYPE_HCLK
			| RCC_CLOCKTYPE_PCLK1 | RCC_CLOCKTYPE_PCLK2);
	RCC_ClkInitStruct.SYSCLKSource = RCC_SYSCLKSOURCE_PLLCLK;
	RCC_ClkInitStruct.AHBCLKDivider = RCC_SYSCLK_DIV1;
	RCC_ClkInitStruct.APB1CLKDivider = RCC_HCLK_DIV4;
	RCC_ClkInitStruct.APB2CLKDivider = RCC_HCLK_DIV8;
	if (HAL_RCC_ClockConfig(&RCC_ClkInitStruct, FLASH_LATENCY_7) != HAL_OK) {
		Error_Handler();
	}
}

/**
 * @brief  This function is executed in case of error occurrence.
 * @param  None
 * @retval None
 */
static void Error_Handler(void) {
	/* User may add here some code to deal with this error */
	while (1) {
	}
}

/**
 * @brief  Configure the MPU attributes as Write Through for SRAM1/2.
 * @note   The Base Address is 0x20010000 since this memory interface is the AXI.
 *         The Region Size is 256KB, it is related to SRAM1 and SRAM2  memory size.
 * @param  None
 * @retval None
 */
static void MPU_Config(void) {
	MPU_Region_InitTypeDef MPU_InitStruct;

	/* Disable the MPU */
	HAL_MPU_Disable();

	/* Configure the MPU attributes as WT for SRAM */
	MPU_InitStruct.Enable = MPU_REGION_ENABLE;
	MPU_InitStruct.BaseAddress = 0x20010000;
	MPU_InitStruct.Size = MPU_REGION_SIZE_256KB;
	MPU_InitStruct.AccessPermission = MPU_REGION_FULL_ACCESS;
	MPU_InitStruct.IsBufferable = MPU_ACCESS_NOT_BUFFERABLE;
	MPU_InitStruct.IsCacheable = MPU_ACCESS_CACHEABLE;
	MPU_InitStruct.IsShareable = MPU_ACCESS_SHAREABLE;
	MPU_InitStruct.Number = MPU_REGION_NUMBER0;
	MPU_InitStruct.TypeExtField = MPU_TEX_LEVEL0;
	MPU_InitStruct.SubRegionDisable = 0x00;
	MPU_InitStruct.DisableExec = MPU_INSTRUCTION_ACCESS_ENABLE;

	HAL_MPU_ConfigRegion(&MPU_InitStruct);

	/* Enable the MPU */
	HAL_MPU_Enable(MPU_PRIVILEGED_DEFAULT);
}

#ifdef  USE_FULL_ASSERT

/**
 * @brief  Reports the name of the source file and the source line number
 *         where the assert_param error has occurred.
 * @param  file: pointer to the source file name
 * @param  line: assert_param error line source number
 * @retval None
 */
void assert_failed(uint8_t* file, uint32_t line)
{
	/* User can add his own implementation to report the file name and line number,
	 ex: printf("Wrong parameters value: file %s on line %d\r\n", file, line) */

	/* Infinite loop */
	while (1)
	{
	}
}
#endif

/**
 * @}
 */

/**
 * @}
 */

/************************ (C) COPYRIGHT STMicroelectronics *****END OF FILE****/
