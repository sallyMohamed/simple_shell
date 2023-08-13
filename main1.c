#include "shell.h"

/**
 * main - Entry point
 * Return: 0 is success.
*/

int main(void)
{
i_t i;
char *line = NULL;
size_t len = 0;
ssize_t nread;
environment_list(&i);
while (1)
{
if (interactmode(&i))
_inputputchar('$');
nread = getline(&line, &len, stdin);
if (nread == -1)
{
_inputputchar('\n');
break;
}
line[nread - 1] = '\0'; /* Removing the newline character */
if (_stringcomp(line, "exit") == 0)
break;
char **commands = strtow(line);
if (commands)
{
int status = execute_commands(&i, commands);
free_ws(commands);
if (status == -2)
break;
}
else
{
say_error(&i, "Failed to split the command line");
}
if (line)
{
free(line);
line = NULL;
}
}
if (line)
free(line);
return (0);
}
