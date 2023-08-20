#include "shell.h"

/**
 * **string_tow - splits a string into words.
 * @string: string
 * @e: delimeter string
 * Return: a pointer to an array of strings, or NULL on failure
 */

char **string_tow(char *string, char *e)
{
int o, r, x, n, numberofwords = 0;
char **d;
if (string == NULL || string[0] == 0)
return (NULL);
if (!e)
e = " ";
for (o = 0; string[o] != '\0'; o++)
if (!is_delimeter(string[o], e) && (is_delimeter(string[o + 1], e) ||
!string[o + 1]))
numberofwords++;
if (numberofwords == 0)
return (NULL);
d = malloc((1 + numberofwords) *sizeof(char *));
if (!d)
return (NULL);
for (o = 0, r = 0; r < numberofwords; r++)
{
while (is_delimeter(string[o], e))
o++;
x = 0;
while (!is_delimeter(string[o + x], e) && string[o + x])
x++;
d[r] = malloc((x + 1) * sizeof(char));
if (!d[r])
{
for (x = 0; x < r; x++)
free(d[x]);
free(d);
return (NULL);
}
for (n = 0; n < x; n++)
d[r][n] = string[o++];
d[r][n] = 0;
}
d[r] = NULL;
return (d);
}

/**
 * **string_tow2 - function that splits a string into words
 * @string: string
 * @e: delimeter
 * Return: a pointer to an array of strings, or NULL on failure
 */
char **string_tow2(char *string, char e)
{
int o, r, x, n, numberofwords = 0;
char **d;
if (string == NULL || string[0] == 0)
return (NULL);
for (o = 0; string[o] != '\0'; o++)
if ((string[o] != e && string[o + 1] == e) ||
(string[o] != e && !string[o + 1]) || string[o + 1] == e)
numberofwords++;
if (numberofwords == 0)
return (NULL);
d = malloc((1 + numberofwords) *sizeof(char *));
if (!d)
return (NULL);
for (o = 0, r = 0; r < numberofwords; r++)
{
while (string[o] == e && string[o] != e)
o++;
x = 0;
while (string[o + x] != e && string[o + x] && string[o + x] != e)
x++;
d[r] = malloc((x + 1) * sizeof(char));
if (!d[r])
{
for (x = 0; x < r; x++)
free(d[x]);
free(d);
return (NULL);
}
for (n = 0; n < x; n++)
d[r][n] = string[o++];
d[r][n] = 0;
}
d[r] = NULL;
return (d);
}
