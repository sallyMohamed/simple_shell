#include "shell.h"
/**
 * free_memory - frees allocated memory and NULLs the address.
 * @ptr: pointer to free
 */
void free_memory(void **ptr)
{
if (ptr && *ptr)
{
free(*ptr);
*ptr = NULL;
}
}
