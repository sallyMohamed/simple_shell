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


/*int _putchar(char c);*/

typedef struct liststring
{
	int number;
	char *string;
	struct liststring *next;
} list_str;


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
	list_str *environ;
	list_str *history;
	list_str *aliasnode;
	char **environ;
	int environ_changed;
	int status;

	char **cmd_buffer; /* memory mangement */
	int cmd_buffer_type; /* CMD_type_totest ||, &&, ; */
	int readfiledis;
	int histcount;
} i_t;

/* _memory.c */
void free_memory(void **ptr);

/* _atoiandexit.c */
int interactmode(i_t *);
int is_delimeter(char, char *);
int _isalphabetic(int);
int _atointeger(char *);



#endif
