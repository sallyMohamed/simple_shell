#include "shell.h"

/**
 * reverse_string - function that reverse input string.
 * @str: string
*/

void reverse_string(char *str)
{
size_t length = strlen(str);
size_t i;
size_t j;
for (i = 0, j = length - 1; i < j; i++, j--)
{
char temp = str[i];
str[i] = str[j];
str[j] = temp;
}
}

/**
 * convert_number - function that convert numbers.
 * @number: number
 * @base: base
 * Return: result.
*/

char *convert_number(int number, int base)
{
char buffer[1024]; /* Assuming a maximum buffer size of 1024 */
int is_negative = 0;
int digit;
int index = 0;
char *result;
if (number == 0)
{
result = _strduplicate("0");
return (result);
}
if (number < 0 && base == 10)
{
is_negative = 1;
number = -number;
}
while (number > 0)
{
digit = number % base;
buffer[index++] = digit < 10 ? '0' + digit : 'A' + digit - 10;
number /= base;
}
if (is_negative)
buffer[index++] = '-';
buffer[index] = '\0';
/* Reverse the buffer to get the correct number representation */
reverse_string(buffer);
result = _strduplicate(buffer);
return (result);
}
