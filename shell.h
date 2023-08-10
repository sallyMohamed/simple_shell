#ifndef _SHELL_H_
#define _SHELL_H_

#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <string.h>
#include <sys/types.h>
#include <sys/wait.h>
#include <sys/stat.h>
#include <limits.h>
#include <fcntl.h>
#include <errno.h>

typedef struct passinform
{
	char *argument;
	char **argvactor;
	char *path;
	int argcounter;
	unsigned int line_counter;
	int error_num;
	int line_flag;
	char *filename;
	/*list_t *env;
	list_t *history;
	list_t *alias;*/
	char **environ;
	int env_changed;
	int status;

	char **cmd_buf; /* pointer to cmd ; chain buffer, for memory mangement */
	int cmd_buf_type; /* CMD_type ||, &&, ; */
	int readfiledis;
	int histcount;
} i_t;


void free_memory(void **ptr);

/* _atoiandexit.c */
int interactmode(i_t *);
int is_delimeter(char, char *);
int _isalphabetic(int);
int _atointeger(char *);



#endif
