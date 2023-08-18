#include "shell.h"

/**
 * isChain - function tests if char is a chain delimeter
 * @i: struct
 * @buffer: buffer
 * @o: address
 * Return: 1 if chain delimeter, 0 otherwise
 */
int isChain(i_t *i, char *buffer, size_t *o)
{
size_t e = *o;
if (buffer[e] == '|' && buffer[e + 1] == '|')
{
buffer[e] = 0;
e++;
i->cmd_buffer_type = EM_OR;
}
else if (buffer[e] == '&' && buffer[e + 1] == '&')
{
buffer[e] = 0;
e++;
i->cmd_buffer_type = EM_AND;
}
else if (buffer[e] == ';') /* find end of the command */
{
buffer[e] = 0; /* replace ; with null */
i->cmd_buffer_type = EM_CHAIN;
}
else
return (0);
*o = e;
return (1);
}

/**
 * chainCheck - function that check we should continue chaining or not.
 * @i: struct
 * @buffer: buffer
 * @o: address
 * @j: starting position
 * @length: length of buffer
 * Return: Void
 */
void chainCheck(i_t *i, char *buffer, size_t *o, size_t j, size_t length)
{
size_t e = *o;
if (i->cmd_buffer_type == EM_AND)
{
if (i->status)
{
buffer[j] = 0;
e = length;
}
}
if (i->cmd_buffer_type == EM_OR)
{
if (!i->status)
{
buffer[j] = 0;
e = length;
}
}
*o = e;
}

/**
 * replaceAlias - function replaces an aliases in string
 * @i: struct
 * Return: 1 if replaced, 0 otherwise
 */
int replaceAlias(i_t *i)
{
int e;
list_str *nod_e;
char *o;
for (e = 0; e < 10; e++)
{
nod_e = node_startWith(i->aliasnode, i->argvactor[0], '=');
if (!nod_e)
return (0);
free(i->argvactor[0]);
o = _stringchar(nod_e->string, '=');
if (!o)
return (0);
o = _strduplicate(o + 1);
if (!o)
return (0);
i->argvactor[0] = o;
}
return (1);
}

/**
 * replaceVariables - function replaces variables in string
 * @i: struct
 * Return: 1 if replaced, 0 otherwise
 */
int replaceVariables(i_t *i)
{
int j = 0;
list_str *nod_e;
for (j = 0; i->argvactor[j]; j++)
{
if (i->argvactor[j][0] != '$' || !i->argvactor[j][1])
continue;
if (!_stringcomp(i->argvactor[j], "$?"))
{
replaceStr(&(i->argvactor[j]),
_strduplicate(covertNumber(i->status, 10, 0)));
continue;
}
if (!_stringcomp(i->argvactor[j], "$$"))
{
replaceStr(&(i->argvactor[j]),
_strduplicate(covertNumber(getpid(), 10, 0)));
continue;
}
nod_e = node_startWith(i->environ2, &i->argvactor[j][1], '=');
if (nod_e)
{
replaceStr(&(i->argvactor[j]),
_strduplicate(_stringchar(nod_e->string, '=') + 1));
continue;
}
replaceStr(&i->argvactor[j], _strduplicate(""));
}
return (0);
}

/**
 * replaceStr - function that replaces string
 * @old_str: address
 * @new_str: address
 * Return: 1 if replaced, 0 otherwise
 */
int replaceStr(char **old_str, char *new_str)
{
free(*old_str);
*old_str = new_str;
return (1);
}
