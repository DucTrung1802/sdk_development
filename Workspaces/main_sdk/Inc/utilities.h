#ifndef UTILITIES_H_
#define UTILITIES_H_

#include <string.h>
#include <stdio.h>
#include <stdlib.h>
#include <stddef.h>
#include <main.h>

UART_HandleTypeDef huart1;

uint8_t *uint8Cat(uint8_t *string_1, uint8_t *string_2);

void convPrintConstChar(const char *value);

#endif /* UTILITIES_H_ */
