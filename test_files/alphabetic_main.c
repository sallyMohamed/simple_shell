#include "shell.h"

/**
 * main - check the code.
 *
 * Return: Always 0.
 */
int main(void)
{
    int r;

    r = _isalphabetic('H');
    _putchar(r + '0');
    r = _isalphabetic('o');
    _putchar(r + '0');
    r = _isalphabetic(108);
    _putchar(r + '0');
    r = _isalphabetic(';');
    _putchar(r + '0');
    _putchar('\n');
    return (0);
}
