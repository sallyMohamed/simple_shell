#include "shell.h"

/**
 * clear_i - initializes i_t
 * @i: structrualArgument
 */
void clear_i(i_t *i)
{
	i->argument = NULL;
	i->argvactor = NULL;
	i->path = NULL;
	i->argcounter = 0;
}

/**
 * set_i - initializes i_t struct
 * @i: structuralArgument
 * @avactor: vector
 */
void set_i(i_t *i, char **avactor)
{
	int c = 0;

	i->filename = avactor[0];
	if (i->argument)
	{
		i->argvactor = strtow(i->argument, " \t");
		if (!i->argvactor)
		{

			i->argvactor = malloc(sizeof(char *) * 2);
			if (i->argvactor)
			{
				i->argvactor[0] = _strduplicate(i->argument);
				i->argvactor[1] = NULL;
			}
		}
		for (c = 0; i->argvactor && i->argvactor[c]; c++)
			;
		i->argcounter = c;

		replaceAlias(i);
		replaceVariables(i);
	}
}

/**
 * free_i - frees i_t
 * @i: struct address
 * @a: all fields
 */
void free_i(i_t *i, int a)
{
	F_Free(i->argvactor);
	i->argvactor = NULL;
	i->path = NULL;
	if (a)
	{
		if (!i->cmd_buffer)
			free(i->argument);
		if (i->environ2)
			_freelist(&(i->environ2));
		if (i->history)
			_freelist(&(i->history));
		if (i->aliasnode)
			_freelist(&(i->aliasnode));
		F_Free(i->environ);
			i->environ = NULL;
		free_memory((void **)i->cmd_buffer);
		if (i->readfiledis > 2)
			close(i->readfiledis);
		_putchar(BUFFER_FLUSH);
	}
}
