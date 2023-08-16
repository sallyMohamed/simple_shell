#include "shell.h"

/**
 *_inputputs - Input string
 * @string: string WILL printed
 *
 * Return: Nothing
 */
void _inputputs(char *string)
{
	int c = 0;

	if (!string)
		return;
	while (string[c] != '\0')
	{
		_inputputchar(string[c]);
		c++;
	}
}

/**
 * _inputputchar - writes the character c to stderr
 * @ch: character 
 *
 * Return: On success 1.
 * On error, -1 
 */
int _inputputchar(char ch)
{
	static int j;
	static char buffer[WRITE_BUFFERSIZE];

	if (ch == BUFFER_FLUSH || j >= WRITE_BUFFERSIZE)
	{
		write(2, buffer, j);
		j = 0;
	}
	if (ch != BUFFER_FLUSH)
		buffer[j++] = ch;
	return (1);
}

/**
 * _putfdis - character c to given fdisc
 * @ch: character to print
 * @fdis: filedescriptor
 *
 * Return: On success 1.
 * On error, -1 is returned.
 */
int _putfdis(char ch, int fdis)
{
	static int j;
	static char buffer[WRITE_BUFFERSIZE];

	if (ch == BUFFER_FLUSH || j >= WRITE_BUFFERSIZE)
	{
		write(fdis, buffer, j);
		j = 0;
	}
	if (ch != BUFFER_FLUSH)
		buffer[j++] = ch;
	return (1);
}

/**
 *_putsfdis - input string
 * @string: string  printed
 * @fdis: filedescriptor to write to
 *
 * Return: number chars put
 */
int _putsfdis(char *string, int fdis)
{
	int j = 0;

	if (!string)
		return (0);
	while (*string)
	{
		j += _putfdis(*string++, fdis);
	}
	return (j);
}
