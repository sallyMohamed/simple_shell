#include "shell.h"
/**
 * free_memory - frees a pointer allocated memory and NULLs the address.
 * @ptr: pointer to free
 * Return: 1 if memory freed, 0 if not.
 */
int free_memory(void **ptr)
{
if (ptr && *ptr)
{
free(*ptr);
*ptr = NULL;
return (1);
}
return (0);
}
