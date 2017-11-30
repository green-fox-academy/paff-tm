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
/* Private define ------------------------------------------------------------*/
#define A0 			GPIOA, GPIO_PIN_0
#define A1 			GPIOF, GPIO_PIN_10
#define A2 			GPIOF, GPIO_PIN_9
#define A3 			GPIOF, GPIO_PIN_8
#define A4 			GPIOF, GPIO_PIN_7
#define A5 			GPIOF, GPIO_PIN_6
#define D0 			GPIOC, GPIO_PIN_7
#define D1 			GPIOC, GPIO_PIN_6
#define D2 			GPIOG, GPIO_PIN_6
#define D3 			GPIOB, GPIO_PIN_4
#define D4 			GPIOG, GPIO_PIN_7
#define D5 			GPIOI, GPIO_PIN_0

#define MPIN14		A5
#define MPIN13		A4
#define MPIN12		A3
#define MPIN10		A2
#define MPIN9		A1
#define MPIN8		A0
#define MPIN7		D5
#define MPIN6		D4
#define MPIN4		D3
#define MPIN3		D2
#define MPIN2		D1
#define MPIN1		D0


#define COL1 MPIN13
#define COL2 MPIN3
#define COL3 MPIN4
#define COL4 MPIN10
#define COL5 MPIN6

#define ROW1 MPIN9
#define ROW2 MPIN14
#define ROW3 MPIN8
#define ROW4 MPIN12
#define ROW5 MPIN1
#define ROW6 MPIN7
#define ROW7 MPIN2

#define LM1 0,0,0,0,0,	0,0,1,0,0,	0,1,1,0,0,	0,0,1,0,0,	0,0,1,0,0,	0,1,1,1,0,	0,0,0,0,0


/* Private macro -------------------------------------------------------------*/
/* Private variables ---------------------------------------------------------*/
/* Private function prototypes -----------------------------------------------*/
static void SystemClock_Config(void);
static void Error_Handler(void);
static void MPU_Config(void);
static void CPU_CACHE_Enable(void);

/* Private functions ---------------------------------------------------------*/

void Col_Init(GPIO_TypeDef *_port, uint16_t _pin)
{
	GPIO_InitTypeDef col;
	col.Pin = _pin;
	col.Mode = GPIO_MODE_OUTPUT_PP;
	col.Pull = GPIO_PULLDOWN;
	col.Speed = GPIO_SPEED_HIGH;

	HAL_GPIO_Init(_port, &col);
	HAL_GPIO_WritePin(_port, _pin, GPIO_PIN_RESET);
}

void Row_Init(GPIO_TypeDef *_port, uint16_t _pin)
{
	GPIO_InitTypeDef row;
	row.Pin = _pin;
	row.Mode = GPIO_MODE_OUTPUT_PP;
	row.Pull = GPIO_PULLUP;
	row.Speed = GPIO_SPEED_HIGH;

	HAL_GPIO_Init(_port, &row);
	HAL_GPIO_WritePin(_port, _pin, GPIO_PIN_SET);
}

void My_Init()
{
	__HAL_RCC_GPIOA_CLK_ENABLE();
	__HAL_RCC_GPIOB_CLK_ENABLE();
	__HAL_RCC_GPIOC_CLK_ENABLE();
	//__HAL_RCC_GPIOD_CLK_ENABLE();
	//__HAL_RCC_GPIOE_CLK_ENABLE();
	__HAL_RCC_GPIOF_CLK_ENABLE();
	__HAL_RCC_GPIOG_CLK_ENABLE();
	//__HAL_RCC_GPIOH_CLK_ENABLE();
	__HAL_RCC_GPIOI_CLK_ENABLE();
	//__HAL_RCC_GPIOJ_CLK_ENABLE();
	//__HAL_RCC_GPIOK_CLK_ENABLE();

	Col_Init(COL1);
	Col_Init(COL2);
	Col_Init(COL3);
	Col_Init(COL4);
	Col_Init(COL5);

	Row_Init(ROW1);
	Row_Init(ROW2);
	Row_Init(ROW3);
	Row_Init(ROW4);
	Row_Init(ROW5);
	Row_Init(ROW6);
	Row_Init(ROW7);
}


struct tPin {
	  GPIO_TypeDef* port;
	  uint16_t		pin;
};

void Row_On(GPIO_TypeDef* col_port, uint16_t col_pin)
{

}

void Row_Off(GPIO_TypeDef* col_port, uint16_t col_pin)
{

}

void LED_On(GPIO_TypeDef* col_port, uint16_t col_pin, GPIO_TypeDef* row_port, uint16_t row_pin)
{
	 HAL_GPIO_WritePin(col_port, col_pin, GPIO_PIN_SET);
	 HAL_GPIO_WritePin(row_port, row_pin, GPIO_PIN_RESET);
}

void LED_Off(GPIO_TypeDef* col_port, uint16_t col_pin, GPIO_TypeDef* row_port, uint16_t row_pin)
{
	 HAL_GPIO_WritePin(col_port, col_pin, GPIO_PIN_RESET);
	 HAL_GPIO_WritePin(row_port, row_pin, GPIO_PIN_SET);
}

void PrintNumber(unsigned int n, unsigned int numbers[10][7][5], tPin *cols, tPin *rows, uint32_t delay)
{
	uint32_t tickstart = 0;
	tickstart = HAL_GetTick();
	while((HAL_GetTick() - tickstart) < delay)
	{
		  for (unsigned int r = 0; r < 7; ++r) {
			  for (unsigned int c = 0; c < 5; ++c) {
				  if (numbers[n][r][c] == 1) {
					  HAL_GPIO_WritePin(cols[c].port, cols[c].pin, GPIO_PIN_SET);
				  } else {
					  HAL_GPIO_WritePin(cols[c].port, cols[c].pin, GPIO_PIN_RESET);
				  }
			  }
			  HAL_GPIO_WritePin(rows[r].port, rows[r].pin, GPIO_PIN_RESET);
			  HAL_Delay(1);
			  HAL_GPIO_WritePin(rows[r].port, rows[r].pin, GPIO_PIN_SET);
		  }
	}
}


/**
  * @brief  Main program
  * @param  None
  * @retval None
  */
int main(void)
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
  My_Init();

  /* Add your application code here     */

  tPin rows[7] =
  {
	ROW1,
	ROW2,
	ROW3,
	ROW4,
	ROW5,
	ROW6,
	ROW7,
  };

  tPin cols[5] =
  {
	COL1,
	COL2,
	COL3,
	COL4,
	COL5,
  };

  //typedef unsigned int tMask[7][5];

  unsigned int numbers[10][7][5] =  {
	// 0
	  0,1,1,1,0,
	  1,0,0,0,1,
	  1,0,0,1,1,
	  1,0,1,0,1,
	  1,1,0,0,1,
	  1,0,0,0,1,
	  0,1,1,1,0,

	// 1
	  0,0,1,0,0,
	  0,1,1,0,0,
	  0,0,1,0,0,
	  0,0,1,0,0,
	  0,0,1,0,0,
	  0,0,1,0,0,
	  0,1,1,1,0,

    // 2
	  0,1,1,1,0,
	  1,0,0,0,1,
	  0,0,0,0,1,
	  0,0,0,1,0,
	  0,0,1,0,0,
	  0,1,0,0,0,
	  1,1,1,1,1,

	// 3
	  1,1,1,1,1,
	  0,0,0,1,0,
	  0,0,1,0,0,
	  0,0,0,1,0,
	  0,0,0,0,1,
	  1,0,0,0,1,
	  0,1,1,1,0,

	// 4
	  0,0,0,1,0,
	  0,0,1,1,0,
	  0,1,0,1,0,
	  1,0,0,1,0,
	  1,1,1,1,1,
	  0,0,0,1,0,
	  0,0,0,1,0,

	// 5
	  1,1,1,1,1,
	  1,0,0,0,0,
	  1,1,1,1,0,
	  0,0,0,0,1,
	  0,0,0,0,1,
	  1,0,0,0,1,
	  0,1,1,1,0,

	// 6
	  0,0,1,1,0,
	  0,1,0,0,0,
	  1,0,0,0,0,
	  1,1,1,1,0,
	  1,0,0,0,1,
	  1,0,0,0,1,
	  0,1,1,1,0,


	// 7
	  1,1,1,1,1,
	  0,0,0,0,1,
	  0,0,0,1,0,
	  0,0,1,0,0,
	  0,1,0,0,0,
	  0,1,0,0,0,
	  0,1,0,0,0,

	// 8
	  0,1,1,1,0,
	  1,0,0,0,1,
	  1,0,0,0,1,
	  0,1,1,1,0,
	  1,0,0,0,1,
	  1,0,0,0,1,
	  0,1,1,1,0,

	// 9
	  0,1,1,1,0,
	  1,0,0,0,1,
	  1,0,0,0,1,
	  0,1,1,1,1,
	  0,0,0,0,1,
	  0,0,0,1,0,
	  0,1,1,0,0,
  };

  //unsigned int led_num = (int)(sizeof(aPins) / sizeof(aPins[0]));

  //for (unsigned int i = 0; i < led_num; ++i){
	//  LED_Init(aPins[i].port, aPins[i].pin);
  //}

  /* Infinite loop */

  //LED_On(COL3, ROW4);



  while (1)
  {
	  HAL_Delay(5000);
	  //PrintNumber(3, numbers, cols, rows, 5000);
	  for (int i = 3; i >= 0 ; --i) {
		  PrintNumber(i, numbers, cols, rows, 1500);
	  }
	  PrintNumber(0, numbers, cols, rows, 5000);

  }

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
  if(HAL_RCC_OscConfig(&RCC_OscInitStruct) != HAL_OK)
  {
    Error_Handler();
  }

  /* activate the OverDrive to reach the 216 Mhz Frequency */
  if(HAL_PWREx_EnableOverDrive() != HAL_OK)
  {
    Error_Handler();
  }
  
  /* Select PLL as system clock source and configure the HCLK, PCLK1 and PCLK2 
     clocks dividers */
  RCC_ClkInitStruct.ClockType = (RCC_CLOCKTYPE_SYSCLK | RCC_CLOCKTYPE_HCLK | RCC_CLOCKTYPE_PCLK1 | RCC_CLOCKTYPE_PCLK2);
  RCC_ClkInitStruct.SYSCLKSource = RCC_SYSCLKSOURCE_PLLCLK;
  RCC_ClkInitStruct.AHBCLKDivider = RCC_SYSCLK_DIV1;
  RCC_ClkInitStruct.APB1CLKDivider = RCC_HCLK_DIV4;  
  RCC_ClkInitStruct.APB2CLKDivider = RCC_HCLK_DIV2;  
  if(HAL_RCC_ClockConfig(&RCC_ClkInitStruct, FLASH_LATENCY_7) != HAL_OK)
  {
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
