#include "shell.h"

/**
 * _stringlen - function that returns the length of a string
 * @t: string
 * Return: length of string
 */
int _stringlen(char *t)
{
int j = 0;
if (!t)
return (0);
for (; *t; t++)
{
j++;
}
return (j);
}

/**
 * _stringcomp - gives lexicogarphic comparison of two strangs.
 * @t1: first strang
 * @t2: second strang
 * Return: (-) if t1 < t2, (+) if t1 > t2, zero if t1 == t2
 */
int _stringcomp(char *t1, char *t2)
{
while (*t1 && *t2)
{
if (*t1 != *t2)
return (*t1 - *t2);
t1++;
t2++;
}
if (*t1 == *t2)
return (0);
else
return (*t1 < *t2 ? -1 : 1);
}

/**
 * startWith - function that checks if needle starts with haystack
 * @hay: string
 * @need: substring to find
 * Return: address of next char of hay or NULL
 */
char *startWith(const char *hay, const char *need)
{
while (*need)
if (*need++ != *hay++)
return (NULL);
return ((char *)hay);
}

/**
 * _stringcat2 - concatenates two strings
 * @destion: destination buffer
 * @source: the source buffer
 * Return: pointer
 */
char *_stringcat2(char *destion, char *source)
{
char *ust = destion;
for (; *destion; destion++)
{
}
for (; *source; source++, destion++)
{
*destion = *source;
}
*destion = *source;
return (ust);
}
