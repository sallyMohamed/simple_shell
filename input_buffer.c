#include "shell.h"

/**
 * in_buffer - buffers commands
 * @i: structuralArgument
 * @buff: buffer
 * @len: length var
 *
 * Return: bytes
 */
ssize_t in_buffer(i_t *i, char **buff, size_t *len)
{
	ssize_t r = 0;
	size_t len_p = 0;

	if (!*len)
	{

		free(*buff);
		*buff = NULL;
		signal(SIGINT, sHandler);
#if USEE_GETLINE
		r = getl(buf, &len_p, stdin);
#else
		r = _getl(i, buff, &len_p);
#endif
		if (r > 0)
		{
			if ((*buff)[r - 1] == '\n')
			{
				(*buff)[r - 1] = '\0';
				r--;
			}
			i->line_flag = 1;
			 remo_comm(*buff);
			build_hlist(i, *buff, i->histcount++);

			{
				*len = r;
				i->cmd_buffer = buff;
			}
		}
	}
	return (r);
}

/**
 * getInput - line do the newline
 * @i: structuralArgument
 *
 * Return: byte
 */
ssize_t getInput(i_t *i)
{
	static char *buff;
	static size_t i2, j, len;
	ssize_t r = 0;
	char **buff_pio = &(i->argument), *pio;

	_putchar(BUFFER_FLUSH);
	r = in_buffer(i, &buff, &len);
	if (r == -1)
		return (-1);
	if (len)
	{
		j = i2;
		pio = buff + i2;

		chainCheck(i, buff, &j, i2, len);
		while (j < len)
		{
			if (isChain(i, buff, &j))
				break;
			j++;
		}

		i2 = j + 1;
		if (i2 >= len)
		{
			i2 = len = 0;
			i->cmd_buffer_type = CMD_NORMAL;
		}

		*buff_pio = pio;
		return (_stringlen(pio));
	}

	*buff_pio = buff;
	return (r);
}

/**
 * readBuffer - readsBuffer
 * @i: StructuralArgument
 * @buff: buffer
 * @c: size
 *
 * Return: r
 */
ssize_t readBuffer(i_t *i, char *buff, size_t *c)
{
	ssize_t r = 0;

	if (*c)
		return (0);
	r = read(i->readfiledis, buff, READ_BUFFERSIZE);
	if (r >= 0)
		*c = r;
	return (r);
}

/**
 * _getl - next line from STDIN
 * @i: structuralArgument
 * @pio: pointer
 * @length: length
 *
 * Return: s
 */
int _getl(i_t *i, char **pio, size_t *length)
{
	static char buff[READ_BUFFERSIZE];
	static size_t y, len;
	size_t k;
	ssize_t r = 0, s = 0;
	char *p = NULL, *new_p = NULL, *c;

	p = *pio;
	if (p && length)
		s = *length;
	if (y == len)
		y = len = 0;

	r = readBuffer(i, buff, &len);
	if (r == -1 || (r == 0 && len == 0))
		return (-1);

	c = _stringchar(buff + y, '\n');
	k = c ? 1 + (unsigned int)(c - buff) : len;
	new_p = _relocate(p, s, s ? s + k : k + 1);
	if (!new_p)
		return (p ? free(p), -1 : -1);

	if (s)
		_stringcat(new_p, buff + y, k - y);
	else
		_stringcopy(new_p, buff + y, k - y + 1);

	s += k - y;
	y = k;
	p = new_p;

	if (length)
		*length = s;
	*pio = p;
	return (s);
}

/**
 * sHandler - blocks
 * @sig_number: number
 *
 * Return: void
 */
void sHandler(__attribute__((unused))int sig_number)
{
	_puts("\n");
	_puts("$ ");
	_putchar(BUFFER_FLUSH);
}
