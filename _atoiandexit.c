#include "shell.h"

/**
 * interactmode - returns true while interactive mode is on
 * @i: address
 *
 * Return: 1 interactive mode, 0 otherwise
 */
int interactmode(i_t *i)
{
	return (isatty(STDIN_FILENO) && i->readfiledis <= 2);
}
/**
 * is_delimeter - checksCharacter is a delimeter
 * @chr: chartocheck
 * @d: delimeter
 * Return: 1 if true, 0 if false
 */
int is_delimeter(char chr, char *d)
{
	while (*d)
		if (*d++ == chr)
			return (1);
	return (0);
}

/**
 *_isalphabetic - checksAlphabetic character
 *@ch: input character
 *Return: 1 for alphabetic, 0 otherwise
 */

int _isalphabetic(int ch)
{
	if ((ch >= 'a' && ch <= 'z') || (ch >= 'A' && ch <= 'Z'))
		return (1);
	else
		return (0);
}

/**
 *_atointeger - convertString to an integer
 *@string: string converted
 *Return: 0 if Nostring, else converted number
 */

int _atointeger(char *string)
{
	int c, s = 1, f = 0, out;
	unsigned int finalresult = 0;

	for (c = 0;  string[c] != '\0' && f != 2; c++)
	{
		if (string[c] == '-')
			s *= -1;

		if (string[c] >= '0' && string[c] <= '9')
		{
			f = 1;
			finalresult *= 10;
			finalresult += (string[c] - '0');
		}
		else if (f == 1)
			f = 2;
	}

	if (s == -1)
		out = -finalresult;
	else
		out = finalresult;

	return (out);
}
