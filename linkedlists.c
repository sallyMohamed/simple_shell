#include "shell.h"

/**
 * *addto_start - adds a node
 * @h: address of pointer
 * @string: string
 * @number: node index
 * Return: size of list
 */
list_str *addto_start(list_str **h, const char *string, int number)
{
list_str *new_h;
if (!h)
return (NULL);
new_h = malloc(sizeof(list_str));
if (!new_h)
return (NULL);
_memoryset((void *)new_h, 0, sizeof(list_str));
new_h->number = number;
if (string)
{
new_h->string = _strduplicate(string);
if (!new_h->string)
{
free(new_h);
return (NULL);
}
}
new_h->next = *h;
*h = new_h;
return (new_h);
}

/**
 * *addto_end - adds a node
 * @h: address of pointer
 * @string: string
 * @number: node index
 * Return: size of list
 */
list_str *addto_end(list_str **h, const char *string, int number)
{
list_str *newnod_e, *nod_e;
if (!h)
return (NULL);
nod_e = *h;
newnod_e = malloc(sizeof(list_str));
if (!newnod_e)
return (NULL);
_memoryset((void *)newnod_e, 0, sizeof(list_str));
newnod_e->number = number;
if (string)
{
newnod_e->string = _strduplicate(string);
if (!newnod_e->string)
{
free(newnod_e);
return (NULL);
}
}
if (nod_e)
{
while (nod_e->next)
nod_e = nod_e->next;
nod_e->next = newnod_e;
}
else
*h = newnod_e;
return (newnod_e);
}

/**
 * say_stringlist - prints only the str element
 * @h: pointer
 * Return: size of list
 */
size_t say_stringlist(const list_str *h)
{
size_t j = 0;
while (h)
{
_puts(h->string ? h->string : "(nil)");
_puts("\n");
h = h->next;
j++;
}
return (j);
}

/**
 * _deletenodeatindex - deletes node at index
 * @h: address of pointer
 * @inx: index to  delete
 * Return: 1 on success, 0 on failure
 */
int _deletenodeatindex(list_str **h, unsigned int inx)
{
list_str *nod_e, *prevnod_e;
unsigned int j = 0;
if (!h || !*h)
return (0);
if (!inx)
{
nod_e = *h;
*h = (*h)->next;
free(nod_e->string);
free(nod_e);
return (1);
}
nod_e = *h;
while (nod_e)
{
if (j == inx)
{
prevnod_e->next = nod_e->next;
free(nod_e->string);
free(nod_e);
return (1);
}
j++;
prevnod_e = nod_e;
nod_e = nod_e->next;
}
return (0);
}

/**
 * _freelist - frees a list
 * @h_ptr: address
 * Return: void
 */
void _freelist(list_str **h_ptr)
{
list_str *nod_e, *nextnod_e, *h;
if (!h_ptr || !*h_ptr)
return;
h = *h_ptr;
nod_e = h;
while (nod_e)
{
nextnod_e = nod_e->next;
free(nod_e->string);
free(nod_e);
nod_e = nextnod_e;
}
*h_ptr = NULL;
}
