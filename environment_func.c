#include "shell.h"

/**
 * _environment - Environment
 * @i: StructurArguments
 *
 * Return: Always 0
 */
int _environment(i_t *i)
{
	say_stringlist(i->environ2);
	return (0);
}

/**
 * _envData - Environment variable
 * @i: StructurArguments
 * @env_name: env varAIABLE
 *
 * Return: the value
 */
char *_envData(i_t *i, const char *env_name)
{
	list_str *nod_e = i->environ2;
	char *pio;

	while (nod_e)
	{
		pio = startWith(nod_e->string, env_name);
		if (pio && *pio)
			return (pio);
		nod_e = nod_e->next;
	}
	return (NULL);
}

/**
 * _setenvironment - InitializEnvironment variable
 *
 * @i: StructurArgumentS
 *
 *  Return: Always 0
 */
int _setenvironment(i_t *i)
{
	if (i->argcounter != 3)
	{
		_inputputs("Error in arguements number\n");
		return (1);
	}
	if (_setEnvo(i, i->argvactor[1], i->argvactor[2]))
		return (0);
	return (1);
}

/**
 * _unsetenvironment - RemoveEnvoVariable
 * @i: StructurArguments
 *  Return: Always 0
 */
int _unsetenvironment(i_t *i)
{
	int c;

	if (i->argcounter == 1)
	{
		_inputputs("little arguements.\n");
		return (1);
	}
	for (c = 1; c <= i->argcounter; c++)
		_unsetEnvo(i, i->argvactor[c]);

	return (0);
}

/**
 * environment_list - env linked list
 * @i: StructurArguments.
 * Return: Always 0
 */
int environment_list(i_t *i)
{
	list_str *nod_e = NULL;
	size_t n;

	for (n = 0; environ[n]; n++)
		addto_end(&nod_e, environ[n], 0);
	i->environ2 = nod_e;
	return (0);
}
