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

/** @addtogroup STM32F7xx_HAL_Examples
 * @{
 */

/** @addtogroup Templates
 * @{
 */

/* Private typedef -----------------------------------------------------------*/
/* Private define ------------------------------------------------------------*/
#define A4_PIN			GPIO_PIN_7
#define A5_PIN			GPIO_PIN_6	//PRM in
#define D5_PIN			GPIO_PIN_0	//Button 2
#define D7_PIN			GPIO_PIN_3	//Button 1

#define A0 				GPIOA, GPIO_PIN_0
#define A1 				GPIOF, GPIO_PIN_10
#define A2 				GPIOF, GPIO_PIN_9
#define A3 				GPIOF, GPIO_PIN_8
#define A4 				GPIOF, A4_PIN
#define D11 			GPIOB, GPIO_PIN_11
#define	D9				GPIOA, GPIO_PIN_15//, GPIO_AF1_TIM2
#define A5 				GPIOF, A5_PIN

#define	D3				GPIOB, GPIO_PIN_4, GPIO_AF2_TIM3	//Vent RPM in
#define	D10				GPIOA, GPIO_PIN_8, GPIO_AF1_TIM1	//Vent
#define	D5				GPIOI, D5_PIN	//Button 2
#define	D7				GPIOI, D7_PIN	//Button 1


#define		VENT			D10
#define		BUTTON_1		D7
#define		BUTTON_1_PIN	D7_PIN
#define		BUTTON_2		D5
#define		BUTTON_2_PIN	D5_PIN
#define		VENT_RPM_IN		D3

#define 	TIM1_PERIOD		1000


/* Private macro -------------------------------------------------------------*/
/* Private variables ---------------------------------------------------------*/

UART_HandleTypeDef uart_handle;
GPIO_InitTypeDef gpio_inittypedef;
TIM_OC_InitTypeDef sConfig;
TIM_IC_InitTypeDef icConfig;
unsigned int PWM_percent = 50;

uint32_t tick_before = 0;
uint32_t RPM_time_before = 0;
uint32_t RPM_time_now = 0;
uint32_t RPM = 0;

TIM_HandleTypeDef TimHandle;


/* Private function prototypes -----------------------------------------------*/

#ifdef __GNUC__
/* With GCC/RAISONANCE, small printf (option LD Linker->Libraries->Small printf
 set to 'Yes') calls __io_putchar() */
#define PUTCHAR_PROTOTYPE int __io_putchar(int ch)
#else
#define PUTCHAR_PROTOTYPE int fputc(int ch, FILE *f)
#endif /* __GNUC__ */

static void SystemClock_Config(void);
static void Error_Handler(void);
static void MPU_Config(void);
static void CPU_CACHE_Enable(void);
void Init_UART();
void Init_TIM1();
void Init_TIM3();
void Init_PIN_Vent(GPIO_TypeDef  *_GPIOx, uint32_t _GPIO_Pin_x, uint32_t _GPIO_AF);
void Init_PIN_PB(GPIO_TypeDef  *_GPIOx, uint32_t _GPIO_Pin_x);
void Init_PIN_RPM_in(GPIO_TypeDef  *_GPIOx, uint32_t _GPIO_PIN_x, uint32_t _GPIO_AF);
void EXTI0_IRQHandler();
void EXTI3_IRQHandler();
void TIM3_IRQHandler();
void HAL_TIM_IC_CaptureCallback(TIM_HandleTypeDef *htim);
void HAL_GPIO_EXTI_Callback(uint16_t GPIO_Pin);
void Set_TIM1_PWM(uint32_t percent);


/* Private functions ---------------------------------------------------------*/

/**
 * @brief  Main program
 * @param  None
 * @retval None
 */
int main(void) {
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

	/* Add your application code here
	 */
	tick_before = HAL_GetTick();

	Init_UART();
	Init_TIM1();
	Init_TIM3();

  	__HAL_RCC_GPIOI_CLK_ENABLE();
	Init_PIN_PB(BUTTON_1);
	HAL_NVIC_SetPriority(EXTI3_IRQn, 0x0E, 0x00);
	HAL_NVIC_EnableIRQ(EXTI3_IRQn);

	Init_PIN_PB(BUTTON_2);
	HAL_NVIC_SetPriority(EXTI0_IRQn, 0x0E, 0x00);
	HAL_NVIC_EnableIRQ(EXTI0_IRQn);

	__HAL_RCC_GPIOA_CLK_ENABLE();
  	Init_PIN_Vent(VENT);

	__HAL_RCC_GPIOB_CLK_ENABLE();
	Init_PIN_RPM_in(VENT_RPM_IN);
	HAL_NVIC_SetPriority(TIM3_IRQn, 0x0D, 0x00);
	HAL_NVIC_EnableIRQ(TIM3_IRQn);

	printf("\n-----------------WELCOME-----------------\r\n");
	printf("*********in STATIC control loop WS*********\r\n\n");

	Set_TIM1_PWM(PWM_percent);

	while (1)
	{
		printf("RPM: %u\n", RPM);
		HAL_Delay(500);
	}

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

void Init_UART()
{
	uart_handle.Init.BaudRate = 115200;
	uart_handle.Init.WordLength = UART_WORDLENGTH_8B;
	uart_handle.Init.StopBits = UART_STOPBITS_1;
	uart_handle.Init.Parity = UART_PARITY_NONE;
	uart_handle.Init.HwFlowCtl = UART_HWCONTROL_NONE;
	uart_handle.Init.Mode = UART_MODE_TX_RX;
	BSP_COM_Init(COM1, &uart_handle);
}

void Init_TIM1()
{
	__HAL_RCC_TIM1_CLK_ENABLE();
  	TimHandle.Instance               = TIM1;
  	TimHandle.Init.Period            = TIM1_PERIOD - 1;		//8000
  	TimHandle.Init.Prescaler         = 6750;			//6750
  	TimHandle.Init.ClockDivision     = TIM_CLOCKDIVISION_DIV1;
  	TimHandle.Init.CounterMode       = TIM_COUNTERMODE_UP;
  	HAL_TIM_PWM_Init(&TimHandle);

  	sConfig.OCMode       = TIM_OCMODE_PWM1;
  	sConfig.Pulse		 = 0;
  	HAL_TIM_PWM_ConfigChannel(&TimHandle, &sConfig, TIM_CHANNEL_1);
  	HAL_TIM_PWM_Start(&TimHandle, TIM_CHANNEL_1);
}

void Init_TIM3()
{
	__HAL_RCC_TIM3_CLK_ENABLE();
  	TimHandle.Instance               = TIM3;
  	TimHandle.Init.Period            = 3000 - 1;	//3000
  	TimHandle.Init.Prescaler         = 45000;		//45000
  	TimHandle.Init.ClockDivision     = TIM_CLOCKDIVISION_DIV1;
  	TimHandle.Init.CounterMode       = TIM_COUNTERMODE_UP;
  	HAL_TIM_IC_Init(&TimHandle);

  	icConfig.ICFilter 				= 1;
  	icConfig.ICPolarity 			= TIM_ICPOLARITY_RISING;
  	icConfig.ICPrescaler 			= TIM_ICPSC_DIV1;
  	HAL_TIM_IC_ConfigChannel(&TimHandle, &icConfig, TIM_CHANNEL_1);
  	HAL_TIM_IC_Start_IT(&TimHandle, TIM_CHANNEL_1);
}

void Init_PIN_Vent(GPIO_TypeDef  *_GPIOx, uint32_t _GPIO_PIN_x, uint32_t _GPIO_AF)
{
	gpio_inittypedef.Alternate =	_GPIO_AF;
	gpio_inittypedef.Mode = 		GPIO_MODE_AF_PP;
	gpio_inittypedef.Pin = 			_GPIO_PIN_x;
	gpio_inittypedef.Pull = 		GPIO_NOPULL;
	gpio_inittypedef.Speed = 		GPIO_SPEED_HIGH;
	HAL_GPIO_Init(_GPIOx, &gpio_inittypedef);
}

void Init_PIN_PB(GPIO_TypeDef  *_GPIOx, uint32_t _GPIO_PIN_x)
{
	gpio_inittypedef.Mode = 		GPIO_MODE_IT_RISING;
	gpio_inittypedef.Pin = 			_GPIO_PIN_x;
	gpio_inittypedef.Pull = 		GPIO_PULLDOWN;
	gpio_inittypedef.Speed = 		GPIO_SPEED_HIGH;
	HAL_GPIO_Init(_GPIOx, &gpio_inittypedef);
}

void Init_PIN_RPM_in(GPIO_TypeDef  *_GPIOx, uint32_t _GPIO_PIN_x, uint32_t _GPIO_AF)
{
	gpio_inittypedef.Alternate =	_GPIO_AF;
	gpio_inittypedef.Mode = 		GPIO_MODE_AF_PP;
	gpio_inittypedef.Pin = 			_GPIO_PIN_x;
	gpio_inittypedef.Pull = 		GPIO_NOPULL;
	gpio_inittypedef.Speed = 		GPIO_SPEED_HIGH;
	HAL_GPIO_Init(_GPIOx, &gpio_inittypedef);
}

void EXTI0_IRQHandler()
{
	HAL_GPIO_EXTI_IRQHandler(BUTTON_2_PIN);
}

void EXTI3_IRQHandler()
{
	HAL_GPIO_EXTI_IRQHandler(BUTTON_1_PIN);
}

void HAL_GPIO_EXTI_Callback(uint16_t GPIO_Pin)
{
	if ((HAL_GetTick() - tick_before) > 250) {
		unsigned int dif = 5;
		if ((GPIO_Pin == BUTTON_1_PIN) && (PWM_percent <= 100 - dif)) {
			PWM_percent += dif;
		} else if ((GPIO_Pin == BUTTON_2_PIN) && (PWM_percent >= dif)) {
			PWM_percent -= dif;
		}
		Set_TIM1_PWM(PWM_percent);
		tick_before = HAL_GetTick();
		printf("PWM percent: %u\n", PWM_percent);
	}
}

void TIM3_IRQHandler()
{
	HAL_TIM_IRQHandler(&TimHandle);
}

void HAL_TIM_IC_CaptureCallback(TIM_HandleTypeDef *htim)
{
	printf("HAL_TIM_IC_CaptureCallback\n");
}

void Set_TIM1_PWM(uint32_t percent)
{
	if (percent >= 0 && percent <= 100) {
		TIM1->CCR1 = TIM1_PERIOD * percent / 100;
	}
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
