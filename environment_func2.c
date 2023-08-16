#include "shell.h"

/**
 * **getEnvo - returns the string array copy of our environ
 * @i: StructureArguments.
 *
 * Return: Always 0
 */
char **getEnvo(i_t *i)
{
	if (!i->environ || i->environ_changed)
	{
		i->environ = list_TOstr(i->environ2);
		i->environ_changed = 0;
	}

	return (i->environ);
}

/**
 * _unsetEnvo - RemovEnvironment variable
 * @i: StructureArguments.
 *
 *  Return: 1 delete, 0 else
 * @variable: envVar String
 */
int _unsetEnvo(i_t *i, char *variable)
{
	list_t *nod_e = i->environ2;
	size_t c = 0;
	char *pio;

	if (!nod_e || !variable)
		return (0);

	while (nod_e)
	{
		pio = startWith(nod_e->string, variable);
		if (pio && *pio == '=')
		{
			i->environ_changed = _deletenodeatindex(&(i->environ2), c);
			c = 0;
			nod_e = i->environ2;
			continue;
		}
		nod_e = nod_e->next;
		c++;
	}
	return (i->environ_changed);
}

/**
 * _setEnvo - Environment variable,
 *
 * @i: StructureArguments.
 *
 * @variable: stringEnvVar
 * @vlu: value
 *  Return: Always 0
 */
int _setEnvo(i_t *i, char *variable, char *vlu)
{
	char *buffer = NULL;
	list_t *nod_e;
	char *pio;

	if (!variable || !vlu)
		return (0);
	buffer = malloc(_stringlen(variable) + _stringlen(vlu) + 2);
	if (!buffer)
		return (1);
	__stringcopy(buffer, variable);
	_stringcat2(buffer, "=");
	_stringcat2(buffer, vlu);
	nod_e = i->environ2;
	while (nod_e)
	{
		pio = startWith(nod_e->string, variable);
		if (pio && *pio == '=')
		{
			free(nod_e->string);
			nod_e->string = buffer;
			i->environ_changed = 1;
			return (0);
		}
		nod_e = nod_e->next;
	}
	addto_end(&(i->environ2), buffer, 0);
	free(buffer);
	i->environ_changed = 1;
	return (0);
}
