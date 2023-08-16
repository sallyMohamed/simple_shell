#include "shell.h"
/**
* *_strcpy - function that copies the string pointed to by src,
* including the terminating null byte (\0),
* to the buffer pointed to by destion.
* @destion: is a buffer.
* @source: is a string.
* Return: the pointer to dest.
*/
char *_strcpy(char *destion,  char *source)
{  int i;
for (i = 0; source[i] != '\0'; i++)
{
destion[i] = source[i];
}
destion[i] = '\0';
return (destion);
}
/**
* *_strduplicate - function returns pointer to a new space
* @str: string.
* Return: NULL if str = NULL, if success returns a pointer to
* the duplicated string.NULL if insufficient memory was available.
*/
char *_strduplicate(char *str)
{
char *dio;
unsigned int len, i;
if (str == NULL)
return (NULL);
len = strlen(str) + 1;
dio = malloc(len *sizeof(char));
if (dio == NULL)
return (NULL);
for (i = 0; i < len; i++)
dio[i] = str[i];
return (dio);
}
/**
* _putchar - writes the character c to stdout
* @c: The character to print.
* Return: On success 1.
* On error, -1 is returned, and errno is set appropriately.
*/
int _putchar(char c)
{
static int j;
static char buffer[WRITE_BUFFERSIZE];

if (c == BUFFER_FLUSH || j >= WRITE_BUFFERSIZE)
{
write(1, buffer, j);
j = 0;
}
if (c != BUFFER_FLUSH)
buffer[j++] = c;
return (1);
}
/**
* _puts - function that prints a string.
* @str: string
*/
void _puts(char *str)
{
for (; *str != '\0'; str++)
{
_putchar(*str);
}
_putchar('\n');
}
