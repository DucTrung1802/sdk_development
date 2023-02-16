/* USER CODE BEGIN Header */
/**
 ******************************************************************************
 * File Name          : freertos.c
 * Description        : Code for freertos applications
 ******************************************************************************
 * @attention
 *
 * Copyright (c) 2023 STMicroelectronics.
 * All rights reserved.
 *
 * This software is licensed under terms that can be found in the LICENSE file
 * in the root directory of this software component.
 * If no LICENSE file comes with this software, it is provided AS-IS.
 *
 ******************************************************************************
 */
/* USER CODE END Header */

/* Includes ------------------------------------------------------------------*/
#include "FreeRTOS.h"
#include "task.h"
#include "main.h"
#include "cmsis_os.h"

/* Private includes ----------------------------------------------------------*/
/* USER CODE BEGIN Includes */
#include <string.h>
#include "usart.h"
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
/* USER CODE BEGIN Variables */
char Sim_response[500] = {0};
char Sim_Rxdata[2] = {0};
int8_t sendStatus;
char dataSend[] = "{\"msgType\": \"Logging\",\"data\": {\"LOG\": \"ESP TEST\"}}";
/* USER CODE END Variables */
/* Definitions for defaultTask */
osThreadId_t defaultTaskHandle;
const osThreadAttr_t defaultTask_attributes = {
    .name = "defaultTask",
    .stack_size = 128 * 4,
    .priority = (osPriority_t)osPriorityNormal,
};

/* Private function prototypes -----------------------------------------------*/
/* USER CODE BEGIN FunctionPrototypes */
void display(void *data)
{
  HAL_UART_Transmit(&huart2, (uint8_t *)data, (uint16_t)strlen(data), 1000);
}
void deleteBuffer(char *buf)
{
  int len = strlen(buf);
  for (int i = 0; i < len; i++)
  {
    buf[i] = 0;
  }
}
int8_t Sim_sendCommand(char *command, char *response, uint32_t timeout)
{
  uint8_t answer = 0, count = 0;
  deleteBuffer(Sim_response);
  uint32_t time = HAL_GetTick();
  uint32_t time1 = HAL_GetTick();
  HAL_UART_Transmit(&huart1, (uint8_t *)command, (uint16_t)strlen(command), 1000);
  HAL_UART_Transmit(&huart1, (uint8_t *)"\r\n", (uint16_t)strlen("\r\n"), 1000);
  do
  {
    while (HAL_UART_Receive(&huart1, (uint8_t *)Sim_Rxdata, 1, 1000) != HAL_OK)
    {
      if (HAL_GetTick() - time > timeout)
      {
        return 0;
      }
    }
    time = HAL_GetTick();
    Sim_response[count++] = Sim_Rxdata[0];
    while ((HAL_GetTick() - time < timeout))
    {
      if (HAL_UART_Receive(&huart1, (uint8_t *)Sim_Rxdata, 1, 1000) == HAL_OK)
      {
        Sim_response[count++] = Sim_Rxdata[0];
        time1 = HAL_GetTick();
      }
      else
      {
        if (HAL_GetTick() - time1 > 100)
        {
          if (strstr(Sim_response, response) != NULL)
          {
            answer = 1;
          }
          else
          {
            answer = 0;
          }
          break;
        }
      }
    }
  } while (answer == 0);
  display(Sim_response);
  return answer;
}
/* USER CODE END FunctionPrototypes */

void StartDefaultTask(void *argument);

void MX_FREERTOS_Init(void); /* (MISRA C 2004 rule 8.1) */

/**
 * @brief  FreeRTOS initialization
 * @param  None
 * @retval None
 */
void MX_FREERTOS_Init(void)
{
  /* USER CODE BEGIN Init */

  /* USER CODE END Init */

  /* USER CODE BEGIN RTOS_MUTEX */
  /* add mutexes, ... */
  /* USER CODE END RTOS_MUTEX */

  /* USER CODE BEGIN RTOS_SEMAPHORES */
  /* add semaphores, ... */
  /* USER CODE END RTOS_SEMAPHORES */

  /* USER CODE BEGIN RTOS_TIMERS */
  /* start timers, add new ones, ... */
  /* USER CODE END RTOS_TIMERS */

  /* USER CODE BEGIN RTOS_QUEUES */
  /* add queues, ... */
  /* USER CODE END RTOS_QUEUES */

  /* Create the thread(s) */
  /* creation of defaultTask */
  defaultTaskHandle = osThreadNew(StartDefaultTask, NULL, &defaultTask_attributes);

  /* USER CODE BEGIN RTOS_THREADS */
  /* add threads, ... */
  /* USER CODE END RTOS_THREADS */

  /* USER CODE BEGIN RTOS_EVENTS */
  /* add events, ... */
  /* USER CODE END RTOS_EVENTS */
}

/* USER CODE BEGIN Header_StartDefaultTask */
/**
 * @brief  Function implementing the defaultTask thread.
 * @param  argument: Not used
 * @retval None
 */
/* USER CODE END Header_StartDefaultTask */
void StartDefaultTask(void *argument)
{
  /* USER CODE BEGIN StartDefaultTask */
  /* Infinite loop */
  for (;;)
  {
    if (Sim_sendCommand("AT", "OK", 5000))
    {
      osDelay(10);
      if (Sim_sendCommand("AT+CGMR", "OK", 5000))
      {
        osDelay(10);
        if (Sim_sendCommand("AT+CGSN", "OK", 5000))
        {
          osDelay(10);
          if (Sim_sendCommand("AT+ICCID", "OK", 5000))
          {
            osDelay(10);
            if (Sim_sendCommand("AT+CENG?", "OK", 5000))
            {
              osDelay(10);
              if (Sim_sendCommand("AT+CSOC=1,2,1", "OK", 5000))
              {
                osDelay(10);
                if (Sim_sendCommand("AT+CSOCON=0,20004,\"115.78.92.253\"", "OK", 5000))
                {
                  osDelay(10);
                  if (Sim_sendCommand("AT+CSOSTATUS=0", "OK", 5000))
                  {
                    osDelay(10);
                    if (Sim_sendCommand("AT+CSOSEND=0,2,\"aa\"", "+CSONMI", 5000))
                    {
                      osDelay(10);
                      if (Sim_sendCommand("AT+CSOCL=0", "OK", 5000))
                      {
                        osDelay(10);
                      }
                    }
                  }
                }
              }
            }
          }
        }
      }
    }
    osDelay(30000);
  }
  /* USER CODE END StartDefaultTask */
}

/* Private application code --------------------------------------------------*/
/* USER CODE BEGIN Application */

/* USER CODE END Application */
