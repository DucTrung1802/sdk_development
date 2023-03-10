/*
 * uint8Cat.cpp
 *
 *  Created on: 12 Feb 2023
 *      Author: lyduc
 */

#include "utilities.h"

uint8_t * uint8Cat(uint8_t * string_1, uint8_t * string_2){
	uint8_t *concatenated;
	size_t len1 = strlen((char *)string_1);
	size_t len2 = strlen((char *)string_2);

	// Allocate memory for the concatenated string
	concatenated = (uint8_t *)malloc(len1 + len2 + 1);
	if (concatenated == NULL) {
		printf("Failed to allocate memory\n");
		return NULL;
	}

	// Copy characters from string1 into concatenated
	memcpy(concatenated, string_1, len1);

	// Copy characters from string2 into concatenated after string1
	memcpy(concatenated + len1, string_2, len2);

	// Null-terminate the concatenated string
	concatenated[len1 + len2] = '\0';

	return concatenated;
}

void convPrint(uint8_t* value) {
	uint8_t new_line[] = "\n";
	uint8_t * output = uint8Cat(value, new_line);
	HAL_UART_Transmit(&huart1, output, strlen((const char *)output), 500);
}

void convPrint(int value) {
	char buffer[15];
	itoa(value, buffer, 10);
	uint8_t new_line[] = "\n";
	uint8_t * output = uint8Cat((uint8_t *)buffer, new_line);
	HAL_UART_Transmit(&huart1, output, strlen((const char *)output), 500);
}

void convPrint(bool value) {
	uint8_t new_line[] = "\n";
	uint8_t * output = uint8Cat((uint8_t *)value, new_line);
	HAL_UART_Transmit(&huart1, output, strlen((const char *)output), 500);
}

void newLine() {
	HAL_UART_Transmit(&huart1, (uint8_t *)"\n", strlen((const char *)"\n"), 500);
}
