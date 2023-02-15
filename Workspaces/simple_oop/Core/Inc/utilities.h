/*
 * ulti.h
 *
 *  Created on: 12 Feb 2023
 *      Author: lyduc
 */

#ifndef INC_UTILITIES_H_
#define INC_UTILITIES_H_

#include "main.h"
#include <string.h>
#include <string>

#ifdef __cplusplus
extern "C"
#endif

UART_HandleTypeDef huart1;


uint8_t * uint8Cat(uint8_t * string_1, uint8_t * string_2);

void convPrint(uint8_t * value);

void convPrint(int value);

void newLine();

#ifdef __cplusplus

#endif


#endif /* INC_UTILITIES_H_ */
