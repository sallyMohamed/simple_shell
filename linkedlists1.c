#include "shell.h"

/**
 * linkedlist_length - determines length of linked list
 * @e: pointer
 * Return: size of list
 */
size_t linkedlist_length(const list_str *e)
{
size_t j;
for (j = 0; e != NULL; e = e->next, j++)
{
}
return (j);
}

/**
 * **list_TOstr - returns an array of strings
 * @h: pointer
 * Return: array of strings
 */
char **list_TOstr(list_str *h)
{
list_str *nod_e = h;
size_t i = linkedlist_length(h), j;
char **strings;
char *string;
if (!h || !i)
return (NULL);
strings = malloc(sizeof(char *) * (i + 1));
if (!strings)
return (NULL);
for (i = 0; nod_e; nod_e = nod_e->next, i++)
{
string = malloc(_stringlen(nod_e->string) + 1);
if (!string)
{
for (j = 0; j < i; j++)
free(strings[j]);
free(strings);
return (NULL);
}
string = _strcpy(string, nod_e->string);
strings[i] = string;
}
strings[i] = NULL;
return (strings);
}

/**
 * print_linkedlist - prints all elements
 * @e: pointer
 * Return: size of list
 */
size_t print_linkedlist(const list_str *e)
{
size_t i;
for (i = 0; e != NULL; e = e->next, i++)
{
_puts(convertNumber(e->number, 10, 0));
_putchar(':');
_putchar(' ');
_puts(e->string ? e->string : "(nil)");
_puts("\n");
}
return (i);
}

/**
 * node_startWith - returns node
 * @nod_e: pointer
 * @last: string
 * @k: the character after last to match
 * Return: match node or null
 */
list_str *node_startWith(list_str *nod_e, char *last, char k)
{
char *y = NULL;
for (; nod_e != NULL; nod_e = nod_e->next)
{
y = startWith(nod_e->string, last);
if (y && ((k == -1) || (*y == k)))
return (nod_e);
}
return (NULL);
}

/**
 * get_nodeindex - get index in a node
 * @h: pointer
 * @nod_e: pointer
 * Return: index of node or -1
 */
ssize_t get_nodeindex(list_str *h, list_str *nod_e)
{
size_t j = 0;
for (; h != NULL; h = h->next, j++)
{
if (h == nod_e)
return (j);
}
return (-1);
}
