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
/* Private macro -------------------------------------------------------------*/
/* Private variables ---------------------------------------------------------*/
/* Private function prototypes -----------------------------------------------*/
static void SystemClock_Config(void);
static void Error_Handler(void);
static void MPU_Config(void);
static void CPU_CACHE_Enable(void);

/* Private functions ---------------------------------------------------------*/

void My_Init(void)
{
	__HAL_RCC_GPIOA_CLK_ENABLE();    // we need to enable the GPIOA port's clock first

	GPIO_InitTypeDef led0;            // create a config structure
	led0.Pin = GPIO_PIN_0;            // this is about PIN 0
	led0.Mode = GPIO_MODE_OUTPUT_PP;  // Configure as output with push-up-down enabled
	led0.Pull = GPIO_PULLDOWN;        // the push-up-down should work as pulldown
	led0.Speed = GPIO_SPEED_HIGH;     // we need a high-speed output

	HAL_GPIO_Init(GPIOA, &led0);      // initialize the pin on GPIOA port with HAL

	__HAL_RCC_GPIOF_CLK_ENABLE();    // we need to enable the GPIOA port's clock first

	GPIO_InitTypeDef led1;            // create a config structure
	led1.Pin = GPIO_PIN_8;            // this is about PIN 0
	led1.Mode = GPIO_MODE_OUTPUT_PP;  // Configure as output with push-up-down enabled
	led1.Pull = GPIO_PULLDOWN;        // the push-up-down should work as pulldown
	led1.Speed = GPIO_SPEED_HIGH;     // we need a high-speed output

	HAL_GPIO_Init(GPIOF, &led1);      // initialize the pin on GPIOA port with HAL

	GPIO_InitTypeDef led2;            // create a config structure
	led2.Pin = GPIO_PIN_9;            // this is about PIN 0
	led2.Mode = GPIO_MODE_OUTPUT_PP;  // Configure as output with push-up-down enabled
	led2.Pull = GPIO_PULLDOWN;        // the push-up-down should work as pulldown
	led2.Speed = GPIO_SPEED_HIGH;     // we need a high-speed output

	HAL_GPIO_Init(GPIOF, &led2);      // initialize the pin on GPIOA port with HAL

	GPIO_InitTypeDef led3;            // create a config structure
	led3.Pin = GPIO_PIN_10;            // this is about PIN 0
	led3.Mode = GPIO_MODE_OUTPUT_PP;  // Configure as output with push-up-down enabled
	led3.Pull = GPIO_PULLDOWN;        // the push-up-down should work as pulldown
	led3.Speed = GPIO_SPEED_HIGH;     // we need a high-speed output

	HAL_GPIO_Init(GPIOF, &led3);      // initialize the pin on GPIOA port with HAL

	__HAL_RCC_GPIOG_CLK_ENABLE();
	GPIO_InitTypeDef pb1;            // create a config structure
	pb1.Pin = GPIO_PIN_6;
	pb1.Mode = GPIO_MODE_INPUT;
	pb1.Pull = GPIO_PULLUP;
	pb1.Speed = GPIO_SPEED_LOW;
	HAL_GPIO_Init(GPIOG, &pb1);

	__HAL_RCC_GPIOC_CLK_ENABLE();
	GPIO_InitTypeDef pb2;            // create a config structure
	pb2.Pin = GPIO_PIN_6;
	pb2.Mode = GPIO_MODE_INPUT;
	pb2.Pull = GPIO_PULLUP;
	pb2.Speed = GPIO_SPEED_LOW;
	HAL_GPIO_Init(GPIOC, &pb2);

	GPIO_InitTypeDef pb3;            // create a config structure
	pb3.Pin = GPIO_PIN_7;
	pb3.Mode = GPIO_MODE_INPUT;
	pb3.Pull = GPIO_PULLUP;
	pb3.Speed = GPIO_SPEED_LOW;
	HAL_GPIO_Init(GPIOC, &pb3);

}

void RGB_Red(GPIO_PinState state)
{
	if (state == GPIO_PIN_SET)
		HAL_GPIO_WritePin(GPIOF, GPIO_PIN_10, GPIO_PIN_RESET);
	else
		HAL_GPIO_WritePin(GPIOF, GPIO_PIN_10, GPIO_PIN_SET);
}

void RGB_Green(GPIO_PinState state)
{
	if (state == GPIO_PIN_SET)
		HAL_GPIO_WritePin(GPIOF, GPIO_PIN_8, GPIO_PIN_RESET);
	else
		HAL_GPIO_WritePin(GPIOF, GPIO_PIN_8, GPIO_PIN_SET);
}

void RGB_Blue(GPIO_PinState state)
{
	if (state == GPIO_PIN_SET)
		HAL_GPIO_WritePin(GPIOF, GPIO_PIN_9, GPIO_PIN_RESET);
	else
		HAL_GPIO_WritePin(GPIOF, GPIO_PIN_9, GPIO_PIN_SET);
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


  /* Add your application code here     */
  //BSP_LED_Init(LED_GREEN);
  //BSP_LED_On(LED_GREEN);
  My_Init();
  BSP_PB_Init(BUTTON_KEY, BUTTON_MODE_GPIO);


  /* Infinite loop */
  int del = 20;
  float del_red_mul = 1;
  float del_green_mul = 1;
  float del_blue_mul = 1;

  int del_red = del;
  int del_green = del;
  int del_blue = del;

  //GPIOF->ODR = 0b1111111011111111;
  while (1)
  {

	  if (HAL_GPIO_ReadPin(GPIOG, GPIO_PIN_6) == 0) {
		  del_red_mul -= 0.01;
		  if (del_red_mul <= -0.01){
			  del_red_mul = 1;
		  }
		  HAL_Delay(5);
	  }

	  if (HAL_GPIO_ReadPin(GPIOC, GPIO_PIN_6) == 0) {
		  del_green_mul -= 0.01;
		  if (del_green_mul <= -0.01){
			  del_green_mul = 1;
		  }
		  HAL_Delay(5);
	  }

	  if (HAL_GPIO_ReadPin(GPIOC, GPIO_PIN_7) == 0) {
		  del_blue_mul -= 0.01;
		  if (del_blue_mul <= -0.01){
			  del_blue_mul = 1;
		  }
		  HAL_Delay(5);
	  }

	  RGB_Red(GPIO_PIN_RESET);
	  RGB_Green(GPIO_PIN_RESET);
	  RGB_Blue(GPIO_PIN_RESET);

	  del_red = del * del_red_mul;
	  del_green = del * del_green_mul;
	  del_blue = del * del_blue_mul;

	  RGB_Red(GPIO_PIN_SET);
	  RGB_Green(GPIO_PIN_SET);
	  RGB_Blue(GPIO_PIN_SET);

	  if ((del_red < del_green) && (del_red < del_blue)) {
		  HAL_Delay(del_red);
		  RGB_Red(GPIO_PIN_RESET);

		  if (del_green < del_blue) {
			  HAL_Delay(del_green - del_red);
			  RGB_Green(GPIO_PIN_RESET);

			  HAL_Delay(del_blue - del_green);
			  RGB_Blue(GPIO_PIN_RESET);
			  HAL_Delay(del - del_blue);
		  } else {
			  HAL_Delay(del_blue - del_red);
			  RGB_Blue(GPIO_PIN_RESET);

			  HAL_Delay(del_green - del_blue);
			  RGB_Green(GPIO_PIN_RESET);
			  HAL_Delay(del - del_green);
		  }

	  } else if (del_green < del_blue) {
		  HAL_Delay(del_green);
		  RGB_Green(GPIO_PIN_RESET);

		  if (del_blue < del_red) {
			  HAL_Delay(del_blue - del_green);
			  RGB_Blue(GPIO_PIN_RESET);

			  HAL_Delay(del_red - del_blue);
			  RGB_Red(GPIO_PIN_RESET);
			  HAL_Delay(del - del_red);
		  } else {
			  HAL_Delay(del_red - del_green);
			  RGB_Red(GPIO_PIN_RESET);

			  HAL_Delay(del_blue - del_red);
			  RGB_Blue(GPIO_PIN_RESET);
			  HAL_Delay(del - del_blue);
	      }

	  } else {
		  HAL_Delay(del_blue);
		  RGB_Blue(GPIO_PIN_RESET);

		  if (del_green < del_red) {
			  HAL_Delay(del_green - del_blue);
			  RGB_Green(GPIO_PIN_RESET);

			  HAL_Delay(del_red - del_green);
			  RGB_Red(GPIO_PIN_RESET);
			  HAL_Delay(del - del_red);
		  } else {
			  HAL_Delay(del_red - del_blue);
			  RGB_Red(GPIO_PIN_RESET);

			  HAL_Delay(del_green - del_red);
			  RGB_Green(GPIO_PIN_RESET);
			  HAL_Delay(del - del_green);
	      }
	  }

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
