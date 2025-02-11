/* USER CODE BEGIN Header */
/**
  ******************************************************************************
  * @file           : main.c
  * @brief          : Main program body
  ******************************************************************************
  * @attention
  *
  * <h2><center>&copy; Copyright (c) 2024 STMicroelectronics.
  * All rights reserved.</center></h2>
  *
  * This software component is licensed by ST under BSD 3-Clause license,
  * the "License"; You may not use this file except in compliance with the
  * License. You may obtain a copy of the License at:
  *                        opensource.org/licenses/BSD-3-Clause
  *
  ******************************************************************************
  */
/* USER CODE END Header */
/* Includes ------------------------------------------------------------------*/
#include "main.h"

/* Private includes ----------------------------------------------------------*/
/* USER CODE BEGIN Includes */
#include "software_timer.h"

/* USER CODE END Includes */

/* Private typedef -----------------------------------------------------------*/
/* USER CODE BEGIN PTD */

/* USER CODE END PTD */

/* Private define ------------------------------------------------------------*/
/* USER CODE BEGIN PD */
/* USER CODE END PD */

/* Private macro -------------------------------------------------------------*/
/* USER CODE BEGIN PM */

/* USER CODE END PM */

/* Private variables ---------------------------------------------------------*/

/* USER CODE BEGIN PV */

/* USER CODE END PV */

/* Private function prototypes -----------------------------------------------*/
void SystemClock_Config(void);
static void MX_GPIO_Init(void);
/* USER CODE BEGIN PFP */

/* USER CODE END PFP */

/* Private user code ---------------------------------------------------------*/
/* USER CODE BEGIN 0 */
void HAL_TIM_PeriodElapsedCallback(TIM_HandleTypeDef *htim)
{
	timerRun();
}
static void display7seg1(int num){
	switch(num){
	  case 0:
		  	  	HAL_GPIO_WritePin(num_a_GPIO_Port, num_a_Pin, GPIO_PIN_RESET);
		  	  	HAL_GPIO_WritePin(num_b_GPIO_Port, num_b_Pin, GPIO_PIN_RESET);
		  	  	HAL_GPIO_WritePin(num_c_GPIO_Port, num_c_Pin, GPIO_PIN_RESET);
		  	  	HAL_GPIO_WritePin(num_d_GPIO_Port, num_d_Pin, GPIO_PIN_RESET);
		  	  	HAL_GPIO_WritePin(num_e_GPIO_Port, num_e_Pin, GPIO_PIN_RESET);
		  	  	HAL_GPIO_WritePin(num_f_GPIO_Port, num_f_Pin, GPIO_PIN_RESET);
		  	  	HAL_GPIO_WritePin(num_g_GPIO_Port, num_g_Pin, GPIO_PIN_SET);
		  	  	break;
	  case 1:
	  		    HAL_GPIO_WritePin(num_a_GPIO_Port, num_a_Pin, GPIO_PIN_SET);
	  		    HAL_GPIO_WritePin(num_b_GPIO_Port, num_b_Pin, GPIO_PIN_RESET);
	  		    HAL_GPIO_WritePin(num_c_GPIO_Port, num_c_Pin, GPIO_PIN_RESET);
	  		    HAL_GPIO_WritePin(num_d_GPIO_Port, num_d_Pin, GPIO_PIN_SET);
	  		    HAL_GPIO_WritePin(num_e_GPIO_Port, num_e_Pin, GPIO_PIN_SET);
	  		    HAL_GPIO_WritePin(num_f_GPIO_Port, num_f_Pin, GPIO_PIN_SET);
	  		    HAL_GPIO_WritePin(num_g_GPIO_Port, num_g_Pin, GPIO_PIN_SET);
	  	  	    break;
	  case 2:
	  			HAL_GPIO_WritePin(num_a_GPIO_Port, num_a_Pin, GPIO_PIN_RESET);
	  			HAL_GPIO_WritePin(num_b_GPIO_Port, num_b_Pin, GPIO_PIN_RESET);
	  			HAL_GPIO_WritePin(num_c_GPIO_Port, num_c_Pin, GPIO_PIN_SET);
	  			HAL_GPIO_WritePin(num_d_GPIO_Port, num_d_Pin, GPIO_PIN_RESET);
	  			HAL_GPIO_WritePin(num_e_GPIO_Port, num_e_Pin, GPIO_PIN_RESET);
	  			HAL_GPIO_WritePin(num_f_GPIO_Port, num_f_Pin, GPIO_PIN_SET);
	  			HAL_GPIO_WritePin(num_g_GPIO_Port, num_g_Pin, GPIO_PIN_RESET);
	  			break;

	  case 3:
	  	  		HAL_GPIO_WritePin(num_a_GPIO_Port, num_a_Pin, GPIO_PIN_RESET);
	  	  		    HAL_GPIO_WritePin(num_b_GPIO_Port, num_b_Pin, GPIO_PIN_RESET);
	  	  		    HAL_GPIO_WritePin(num_c_GPIO_Port, num_c_Pin, GPIO_PIN_RESET);
	  	  		    HAL_GPIO_WritePin(num_d_GPIO_Port, num_d_Pin, GPIO_PIN_RESET);
	  	  		    HAL_GPIO_WritePin(num_e_GPIO_Port, num_e_Pin, GPIO_PIN_SET);
	  	  		    HAL_GPIO_WritePin(num_f_GPIO_Port, num_f_Pin, GPIO_PIN_SET);
	  	  		    HAL_GPIO_WritePin(num_g_GPIO_Port, num_g_Pin, GPIO_PIN_RESET);
	  	  		    break;
	  case 4:
	 	  	  		HAL_GPIO_WritePin(num_a_GPIO_Port, num_a_Pin, GPIO_PIN_SET);
	 	  	  		HAL_GPIO_WritePin(num_b_GPIO_Port, num_b_Pin, GPIO_PIN_RESET);
	 	  	  		HAL_GPIO_WritePin(num_c_GPIO_Port, num_c_Pin, GPIO_PIN_RESET);
	 	  	  		HAL_GPIO_WritePin(num_d_GPIO_Port, num_d_Pin, GPIO_PIN_SET);
	 	  	  		HAL_GPIO_WritePin(num_e_GPIO_Port, num_e_Pin, GPIO_PIN_SET);
	 	  	  		HAL_GPIO_WritePin(num_f_GPIO_Port, num_f_Pin, GPIO_PIN_RESET);
	 	  	  		HAL_GPIO_WritePin(num_g_GPIO_Port, num_g_Pin, GPIO_PIN_RESET);
	 	  	  		break;
	 case 5:
	 	  			HAL_GPIO_WritePin(num_a_GPIO_Port, num_a_Pin, GPIO_PIN_RESET);
	 	  			HAL_GPIO_WritePin(num_b_GPIO_Port, num_b_Pin, GPIO_PIN_SET);
	 	  			HAL_GPIO_WritePin(num_c_GPIO_Port, num_c_Pin, GPIO_PIN_RESET);
	 	  			HAL_GPIO_WritePin(num_d_GPIO_Port, num_d_Pin, GPIO_PIN_RESET);
	 	  			HAL_GPIO_WritePin(num_e_GPIO_Port, num_e_Pin, GPIO_PIN_SET);
	 	  			HAL_GPIO_WritePin(num_f_GPIO_Port, num_f_Pin, GPIO_PIN_RESET);
	 	  			HAL_GPIO_WritePin(num_g_GPIO_Port, num_g_Pin, GPIO_PIN_RESET);
	 	  			break;
	 case 6:
		 	  		HAL_GPIO_WritePin(num_a_GPIO_Port, num_a_Pin, GPIO_PIN_RESET);
		 	  		HAL_GPIO_WritePin(num_b_GPIO_Port, num_b_Pin, GPIO_PIN_SET);
		 	  		HAL_GPIO_WritePin(num_c_GPIO_Port, num_c_Pin, GPIO_PIN_RESET);
		 	  		HAL_GPIO_WritePin(num_d_GPIO_Port, num_d_Pin, GPIO_PIN_RESET);
		 	  		HAL_GPIO_WritePin(num_e_GPIO_Port, num_e_Pin, GPIO_PIN_RESET);
		 	  		HAL_GPIO_WritePin(num_f_GPIO_Port, num_f_Pin, GPIO_PIN_RESET);
		 	  		HAL_GPIO_WritePin(num_g_GPIO_Port, num_g_Pin, GPIO_PIN_RESET);
		 	  		break;
	 case 7:
		 	  		HAL_GPIO_WritePin(num_a_GPIO_Port, num_a_Pin, GPIO_PIN_RESET);
		 	  		HAL_GPIO_WritePin(num_b_GPIO_Port, num_b_Pin, GPIO_PIN_RESET);
		 	  		HAL_GPIO_WritePin(num_c_GPIO_Port, num_c_Pin, GPIO_PIN_RESET);
		 	  		HAL_GPIO_WritePin(num_d_GPIO_Port, num_d_Pin, GPIO_PIN_SET);
		 	  		HAL_GPIO_WritePin(num_e_GPIO_Port, num_e_Pin, GPIO_PIN_SET);
		 	  		HAL_GPIO_WritePin(num_f_GPIO_Port, num_f_Pin, GPIO_PIN_SET);
		 	  		HAL_GPIO_WritePin(num_g_GPIO_Port, num_g_Pin, GPIO_PIN_SET);
		 	  		break;
	 case 8:
		 	  		HAL_GPIO_WritePin(num_a_GPIO_Port, num_a_Pin, GPIO_PIN_RESET);
		 	  		HAL_GPIO_WritePin(num_b_GPIO_Port, num_b_Pin, GPIO_PIN_RESET);
		 	  		HAL_GPIO_WritePin(num_c_GPIO_Port, num_c_Pin, GPIO_PIN_RESET);
		 	  		HAL_GPIO_WritePin(num_d_GPIO_Port, num_d_Pin, GPIO_PIN_RESET);
		 	  		HAL_GPIO_WritePin(num_e_GPIO_Port, num_e_Pin, GPIO_PIN_RESET);
		 	  		HAL_GPIO_WritePin(num_f_GPIO_Port, num_f_Pin, GPIO_PIN_RESET);
		 	  		HAL_GPIO_WritePin(num_g_GPIO_Port, num_g_Pin, GPIO_PIN_RESET);
		 	  		break;
	 case 9:
		 	  		HAL_GPIO_WritePin(num_a_GPIO_Port, num_a_Pin, GPIO_PIN_RESET);
		 	  		HAL_GPIO_WritePin(num_b_GPIO_Port, num_b_Pin, GPIO_PIN_RESET);
		 	  		HAL_GPIO_WritePin(num_c_GPIO_Port, num_c_Pin, GPIO_PIN_RESET);
		 	  		HAL_GPIO_WritePin(num_d_GPIO_Port, num_d_Pin, GPIO_PIN_RESET);
		 	  		HAL_GPIO_WritePin(num_e_GPIO_Port, num_e_Pin, GPIO_PIN_SET);
		 	  		HAL_GPIO_WritePin(num_f_GPIO_Port, num_f_Pin, GPIO_PIN_RESET);
		 	  		HAL_GPIO_WritePin(num_g_GPIO_Port, num_g_Pin, GPIO_PIN_RESET);
		 	  		break;
	default:
					HAL_GPIO_WritePin(num_a_GPIO_Port, num_a_Pin, GPIO_PIN_SET);
					HAL_GPIO_WritePin(num_b_GPIO_Port, num_b_Pin, GPIO_PIN_SET);
					HAL_GPIO_WritePin(num_c_GPIO_Port, num_c_Pin, GPIO_PIN_SET);
					HAL_GPIO_WritePin(num_d_GPIO_Port, num_d_Pin, GPIO_PIN_SET);
					HAL_GPIO_WritePin(num_e_GPIO_Port, num_e_Pin, GPIO_PIN_SET);
					HAL_GPIO_WritePin(num_f_GPIO_Port, num_f_Pin, GPIO_PIN_SET);
					HAL_GPIO_WritePin(num_g_GPIO_Port, num_g_Pin, GPIO_PIN_SET);
					break;
	}
}
static void display7seg2(int num){
    switch(num){
        case 0:
            HAL_GPIO_WritePin(num_a_1_GPIO_Port, num_a_1_Pin, GPIO_PIN_RESET);
            HAL_GPIO_WritePin(num_b_1_GPIO_Port, num_b_1_Pin, GPIO_PIN_RESET);
            HAL_GPIO_WritePin(num_c_1_GPIO_Port, num_c_1_Pin, GPIO_PIN_RESET);
            HAL_GPIO_WritePin(num_d_1_GPIO_Port, num_d_1_Pin, GPIO_PIN_RESET);
            HAL_GPIO_WritePin(num_e_1_GPIO_Port, num_e_1_Pin, GPIO_PIN_RESET);
            HAL_GPIO_WritePin(num_f_1_GPIO_Port, num_f_1_Pin, GPIO_PIN_RESET);
            HAL_GPIO_WritePin(num_g_1_GPIO_Port, num_g_1_Pin, GPIO_PIN_SET);
            break;
        case 1:
            HAL_GPIO_WritePin(num_a_1_GPIO_Port, num_a_1_Pin, GPIO_PIN_SET);
            HAL_GPIO_WritePin(num_b_1_GPIO_Port, num_b_1_Pin, GPIO_PIN_RESET);
            HAL_GPIO_WritePin(num_c_1_GPIO_Port, num_c_1_Pin, GPIO_PIN_RESET);
            HAL_GPIO_WritePin(num_d_1_GPIO_Port, num_d_1_Pin, GPIO_PIN_SET);
            HAL_GPIO_WritePin(num_e_1_GPIO_Port, num_e_1_Pin, GPIO_PIN_SET);
            HAL_GPIO_WritePin(num_f_1_GPIO_Port, num_f_1_Pin, GPIO_PIN_SET);
            HAL_GPIO_WritePin(num_g_1_GPIO_Port, num_g_1_Pin, GPIO_PIN_SET);
            break;
        case 2:
            HAL_GPIO_WritePin(num_a_1_GPIO_Port, num_a_1_Pin, GPIO_PIN_RESET);
            HAL_GPIO_WritePin(num_b_1_GPIO_Port, num_b_1_Pin, GPIO_PIN_RESET);
            HAL_GPIO_WritePin(num_c_1_GPIO_Port, num_c_1_Pin, GPIO_PIN_SET);
            HAL_GPIO_WritePin(num_d_1_GPIO_Port, num_d_1_Pin, GPIO_PIN_RESET);
            HAL_GPIO_WritePin(num_e_1_GPIO_Port, num_e_1_Pin, GPIO_PIN_RESET);
            HAL_GPIO_WritePin(num_f_1_GPIO_Port, num_f_1_Pin, GPIO_PIN_SET);
            HAL_GPIO_WritePin(num_g_1_GPIO_Port, num_g_1_Pin, GPIO_PIN_RESET);
            break;
        case 3:
            HAL_GPIO_WritePin(num_a_1_GPIO_Port, num_a_1_Pin, GPIO_PIN_RESET);
            HAL_GPIO_WritePin(num_b_1_GPIO_Port, num_b_1_Pin, GPIO_PIN_RESET);
            HAL_GPIO_WritePin(num_c_1_GPIO_Port, num_c_1_Pin, GPIO_PIN_RESET);
            HAL_GPIO_WritePin(num_d_1_GPIO_Port, num_d_1_Pin, GPIO_PIN_RESET);
            HAL_GPIO_WritePin(num_e_1_GPIO_Port, num_e_1_Pin, GPIO_PIN_SET);
            HAL_GPIO_WritePin(num_f_1_GPIO_Port, num_f_1_Pin, GPIO_PIN_SET);
            HAL_GPIO_WritePin(num_g_1_GPIO_Port, num_g_1_Pin, GPIO_PIN_RESET);
            break;
        case 4:
            HAL_GPIO_WritePin(num_a_1_GPIO_Port, num_a_1_Pin, GPIO_PIN_SET);
            HAL_GPIO_WritePin(num_b_1_GPIO_Port, num_b_1_Pin, GPIO_PIN_RESET);
            HAL_GPIO_WritePin(num_c_1_GPIO_Port, num_c_1_Pin, GPIO_PIN_RESET);
            HAL_GPIO_WritePin(num_d_1_GPIO_Port, num_d_1_Pin, GPIO_PIN_SET);
            HAL_GPIO_WritePin(num_e_1_GPIO_Port, num_e_1_Pin, GPIO_PIN_SET);
            HAL_GPIO_WritePin(num_f_1_GPIO_Port, num_f_1_Pin, GPIO_PIN_RESET);
            HAL_GPIO_WritePin(num_g_1_GPIO_Port, num_g_1_Pin, GPIO_PIN_RESET);
            break;
        case 5:
            HAL_GPIO_WritePin(num_a_1_GPIO_Port, num_a_1_Pin, GPIO_PIN_RESET);
            HAL_GPIO_WritePin(num_b_1_GPIO_Port, num_b_1_Pin, GPIO_PIN_SET);
            HAL_GPIO_WritePin(num_c_1_GPIO_Port, num_c_1_Pin, GPIO_PIN_RESET);
            HAL_GPIO_WritePin(num_d_1_GPIO_Port, num_d_1_Pin, GPIO_PIN_RESET);
            HAL_GPIO_WritePin(num_e_1_GPIO_Port, num_e_1_Pin, GPIO_PIN_SET);
            HAL_GPIO_WritePin(num_f_1_GPIO_Port, num_f_1_Pin, GPIO_PIN_RESET);
            HAL_GPIO_WritePin(num_g_1_GPIO_Port, num_g_1_Pin, GPIO_PIN_RESET);
            break;
        case 6:
            HAL_GPIO_WritePin(num_a_1_GPIO_Port, num_a_1_Pin, GPIO_PIN_RESET);
            HAL_GPIO_WritePin(num_b_1_GPIO_Port, num_b_1_Pin, GPIO_PIN_SET);
            HAL_GPIO_WritePin(num_c_1_GPIO_Port, num_c_1_Pin, GPIO_PIN_RESET);
            HAL_GPIO_WritePin(num_d_1_GPIO_Port, num_d_1_Pin, GPIO_PIN_RESET);
            HAL_GPIO_WritePin(num_e_1_GPIO_Port, num_e_1_Pin, GPIO_PIN_RESET);
            HAL_GPIO_WritePin(num_f_1_GPIO_Port, num_f_1_Pin, GPIO_PIN_RESET);
            HAL_GPIO_WritePin(num_g_1_GPIO_Port, num_g_1_Pin, GPIO_PIN_RESET);
            break;
        case 7:
            HAL_GPIO_WritePin(num_a_1_GPIO_Port, num_a_1_Pin, GPIO_PIN_RESET);
            HAL_GPIO_WritePin(num_b_1_GPIO_Port, num_b_1_Pin, GPIO_PIN_RESET);
            HAL_GPIO_WritePin(num_c_1_GPIO_Port, num_c_1_Pin, GPIO_PIN_RESET);
            HAL_GPIO_WritePin(num_d_1_GPIO_Port, num_d_1_Pin, GPIO_PIN_SET);
            HAL_GPIO_WritePin(num_e_1_GPIO_Port, num_e_1_Pin, GPIO_PIN_SET);
            HAL_GPIO_WritePin(num_f_1_GPIO_Port, num_f_1_Pin, GPIO_PIN_SET);
            HAL_GPIO_WritePin(num_g_1_GPIO_Port, num_g_1_Pin, GPIO_PIN_SET);
            break;
        case 8:
            HAL_GPIO_WritePin(num_a_1_GPIO_Port, num_a_1_Pin, GPIO_PIN_RESET);
            HAL_GPIO_WritePin(num_b_1_GPIO_Port, num_b_1_Pin, GPIO_PIN_RESET);
            HAL_GPIO_WritePin(num_c_1_GPIO_Port, num_c_1_Pin, GPIO_PIN_RESET);
            HAL_GPIO_WritePin(num_d_1_GPIO_Port, num_d_1_Pin, GPIO_PIN_RESET);
            HAL_GPIO_WritePin(num_e_1_GPIO_Port, num_e_1_Pin, GPIO_PIN_RESET);
            HAL_GPIO_WritePin(num_f_1_GPIO_Port, num_f_1_Pin, GPIO_PIN_RESET);
            HAL_GPIO_WritePin(num_g_1_GPIO_Port, num_g_1_Pin, GPIO_PIN_RESET);
            break;
        case 9:
            HAL_GPIO_WritePin(num_a_1_GPIO_Port, num_a_1_Pin, GPIO_PIN_RESET);
            HAL_GPIO_WritePin(num_b_1_GPIO_Port, num_b_1_Pin, GPIO_PIN_RESET);
            HAL_GPIO_WritePin(num_c_1_GPIO_Port, num_c_1_Pin, GPIO_PIN_RESET);
            HAL_GPIO_WritePin(num_d_1_GPIO_Port, num_d_1_Pin, GPIO_PIN_RESET);
            HAL_GPIO_WritePin(num_e_1_GPIO_Port, num_e_1_Pin, GPIO_PIN_SET);
            HAL_GPIO_WritePin(num_f_1_GPIO_Port, num_f_1_Pin, GPIO_PIN_RESET);
            HAL_GPIO_WritePin(num_g_1_GPIO_Port, num_g_1_Pin, GPIO_PIN_RESET);
            break;
        default:
            HAL_GPIO_WritePin(num_a_1_GPIO_Port, num_a_1_Pin, GPIO_PIN_SET);
            HAL_GPIO_WritePin(num_b_1_GPIO_Port, num_b_1_Pin, GPIO_PIN_SET);
            HAL_GPIO_WritePin(num_c_1_GPIO_Port, num_c_1_Pin, GPIO_PIN_SET);
            HAL_GPIO_WritePin(num_d_1_GPIO_Port, num_d_1_Pin, GPIO_PIN_SET);
            HAL_GPIO_WritePin(num_e_1_GPIO_Port, num_e_1_Pin, GPIO_PIN_SET);
            HAL_GPIO_WritePin(num_f_1_GPIO_Port, num_f_1_Pin, GPIO_PIN_SET);
            HAL_GPIO_WritePin(num_g_1_GPIO_Port, num_g_1_Pin, GPIO_PIN_SET);
            break;
        }
}


/* Define states for the LED patterns */

/* USER CODE END 0 */

/**
  * @brief  The application entry point.
  * @retval int
  */
int main(void)
{

  /* USER CODE BEGIN 1 */


  /* USER CODE END 1 */

  /* MCU Configuration--------------------------------------------------------*/

  /* Reset of all peripherals, Initializes the Flash interface and the Systick. */
  HAL_Init();

  /* USER CODE BEGIN Init */

  /* USER CODE END Init */

  /* Configure the system clock */
  SystemClock_Config();

  /* USER CODE BEGIN SysInit */

  /* USER CODE END SysInit */

  /* Initialize all configured peripherals */
  MX_GPIO_Init();
  /* USER CODE BEGIN 2 */
HAL_TIM_Base_Start_IT(&htim2);
int redstate = 0;
int states = 0;
setTimer(0, 500);
setTimer(1, 300);
  /* USER CODE END 2 */

  /* Infinite loop */
  /* USER CODE BEGIN WHILE */

 while (1) {
	  switch(redstate){
	  case 0:
		  HAL_GPIO_WritePin(LED_RED_GPIO_Port, LED_RED_Pin, GPIO_PIN_RESET);
		  HAL_GPIO_WritePin(LED_RED_1_GPIO_Port, LED_RED_1_Pin, GPIO_PIN_SET);

		  if(isTimerExpired(0) == 1) {
			  redstate = 1;
			  setTimer(0,500); //5 seconds for RED OFF
			  }
			  switch(states){
				  case 0:
					  HAL_GPIO_WritePin(LED_GREEN_1_GPIO_Port, LED_GREEN_1_Pin, GPIO_PIN_RESET);
					  HAL_GPIO_WritePin(LED_YELLOW_1_GPIO_Port, LED_YELLOW_1_Pin, GPIO_PIN_SET);
					  if(isTimerExpired(1) == 1) {
						  states = 1;
						  setTimer(2,200); // 2 second for YELLOW ON AND
					  }
					  display7seg2( (timer_counter[1]+100) / 100);
					  break;
				  case 1:
					  HAL_GPIO_WritePin(LED_YELLOW_1_GPIO_Port, LED_YELLOW_1_Pin, GPIO_PIN_RESET);
					  HAL_GPIO_WritePin(LED_GREEN_1_GPIO_Port, LED_GREEN_1_Pin, GPIO_PIN_SET);
					  if(isTimerExpired(2) == 1){
						  redstate = 1;
						  states = 0;
						  setTimer(0,500);
						  setTimer(1,300);
						  HAL_GPIO_WritePin(LED_YELLOW_1_GPIO_Port, LED_YELLOW_1_Pin, GPIO_PIN_SET);
					  }
					  display7seg2( (timer_counter[2]+100) / 100);
					  break;
				  }
			  display7seg1( (timer_counter[0]+100) / 100);
		  break;
	  case 1:
		  HAL_GPIO_WritePin(LED_RED_GPIO_Port, LED_RED_Pin, GPIO_PIN_SET);
		  HAL_GPIO_WritePin(LED_RED_1_GPIO_Port, LED_RED_1_Pin, GPIO_PIN_RESET);
		  if(isTimerExpired(0) == 1) {
			  redstate = 0;
			  setTimer(0,500); //5 seconds for RED ON
		  }
		  switch(states){
		  				  case 0:
		  					  HAL_GPIO_WritePin(LED_GREEN_GPIO_Port, LED_GREEN_Pin, GPIO_PIN_RESET);
		  					  HAL_GPIO_WritePin(LED_YELLOW_GPIO_Port, LED_YELLOW_Pin, GPIO_PIN_SET);
		  					  if(isTimerExpired(1) == 1) {
		  						  states = 1;
		  						  setTimer(2,200);
		  					  }
		  					display7seg1( (timer_counter[1]+100) / 100);
		  					  break;
		  				  case 1:
		  					  HAL_GPIO_WritePin(LED_YELLOW_GPIO_Port, LED_YELLOW_Pin, GPIO_PIN_RESET);
		  					  HAL_GPIO_WritePin(LED_GREEN_GPIO_Port, LED_GREEN_Pin, GPIO_PIN_SET);
		  					  if(isTimerExpired(2) == 1){
		  						  redstate = 0;
		  						  states = 0;
		  						  setTimer(0,500);
		  						  setTimer(1,300);
		  						  HAL_GPIO_WritePin(LED_YELLOW_GPIO_Port, LED_YELLOW_Pin, GPIO_PIN_SET);
		  					  }
		  					display7seg1( (timer_counter[2]+100) / 100);
		  					  break;
		  				  }
		  display7seg2( (timer_counter[0]+100) / 100);
		  break;
	  }

    /* USER CODE END WHILE */

    /* USER CODE BEGIN 3 */
  }
  /* USER CODE END 3 */
}

/**
  * @brief System Clock Configuration
  * @retval None
  */
void SystemClock_Config(void)
{
  RCC_OscInitTypeDef RCC_OscInitStruct = {0};
  RCC_ClkInitTypeDef RCC_ClkInitStruct = {0};

  /** Initializes the RCC Oscillators according to the specified parameters
  * in the RCC_OscInitTypeDef structure.
  */
  RCC_OscInitStruct.OscillatorType = RCC_OSCILLATORTYPE_HSI;
  RCC_OscInitStruct.HSIState = RCC_HSI_ON;
  RCC_OscInitStruct.HSICalibrationValue = RCC_HSICALIBRATION_DEFAULT;
  RCC_OscInitStruct.PLL.PLLState = RCC_PLL_NONE;
  if (HAL_RCC_OscConfig(&RCC_OscInitStruct) != HAL_OK)
  {
    Error_Handler();
  }

  /** Initializes the CPU, AHB and APB buses clocks
  */
  RCC_ClkInitStruct.ClockType = RCC_CLOCKTYPE_HCLK|RCC_CLOCKTYPE_SYSCLK
                              |RCC_CLOCKTYPE_PCLK1|RCC_CLOCKTYPE_PCLK2;
  RCC_ClkInitStruct.SYSCLKSource = RCC_SYSCLKSOURCE_HSI;
  RCC_ClkInitStruct.AHBCLKDivider = RCC_SYSCLK_DIV1;
  RCC_ClkInitStruct.APB1CLKDivider = RCC_HCLK_DIV1;
  RCC_ClkInitStruct.APB2CLKDivider = RCC_HCLK_DIV1;

  if (HAL_RCC_ClockConfig(&RCC_ClkInitStruct, FLASH_LATENCY_0) != HAL_OK)
  {
    Error_Handler();
  }
}

/**
  * @brief GPIO Initialization Function
  * @param None
  * @retval None
  */
static void MX_GPIO_Init(void)
{
  GPIO_InitTypeDef GPIO_InitStruct = {0};
/* USER CODE BEGIN MX_GPIO_Init_1 */
/* USER CODE END MX_GPIO_Init_1 */

  /* GPIO Ports Clock Enable */
  __HAL_RCC_GPIOA_CLK_ENABLE();

  /*Configure GPIO pin Output Level */
  HAL_GPIO_WritePin(GPIOA, LED_RED_Pin|LED_YELLOW_Pin|LED_GREEN_Pin|LED_RED_1_Pin
                          |LED_YELLOW_1_Pin|LED_GREEN_1_Pin, GPIO_PIN_RESET);

  /*Configure GPIO pins : LED_RED_Pin LED_YELLOW_Pin LED_GREEN_Pin LED_RED_1_Pin
                           LED_YELLOW_1_Pin LED_GREEN_1_Pin */
  GPIO_InitStruct.Pin = LED_RED_Pin|LED_YELLOW_Pin|LED_GREEN_Pin|LED_RED_1_Pin
                          |LED_YELLOW_1_Pin|LED_GREEN_1_Pin;
  GPIO_InitStruct.Mode = GPIO_MODE_OUTPUT_PP;
  GPIO_InitStruct.Pull = GPIO_NOPULL;
  GPIO_InitStruct.Speed = GPIO_SPEED_FREQ_LOW;
  HAL_GPIO_Init(GPIOA, &GPIO_InitStruct);

/* USER CODE BEGIN MX_GPIO_Init_2 */
/* USER CODE END MX_GPIO_Init_2 */
}

/* USER CODE BEGIN 4 */
/* USER CODE END 4 */

/**
  * @brief  This function is executed in case of error occurrence.
  * @retval None
  */
void Error_Handler(void)
{
  /* USER CODE BEGIN Error_Handler_Debug */
  /* User can add his own implementation to report the HAL error return state */
  __disable_irq();
  while (1)
  {
  }
  /* USER CODE END Error_Handler_Debug */
}

#ifdef  USE_FULL_ASSERT
/**
  * @brief  Reports the name of the source file and the source line number
  *         where the assert_param error has occurred.
  * @param  file: pointer to the source file name
  * @param  line: assert_param error line source number
  * @retval None
  */
void assert_failed(uint8_t *file, uint32_t line)
{
  /* USER CODE BEGIN 6 */
  /* User can add his own implementation to report the file name and line number,
     ex: printf("Wrong parameters value: file %s on line %d\r\n", file, line) */
  /* USER CODE END 6 */
}
#endif /* USE_FULL_ASSERT */
