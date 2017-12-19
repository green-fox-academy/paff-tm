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
#include "define.h"
#include <string.h>

/** @addtogroup STM32F7xx_HAL_Examples
 * @{
 */

/** @addtogroup Templates
 * @{
 */

/* Private typedef -----------------------------------------------------------*/
/* Private define ------------------------------------------------------------*/
#define	D3				D3_PORT, D3_PIN, GPIO_AF2_TIM3	//PRM signal input from ventillator
#define	D10				D10_PORT, D10_PIN, GPIO_AF1_TIM1	//Vent

#define	VENT			D10
#define	BUTTON_1		D7
#define	BUTTON_1_PIN	D7_PIN
#define	BUTTON_2		D5
#define	BUTTON_2_PIN	D5_PIN
#define	VENT_RPM_IN		D3

#define TIM1_PERIOD		1000
#define TIM3_PERIOD		3000

#define PWM_MIN			0		//30
#define	PWM_MAX			100
#define RPM_MIN			0		//4000
#define	RPM_MAX			9000
#define	RPM_CNT_TH		75
#define RPM_REQ_INIT	RPM_MIN
#define BUTT_DIFF		250

#define I2C_SDA				D14
#define I2C_SCLK			D15
#define TC74_DEV_ADDRESS	0b10010000

#define P				0.005	//0.014


/* Private macro -------------------------------------------------------------*/
/* Private variables ---------------------------------------------------------*/
UART_HandleTypeDef uart_handle;
GPIO_InitTypeDef gpio_inittypedef;
TIM_HandleTypeDef TimHandle;
TIM_OC_InitTypeDef sConfig;
TIM_IC_InitTypeDef icConfig;
I2C_HandleTypeDef I2C_Handle;

unsigned int PWM_percent = 50;

volatile uint32_t tick_before = 0;			// for pushbutton frequency

volatile uint32_t RPM_IC_value_before = 0;
volatile unsigned int  RPM_IC_valid = 1;
volatile uint32_t RPM = 0;					//actual RPM of ventillator
double set_PWM = 0;							//set PWM % value by the control
uint32_t required_RPM = RPM_REQ_INIT;		//required RPM by user;
int8_t temp = 0;							//actual temperature


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
void GPIO_I2C_Init(GPIO_TypeDef  *GPIOx, uint16_t GPIO_PIN_x);
void I2C_Init();
int getTempData(int8_t *temp);
void EXTI0_IRQHandler();
void EXTI3_IRQHandler();
void TIM3_IRQHandler();
void HAL_TIM_IC_CaptureCallback(TIM_HandleTypeDef *htim);
void HAL_GPIO_EXTI_Callback(uint16_t GPIO_Pin);
void Set_TIM1_PWM(double percent);
void P_Control(uint32_t required_RPM);


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

	__HAL_RCC_GPIOB_CLK_ENABLE();
	GPIO_I2C_Init(D14);
	GPIO_I2C_Init(D15);

	__HAL_RCC_I2C1_CLK_ENABLE();
	I2C_Init();

  	__HAL_RCC_GPIOI_CLK_ENABLE();
	Init_PIN_PB(BUTTON_1);
	HAL_NVIC_SetPriority(EXTI3_IRQn, 0x0E, 0x00);
	HAL_NVIC_EnableIRQ(EXTI3_IRQn);

	Init_PIN_PB(BUTTON_2);
	HAL_NVIC_SetPriority(EXTI0_IRQn, 0x0E, 0x00);
	HAL_NVIC_EnableIRQ(EXTI0_IRQn);

	__HAL_RCC_GPIOA_CLK_ENABLE();
  	Init_PIN_Vent(VENT);

	//__HAL_RCC_GPIOB_CLK_ENABLE();
	Init_PIN_RPM_in(VENT_RPM_IN);
	HAL_NVIC_SetPriority(TIM3_IRQn, 0x0D, 0x00);
	HAL_NVIC_EnableIRQ(TIM3_IRQn);

	printf("\n-----------------WELCOME-----------------\r\n");
	printf("*********in STATIC control loop WS*********\r\n\n");

	Set_TIM1_PWM(PWM_percent);

	printf("required RPM, actual RPM, control PWM, temp\n");
	int temp1 = 0;
	int temp2 = 10;
	int temp3 = 20;
	int temp4 = 30;

	while (1)
	{
		if (getTempData(&temp) != 0) {
			//printf("temperature sensor communication error\n");
		}
		/* testing part start */
		//printf("%lu; %lu; %i; %i\n", required_RPM, RPM, (int)set_PWM, temp);

		temp1++;
		temp2++;
		temp3 += 2;
		temp4 -= 1;
		if (temp1 == 50)
			temp1 = 0;
		if (temp2 == 100)
			temp2 = 10;
		if (temp3 > 50)
			temp3 = 20;
		if (temp4 == 1)
			temp4 = 30;

		printf("%i; %i; %i; %i\n", temp1, temp2, temp3, temp4);
		/*testing part end*/

		P_Control(required_RPM);
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
  	TimHandle.Init.Prescaler         = 6750 - 1;			//6750
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
  	TimHandle.Init.Period            = TIM3_PERIOD - 1;	//3000
  	TimHandle.Init.Prescaler         = 45000 - 1;		//45000
  	TimHandle.Init.ClockDivision     = TIM_CLOCKDIVISION_DIV1;
  	TimHandle.Init.CounterMode       = TIM_COUNTERMODE_UP;
  	HAL_TIM_IC_Init(&TimHandle);

  	icConfig.ICFilter 				= 0;
  	icConfig.ICPolarity 			= TIM_ICPOLARITY_RISING;
  	icConfig.ICPrescaler 			= TIM_ICPSC_DIV2;
  	icConfig.ICSelection			= TIM_ICSELECTION_DIRECTTI;
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

void GPIO_I2C_Init(GPIO_TypeDef  *GPIOx, uint16_t GPIO_PIN_x)
{
	gpio_inittypedef.Alternate	= GPIO_AF4_I2C1;
	gpio_inittypedef.Mode		= GPIO_MODE_AF_OD;
	gpio_inittypedef.Pin			= GPIO_PIN_x;
	gpio_inittypedef.Pull		= GPIO_PULLUP;
	gpio_inittypedef.Speed		= GPIO_SPEED_HIGH;
	HAL_GPIO_Init(GPIOx, &gpio_inittypedef);
}

void I2C_Init()
{
	I2C_Handle.Instance				= I2C1;
	I2C_Handle.Init.Timing          = 0x40912732;
	I2C_Handle.Init.AddressingMode  = I2C_ADDRESSINGMODE_7BIT;
	HAL_I2C_Init(&I2C_Handle);
}

int getTempData(int8_t *temp)
{
	uint8_t RxData = 0;
	uint8_t TxData = 0x0;

	if (HAL_I2C_Master_Transmit(&I2C_Handle, (uint16_t)TC74_DEV_ADDRESS, &TxData, 1, 10000) != HAL_OK) {
		return -1;
	}
	if (HAL_I2C_Master_Receive(&I2C_Handle, (uint16_t)TC74_DEV_ADDRESS, &RxData, 1, 10000) != HAL_OK) {
		return -1;
	}

	*temp = RxData;
	return 0;
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
	if ((HAL_GetTick() - tick_before) > 150) {
		if ((GPIO_Pin == BUTTON_1_PIN) && (required_RPM <= RPM_MAX - BUTT_DIFF)) {
			required_RPM += BUTT_DIFF;
		} else if ((GPIO_Pin == BUTTON_2_PIN) && (required_RPM >= RPM_MIN + BUTT_DIFF)) {
			required_RPM -= BUTT_DIFF;
		}
		//Set_TIM1_PWM(PWM_percent);
		tick_before = HAL_GetTick();
		//printf("Required RPM: %u\n", required_RPM);
	}
}

void TIM3_IRQHandler()
{
	HAL_TIM_IRQHandler(&TimHandle);
}

void HAL_TIM_IC_CaptureCallback(TIM_HandleTypeDef *htim)
{
	uint32_t RPM_IC_capturedValue;
	uint32_t RPM_IC_elapsedValue;

	if (TIM1->CNT > RPM_CNT_TH && TIM1->CNT < TIM1->CCR1) {
		RPM_IC_capturedValue = HAL_TIM_ReadCapturedValue(htim, TIM_CHANNEL_1);
		if (RPM_IC_valid == 0) {
			RPM_IC_valid = 1;
		} else {
			if (RPM_IC_capturedValue > RPM_IC_value_before)
				RPM_IC_elapsedValue = RPM_IC_capturedValue - RPM_IC_value_before;
			else
				RPM_IC_elapsedValue = (TIM3_PERIOD - RPM_IC_value_before) + RPM_IC_capturedValue;
			//printf("Elapsed value: %lu\n", RPM_IC_capturedValue - RPM_IC_value_before);

			RPM = (TIM3_PERIOD / (double)RPM_IC_elapsedValue) * 60;
		}
		RPM_IC_value_before = RPM_IC_capturedValue;

	} else {
		RPM_IC_valid = 0;
	}
}

void Set_TIM1_PWM(double percent)
{
	if (percent >= 0 && percent <= 100) {
		TIM1->CCR1 = TIM1_PERIOD * (uint32_t)percent / 100;
	}
}

void P_Control(uint32_t required_RPM)
{
	int err = required_RPM - RPM;
	int ctrler_out = P * err;		//percent of PWM
	int temp_set_PWM = set_PWM;

	temp_set_PWM = set_PWM + ctrler_out;

	if (temp_set_PWM < PWM_MIN) {
		set_PWM = PWM_MIN;
	} else if (temp_set_PWM > PWM_MAX) {
		set_PWM = PWM_MAX;
	} else {
		set_PWM += ctrler_out;
	}

	Set_TIM1_PWM(set_PWM);
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
