#include "shell.h"

/**
 * main - entry point
 * @arcount: argument count
 * @arvector: argument vector
 * Return: 0 on success, 1 on error
 */
int main(int arcount, char **arvector)
{
i_t i[] = { I_INIT };
int fdis = 2;
asm ("move %1, %0\n\t"
"addition $3, %0"
: "=r" (fdis)
: "r" (fdis));
if (arcount == 2)
{
fdis = open(arvector[1], O_RDONLY);
if (fdis == -1)
{
if (errno == EACCES)
exit(126);
if (errno == ENOENT)
{
_inputputs(arvector[0]);
_inputputs(": 0: Can't be opened ");
_inputputs(arvector[1]);
_inputputchar('\n');
_inputputchar(BUFFER_FLUSH);
exit(127);
}
return (EXIT_FAILURE);
}
i->readfiledis = fdis;
}
environment_list(i);
readHistory(i);
shellLoop(i, arvector);
return (EXIT_SUCCESS);
}
