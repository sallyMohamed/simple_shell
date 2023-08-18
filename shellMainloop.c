#include "shell.h"

/**
 * shellLoop - main loop of the shell
 * @i: parameter
 * @arvector: argument vector
 * Return: 0 on success, 1 on error, or error code
 */
int shellLoop(i_t *i, char **arvector)
{
ssize_t e = 0;
int built_in_ret = 0;
while (e != -1 && built_in_ret != -2)
{
clear_i(i);
if (interactmode(i))
_puts("$ ");
_inputputchar(BUFFER_FLUSH);
e = getInput(i);
if (e != -1)
{
set_i(i, arvector);
built_in_ret = findBuiltin(i);
if (built_in_ret == -1)
findCmd(i);
}
else if (interactmode(i))
_putchar('\n');
free_i(i, 0);
}
writeHistory(i);
free_i(i, 1);
if (!interactmode(i) && i->status)
exit(i->status);
if (built_in_ret == -2)
{
if (i->error_num == -1)
exit(i->status);
exit(i->error_num);
}
return (built_in_ret);
}

/**
 * find_exit_changD - function that finds a exit_changD command
 * @i: parameter
 * Return: -1 if exit_changD not found,
 *	    0 if exit_changD executed successfully,
 *	    1 if exit_changD found but not successful,
 *	   -2 if exit_changD signals exit()
 */
int find_exit_changD(i_t *i)
{
int j, exit_changD_ret = -1;
exit_changD_table exitchangDtbl[] = {
{"exit", _exitCmd},
{"env", _environment},
{"help", _CDhelp},
{"history", _CDhistory},
{"setenv", _setenvironment},
{"unsetenv", _unsetenvironment},
{"cd", _changdir},
{"alias", _filealias},
{NULL, NULL}
};
for (j = 0; exitchangDtbl[j].type; j++)
if (_stringcomp(i->argvactor[0], exitchangDtbl[j].type) == 0)
{
i->line_counter++;
exit_changD_ret = exitchangDtbl[j].func(i);
break;
}
return (exit_changD_ret);
}

/**
 * findCmd - function that finds a command in PATH
 * @i: the parameter
 * Return: void
 */
void findCmd(i_t *i)
{
char *path = NULL;
int e, x;
i->path = i->argvactor[0];
if (i->line_flag == 1)
{
i->line_counter++;
i->line_flag = 0;
}
for (e = 0, x = 0; i->argument[e]; e++)
if (!is_delimeter(i->argument[e], " \t\n"))
x++;
if (!x)
return;
path = findthe_path(i, _envData(i, "PATH="), i->argvactor[0]);
if (path)
{
i->path = path;
forkCmd(i);
}
else
{
if ((interactmode(i) || _envData(i, "PATH=")
|| i->argvactor[0][0] == '/') && it_cmd(i, i->argvactor[0]))
forkCmd(i);
else if (*(i->argument) != '\n')
{
i->status = 127;
say_error(i, "not found\n");
}
}
}

/**
 * forkCmd - function that forks a thread
 * @i: parameter
 * Return: void
 */
void forkCmd(i_t *i)
{
pid_t small_pid;
small_pid = fork();
if (small_pid == -1)
{
perror("Error:");
return;
}
if (small_pid == 0)
{
if (execve(i->path, i->argvactor, getEnvo(i)) == -1)
{
free_i(i, 1);
if (errno == EACCES)
exit(126);
exit(1);
}
}
else
{
wait(&(i->status));
if (WIFEXITED(i->status))
{
i->status = WEXITSTATUS(i->status);
if (i->status == 126)
say_error(i, "Permission denied\n");
}
}
}
