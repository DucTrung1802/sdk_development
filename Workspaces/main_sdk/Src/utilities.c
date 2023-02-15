#include "utilities.h"

// EXTERNAL FUNCTIONS
// =================================================================

uint8_t *uint8Cat(uint8_t *string_1, uint8_t *string_2)
{
    uint8_t *concatenated;
    size_t len1 = strlen((char *)string_1);
    size_t len2 = strlen((char *)string_2);

    // Allocate memory for the concatenated string
    concatenated = (uint8_t *)malloc(len1 + len2 + 1);
    if (concatenated == NULL)
    {
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

void convPrintUint8t(uint8_t *value)
{
    HAL_UART_Transmit(&huart1, (uint8_t *)value, strlen((const char *)value), 500);
}

void convPrintSrtring(const char *value)
{
    HAL_UART_Transmit(&huart1, (uint8_t *)value, strlen((const char *)value), 500);
}

void convPrintInt(int value)
{
    char buffer[15];
    itoa(value, buffer, 10);
    uint8_t terminate[] = "\0";
    uint8_t *output = uint8Cat((uint8_t *)buffer, terminate);
    HAL_UART_Transmit(&huart1, output, strlen((const char *)output), 500);
}

void convPrintFloat(float value, int digits)
{
    char buffer[20];
    ftoa(value, buffer, digits);
    HAL_UART_Transmit(&huart1, (uint8_t *)buffer, strlen((const char *)buffer), 500);
}

// =================================================================

// INTERNAL FUNCTIONS
// =================================================================

// Reverses a string 'str' of length 'len'
void reverse(char *str, int len)
{
    int i = 0, j = len - 1, temp;
    while (i < j)
    {
        temp = str[i];
        str[i] = str[j];
        str[j] = temp;
        i++;
        j--;
    }
}

// Converts a given integer x to string str[].
// d is the number of digits required in the output.
// If d is more than the number of digits in x,
// then 0s are added at the beginning.
int intToStr(int x, char str[], int d)
{
    int i = 0;
    while (x)
    {
        str[i++] = (x % 10) + '0';
        x = x / 10;
    }

    // If number of digits required is more, then
    // add 0s at the beginning
    while (i < d)
        str[i++] = '0';

    reverse(str, i);
    str[i] = '\0';
    return i;
}

// Converts a floating-point/double number to a string.
void ftoa(float n, char *res, int afterpoint)
{
    // Extract integer part
    int ipart = (int)n;

    // Extract floating part
    float fpart = n - (float)ipart;

    // convert integer part to string
    int i = intToStr(ipart, res, 0);

    // check for display option after point
    if (afterpoint != 0)
    {
        res[i] = '.'; // add dot

        // Get the value of fraction part upto given no.
        // of points after dot. The third parameter
        // is needed to handle cases like 233.007
        fpart = fpart * pow(10, afterpoint);

        intToStr((int)fpart, res + i + 1, afterpoint);
    }
}

// =================================================================
