#include "shell.h"
int is_separator(char c);
int count_ws(char *str);
char **free_ws(char **ws, int w_count);
/**
* strtow - Splits a string into words.
* @str: Input string.
* Return: Pointer to an array of strings (ws), or NULL if it fails.
*/
char **strtow(char *str)
{
char **ws;
int w_count = 0;
int w_index = 0;
int w_begin = 0;
int j;
if (str == NULL || *str == '\0')
return (NULL);
w_count = count_ws(str);
if (w_count == 0)
return (NULL);
ws = malloc((w_count + 1) * sizeof(char *));
if (ws == NULL)
return (NULL);
for (j = 0; str[j] != '\0'; j++)
{
if (is_separator(str[j]))
{
if (j > w_begin)
{
int w_length = j - w_begin;
ws[w_index] = malloc((w_length + 1) * sizeof(char));
if (ws[w_index] == NULL)
return (free_ws(ws, w_index));
strncpy(ws[w_index], str + w_begin, w_length);
ws[w_index][w_length] = '\0';
w_index++;
}
w_begin = j + 1;
}
}
if (j > w_begin)
{
int last_w_length = j - w_begin;
ws[w_index] = malloc((last_w_length + 1) * sizeof(char));
if (ws[w_index] == NULL)
return (free_ws(ws, w_index));
strncpy(ws[w_index], str + w_begin, last_w_length);
ws[w_index][last_w_length] = '\0';
w_index++;
}
ws[w_index] = NULL;
return (ws);
}
/**
* is_separator - Checks if a character is a separator (space).
* @c: Character to check.
* Return: 1 if it is a separator, 0 otherwise.
*/
int is_separator(char c)
{
return (c == ' ');
}
/**
* count_ws - Counts the number of words in a string.
* @str: Input string.
* Return: Number of words.
*/
int count_ws(char *str)
{
int count = 0;
int j;
if (!is_separator(str[0]) && str[0] != '\0')
count++;
for (j = 1; str[j] != '\0'; j++)
{
if (is_separator(str[j - 1]) && !is_separator(str[j]))
count++;
}
return (count);
}
/**
* free_ws - Frees the memory allocated for an array of words.
* @ws: Array of words.
* @w_count: Number of words in the array.
* Return: NULL.
*/
char **free_ws(char **ws, int w_count)
{
int j;
for (j = 0; j < w_count; j++)
free(ws[j]);
free(ws);
return (NULL);
}
