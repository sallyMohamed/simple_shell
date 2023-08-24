#include "shell.h"

/**
 * _CDhistory - history list
 *
 * @i: StructureArguments. Used to maintain
 *
 *  Return: Always 0
 */
int _CDhistory(i_t *i)
{
	print_linkedlist(i->history);
	return (0);
}

/**
 * unsetAlias - sets alias to string
 * @i: parameter struct
 * @s: the string alias
 *
 * Return: 0 success, 1 error
 */
int unsetAlias(i_t *i, char *s)
{
char *pio, count;
int r;
pio = _stringchar(s, '=');
if (!pio)
return (1);
count = *pio;
*pio = 0;
r = _deletenodeatindex(&(i->aliasnode),
get_nodeindex(i->aliasnode, node_startWith(i->aliasnode, s, -1)));
*pio = count;
return (r);
}

/**
 * setAlias - sets alias
 * @i: structrualArgument
 * @s: stringAlias
 *
 * Return: 0 success, 1 error
 */
int setAlias(i_t *i, char *s)
{
	char *pio;

	pio = _stringchar(s, '=');
	if (!pio)
		return (1);
	if (!*++pio)
		return (unsetAlias(i, s));

	unsetAlias(i, s);
	return (addto_end(&(i->aliasnode), s, 0) == NULL);
}

/**
 * sayAlias - sayAlias string
 * @nod_e: the aliasNode
 * Return: Always 0 success, 1 error
 */
int sayAlias(list_str *nod_e)
{
char *pio = NULL, *aa = NULL;
if (nod_e)
{
pio = _stringchar(nod_e->string, '=');
for (aa = nod_e->string; aa <= pio; aa++)
_putchar(*aa);
_putchar('\'');
_puts(pio + 1);
_puts("'\n");
return (0);
}
return (1);
}

/**
 * _filealias - alias
 * @i: StructurArguments.
 *
 *  Return: Always 0
 */
int _filealias(i_t *i)
{
	int j = 0;
	char *pio = NULL;
	list_str *nod_e = NULL;

	if (i->argcounter == 1)
	{
		nod_e = i->aliasnode;
		while (nod_e)
		{
			sayAlias(nod_e);
			nod_e = nod_e->next;
		}
		return (0);
	}
	for (j = 1; i->argvactor[j]; j++)
	{
		pio = _stringchar(i->argvactor[j], '=');
		if (pio)
			setAlias(i, i->argvactor[j]);
		else
			sayAlias(node_startWith(i->aliasnode, i->argvactor[j], '='));
	}

	return (0);
}
