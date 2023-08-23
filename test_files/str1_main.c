#include "shell.h"
/**
 * main - Entry point.
 * Return: 1 is fail, 0 is success.
*/
int main(void)
{
char input[] = "Hello, World!";
char *duplicate;
char copy[50];
_puts("Original String:");
_puts(input);
duplicate = _strdup(input);
if (duplicate == NULL)
{
_puts("Memory allocation failed");
return (1);
}
_puts("Duplicated String:");
_puts(duplicate);
_puts("Copied String:");
_strcpy(copy, input);
_puts(copy);
_puts("Printing with _putchar:");
_putchar('H');
_putchar('e');
_putchar('l');
_putchar('l');
_putchar('o');
_putchar(',');
_putchar(' ');
_putchar('W');
_putchar('o');
_putchar('r');
_putchar('l');
_putchar('d');
_putchar('!');
_putchar('\n');
return (0);
}
