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
