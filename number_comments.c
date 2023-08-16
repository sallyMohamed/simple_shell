#include "shell.h"

/**
 * _strErrortoi - String to nteger
 * @str: string converted
 * Return: 0 no number
 *       -1 on error
 */
int _strErrortoi(char *str)
{
	int j = 0;
	unsigned long int final_result = 0;

	if (*str == '+')
		str++;
	for (j = 0;  str[j] != '\0'; j++)
	{
		if (str[j] >= '0' && str[j] <= '9')
		{
			final_result *= 10;
			final_result += (str[j] - '0');
			if (final_result > INT_MAX)
				return (-1);
		}
		else
			return (-1);
	}
	return (final_result);
}

/**
 * say_error - printsError message
 * @i: StructrualArgument
 * @stri: string
 * Return: 0 no numbers
 *        -1 on error
 */
void say_error(i_t *i, char *stri)
{
	_inputputs(i->filename);
	_inputputs(": ");
	print_decimal(i->line_counter, STDERR_FILENO);
	_inputputs(": ");
	_inputputs(i->argvactor[0]);
	_inputputs(": ");
	_inputputs(stri);
}

/**
 * print_decimal - printsDecimal (base 10)
 * @integer: integer input
 * @fdis: filedescript
 *
 * Return: number of characters printed
 */
int print_decimal(int integer, int fdis)
{
	int (*__putchar)(char) = _putchar;
	int j, counter = 0;
	unsigned int _abs_, current;

	if (fdis == STDERR_FILENO)
		__putchar = _inputputchar;
	if (integer < 0)
	{
		_abs_ = -integer;
		__putchar('-');
		counter++;
	}
	else
		_abs_ = integer;
	current = _abs_;
	for (j = 1000000000; j > 1; j /= 10)
	{
		if (_abs_ / j)
		{
			__putchar('0' + current / j);
			counter++;
		}
		current %= j;
	}
	__putchar('0' + current);
	counter++;

	return (counter);
}

/**
 * convertNumber - convertFunctioN.
 * @n: number
 * @b: base
 * @f: flags
 *
 * Return: string CONVERTED
 */
char *convertNumber(long int n, int b, int f)
{
	static char *arr;
	static char b2[50];
	char s = 0;
	char *poi;
	unsigned long n2 = n;

	if (!(f & CONV_UNSIGN) && n < 0)
	{
		n2 = -n;
		s = '-';

	}
	arr = f & CONV_LOWCAS ? "0123456789abcdef" : "0123456789ABCDEF";
	poi = &b2[49];
	*poi = '\0';

	do	{
		*--poi = arr[n2 % b];
		n2 /= b;
	} while (n2 != 0);

	if (s)
		*--poi = s;
	return (poi);
}

/**
 * remo_comm - Replace '#' with '\0'
 * @buffer: addreString to modify
 *
 * Return: Always 0;
 */
void remo_comm(char *buffer)
{
	int c;

	for (c = 0; buffer[c] != '\0'; c++)
		if (buffer[c] == '#' && (!c || buffer[c - 1] == ' '))
		{
			buffer[c] = '\0';
			break;
		}
}
