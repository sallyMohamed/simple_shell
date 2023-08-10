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

<<<<<<< Updated upstream

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
=======
#define READ_BUF_SIZE 1024
#define WRITE_BUF_SIZE 1024
#define BUF_FLUSH -1

>>>>>>> Stashed changes
void free_memory(void **ptr);
void print_tab(char **tab);
int is_separator(char c);
int count_ws(char *str);
char **free_ws(char **ws, int w_count);
char **strtow(char *str);
char *_strcpy(char *destion,  char *source);
char *_strduplicate(char *str);
void _puts(char *str);
int _putchar(char c);

/* _atoiandexit.c */
int interactmode(i_t *);
int is_delimeter(char, char *);
int _isalphabetic(int);
int _atointeger(char *);



#endif
