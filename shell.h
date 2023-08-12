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


#define I_INIT \
{NULL, NULL, NULL, 0, 0, 0, 0, NULL, NULL, NULL, NULL, NULL, 0, 0, NULL, \
	0, 0, 0}

typedef struct liststring
{
	int number;
	char *string;
	struct liststring *next;
} list_str;

typedef struct exit_changD
{
	char *type;
	int (*func)(i_t *);
} exit_changD_table;


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
	list_str *environ2;
	list_str *history;
	list_str *aliasnode;
	char **environ;
	int environ_changed;
	int status;

	char **cmd_buffer; 
	int cmd_buffer_type;
	int readfiledis;
	int histcount;
} i_t;

/* _memory.c */
#define READ_BUF_SIZE 1024
#define WRITE_BUF_SIZE 1024
#define BUF_FLUSH -1


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


/*string_function.c*/
char *_stringcopy(char *, char *, int);
char *_stringcat(char *, char *, int);
char *_stringchar(char *, char);

/* exit_changD.c */
int _exitCmd(i_t *);  
int _changdir(i_t *);
int _CDhelp(i_t *);


/*number_comments.c*/

int _strErrortoi(char *);

void say_error(i_t *, char *);

int print_decimal(int, int);
char *covert_number(long int, int, int);
void remo_comm(char *);



/* printString.c */
void _inputputs(char *);
int _inputputchar(char);

int _putfdis(char , int );
int _putsfdis(char *, int );

/* environment_func.c */
char *_envData(i_t *, const char *);
int _environment(i_t *);
int _setenvironment(i_t *);
int _unsetenvironment(i_t *);
int environment_list(i_t *);

/* environment_func2.c */
char **getEnvo(i_t *);
int _unsetEnvo(i_t *, char *);
int _setEnvo(i_t *, char *, char *);


/* lists.c */

list_str *addto_end(list_str **, const char *, int);
size_t say_stringlist(const list_str *);


/* string.c */

int _stringcomp(char *, char *);
char *startWith(const char *, const char *);

#endif
