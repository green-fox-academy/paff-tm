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

/** @addtogroup STM32F7xx_HAL_Examples
  * @{
  */

/** @addtogroup Templates
  * @{
  */

/* Private typedef -----------------------------------------------------------*/
typedef struct {
	  GPIO_TypeDef* port;
	  uint16_t		pin;
	  uint8_t		on;
	  uint8_t		duty_cycle;	// 0-100%
} Led_HandleTypef;

/* Private define ------------------------------------------------------------*/
#define LED_NUM		7
#define MIN_DUTY	1
#define MAX_DUTY	80

#define D0 			GPIOC, GPIO_PIN_7
#define D1 			GPIOC, GPIO_PIN_6
#define D2 			GPIOG, GPIO_PIN_6
#define D3 			GPIOB, GPIO_PIN_4
#define D4 			GPIOG, GPIO_PIN_7
#define D5 			GPIOI, GPIO_PIN_0
#define D6			GPIOH, GPIO_PIN_6

#define LED6		D6
#define LED5		D5
#define LED4		D4
#define LED3		D3
#define LED2		D2
#define LED1		D1
#define LED0		D0


/* Private macro -------------------------------------------------------------*/
/* Private variables ---------------------------------------------------------*/
TIM_HandleTypeDef TIM2_Handle;
UART_HandleTypeDef UartHandle;
Led_HandleTypef leds[LED_NUM] = {{LED0, 0, 0}, {LED1, 0, 0}, {LED2, 0, 0}, {LED3, 0, 0}, {LED4, 0, 0}, {LED5, 0, 0}, {LED6, 0, 0}};
uint32_t periodElapsed_Counter = 0;
uint32_t pwm_cnt = 0;

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

void My_Init();
void LED_Init(GPIO_TypeDef *_port, uint16_t _pin);
void InitLEDs(int8_t value, Led_HandleTypef *leds);
void ShowLEDs(Led_HandleTypef *leds);

void TIM2_Config();
void TIM2_IRQHandler();
void HAL_TIM_PeriodElapsedCallback(TIM_HandleTypeDef *htim);

void UART_Config(void);

/* Private functions ---------------------------------------------------------*/


/**
  * @brief  Main program
  * @param  None
  * @retval None
  */
int main(void)
{
  My_Init();

  /* Add your application code here     */

  printf("Welcome in the bicycle shift indicator project!\n\n");

  //HAL_GPIO_WritePin(LED0, GPIO_PIN_SET);
  InitLEDs(5, leds);
  ShowLEDs(leds);

  /* Infinite loop */
  while (1)
  {


  }
}

void My_Init()
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
	  UART_Config();
	  TIM2_Config();

	  __HAL_RCC_GPIOB_CLK_ENABLE();
	  __HAL_RCC_GPIOC_CLK_ENABLE();
	  __HAL_RCC_GPIOG_CLK_ENABLE();
	  __HAL_RCC_GPIOH_CLK_ENABLE();
	  __HAL_RCC_GPIOI_CLK_ENABLE();

	  for (unsigned int i = 0; i < LED_NUM; ++i) {
		  LED_Init(leds[i].port, leds[i].pin);
	  }
}

void LED_Init(GPIO_TypeDef *_port, uint16_t _pin)
{
	GPIO_InitTypeDef led;
	led.Pin = _pin;
	led.Mode = GPIO_MODE_OUTPUT_PP;
	led.Pull = GPIO_PULLDOWN;
	led.Speed = GPIO_SPEED_HIGH;

	HAL_GPIO_Init(_port, &led);
	HAL_GPIO_WritePin(_port, _pin, GPIO_PIN_RESET);
}

void InitLEDs(int8_t value, Led_HandleTypef *leds)
{
	for (unsigned int i = 0; i < value; ++i) {
		leds[i].duty_cycle = MIN_DUTY + i * ((float)(MAX_DUTY - MIN_DUTY) / (value - 1)) ;
		leds[i].on = 0;
		//test
		printf("%u, %u\n", i, leds[i].duty_cycle);
	}
}

void ShowLEDs(Led_HandleTypef *leds)
{
	HAL_TIM_Base_Start_IT(&TIM2_Handle);
	for (unsigned int i = 0; i < LED_NUM; ++i) {
		if (leds[i].duty_cycle > 0) {
			leds[i].on = 1;
			HAL_GPIO_WritePin(leds[i].port, leds[i].pin, GPIO_PIN_SET);
			HAL_Delay(100);
		}
	}
}

void ResetLEDs()
{
	for (unsigned int i = 0; i < LED_NUM; ++i) {
		HAL_GPIO_WritePin(leds[i].port, leds[i].pin, GPIO_PIN_RESET);
		leds[i].on = 0;
	}
}

void TIM2_Config()
{
	__HAL_RCC_TIM2_CLK_ENABLE();

	TIM2_Handle.Instance 			= TIM2;
	TIM2_Handle.Channel				= TIM_CHANNEL_1;
	TIM2_Handle.Init.CounterMode	= TIM_COUNTERMODE_UP;
	TIM2_Handle.Init.ClockDivision  = TIM_CLOCKDIVISION_DIV1;
	TIM2_Handle.Init.Period			= 1;		// 1% of 1/100 sec
	TIM2_Handle.Init.Prescaler		= 10800 - 1;
	HAL_TIM_Base_Init(&TIM2_Handle);

	HAL_NVIC_SetPriority(TIM2_IRQn, 0x0D, 0x0);
	HAL_NVIC_EnableIRQ(TIM2_IRQn);
}

void TIM2_IRQHandler()
{
	HAL_TIM_IRQHandler(&TIM2_Handle);
}


void HAL_TIM_PeriodElapsedCallback(TIM_HandleTypeDef *htim)
{
	if (htim->Instance == TIM2) {
		++pwm_cnt;
		if (pwm_cnt > 100) {
			pwm_cnt = 0;
			++periodElapsed_Counter;
			if (periodElapsed_Counter > 200) {
				periodElapsed_Counter = 0;
				HAL_TIM_Base_Stop_IT(&TIM2_Handle);
				ResetLEDs();
			}
		}

		for (unsigned int i = 0; i < LED_NUM; ++i) {
			if (leds[i].on == 1 && pwm_cnt < leds[i].duty_cycle) {
				HAL_GPIO_WritePin(leds[i].port, leds[i].pin, GPIO_PIN_SET);
				//printf("%u, %u\n", pwm_cnt, leds[i].duty_cycle);
			} else {
				HAL_GPIO_WritePin(leds[i].port, leds[i].pin, GPIO_PIN_RESET);
			}
		}
	}
}

void UART_Config(void) {
    UartHandle.Init.BaudRate = 115200;
    UartHandle.Init.WordLength = UART_WORDLENGTH_8B;
    UartHandle.Init.StopBits = UART_STOPBITS_1;
    UartHandle.Init.Parity = UART_PARITY_NONE;
    UartHandle.Init.HwFlowCtl = UART_HWCONTROL_NONE;
    UartHandle.Init.Mode = UART_MODE_TX_RX;

    BSP_COM_Init(COM1, &UartHandle);
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
static void SystemClock_Config(void)
{
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
    RCC_ClkInitStruct.ClockType = (RCC_CLOCKTYPE_SYSCLK | RCC_CLOCKTYPE_HCLK | RCC_CLOCKTYPE_PCLK1
            | RCC_CLOCKTYPE_PCLK2);
    RCC_ClkInitStruct.SYSCLKSource = RCC_SYSCLKSOURCE_PLLCLK;
    RCC_ClkInitStruct.AHBCLKDivider = RCC_SYSCLK_DIV1;
    RCC_ClkInitStruct.APB1CLKDivider = RCC_HCLK_DIV4;
    RCC_ClkInitStruct.APB2CLKDivider = RCC_HCLK_DIV2;
    if (HAL_RCC_ClockConfig(&RCC_ClkInitStruct, FLASH_LATENCY_7) != HAL_OK) {
        Error_Handler();
    }
}

/**
  * @brief  This function is executed in case of error occurrence.
  * @param  None
  * @retval None
  */
static void Error_Handler(void)
{
  /* User may add here some code to deal with this error */
  while(1)
  {
  }
}

/**
  * @brief  Configure the MPU attributes as Write Through for SRAM1/2.
  * @note   The Base Address is 0x20010000 since this memory interface is the AXI.
  *         The Region Size is 256KB, it is related to SRAM1 and SRAM2  memory size.
  * @param  None
  * @retval None
  */
static void MPU_Config(void)
{
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
static void CPU_CACHE_Enable(void)
{
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
    HAL_UART_Transmit(&UartHandle, (uint8_t *) &ch, 1, 0xFFFF);

    return ch;
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
