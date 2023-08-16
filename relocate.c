#include "shell.h"

/**
 **_memoryset - puts a constant byte to memory
 *@c: pointer
 *@p: byte to fill
 *@e: amount of bytes
 *Return: pointer to the memory area
 */
char *_memoryset(char *c, char p, unsigned int e)
{
unsigned int j;
for (j = 0; j < e; j++)
c[j] = p;
return (c);
}

/**
 * F_Free - frees a string
 * @ee: string of strings
 */
void F_Free(char **ee)
{
char **g = ee;
if (!ee)
return;
for (; *g; g++)
{
free(*g);
}
free(ee);
}

/**
 * _relocate - reallocates amemory
 * @ppt: pointer
 * @old: byte size of previous block
 * @n_ew: byte size of new block
 * Return: pointer to da ol'block nameen.
 */
void *_relocate(void *ppt, unsigned int old, unsigned int n_ew)
{
char *o;
unsigned int i;
if (!ppt)
return (malloc(n_ew));
if (!n_ew)
return (free(ppt), NULL);
if (n_ew == old)
return (ppt);
o = malloc(n_ew);
if (!o)
return (NULL);
old = old < n_ew ? old : n_ew;
for (i = 0; i < old; i++)
{
o[i] = ((char *)ppt)[i];
}
free(ppt);
return (o);
}
