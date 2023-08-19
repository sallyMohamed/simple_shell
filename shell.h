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
#include <stddef.h>


/* for command chaining */
#define EM_OR		1
#define EM_AND          2
#define EM_CHAIN	3



/* number_comments.c */
#define CONV_LOWCAS	1
#define CONV_UNSIGN	2

#define USEE_GETLINE 0
#define USEE_STRTOK 0

#define HISTORY_FILE    ".simple_shell_history"
#define HISTORY_MAX     4096

/* _memory.c */
#define READ_BUFFERSIZE 1024
#define WRITE_BUFFERSIZE 1024
#define BUFFER_FLUSH -1


#define CMD_NORMAL	0
#define CMD_OR		1
#define CMD_AND		2
#define CMD_CHAIN	3



#define I_INIT \
{NULL, NULL, NULL, 0, 0, 0, 0, NULL, NULL, NULL, NULL, NULL, 0, 0, NULL, \
	0, 0, 0}

extern char **environ;

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

typedef struct exit_changD
{
	char *type;
	int (*func)(i_t *);
} exit_changD_table;


void free_memory(void **);
void print_tab(char **);
int is_separator(char);
int count_ws(char *);
char **free_ws(char **, int);
char **strtow(char *);
char *_strcpy(char *,  char *);
char *_strduplicate(char *);
void _puts(char *);
int _putchar(char);

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
char *covertNumber(long int, int, int);
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


/* linkedlists.c */
list_str *addto_end(list_str **, const char *, int);
size_t say_stringlist(const list_str *);
list_str *addto_start(list_str **h, const char *strg, int number);
void _freelist(list_str **h_ptr);
int _deletenodeatindex(list_str **h, unsigned int inx);

/* relocate.c */
char *_memoryset(char *c, char p, unsigned int e);
void F_Free(char **ee);
void *_relocate(void *ppt, unsigned int old, unsigned int n_ew);

/* str.c */
int _stringcomp(char *, char *);
char *startWith(const char *, const char *);
int _stringlen(char *);
char *_stringcat2(char *, char *);

/* parserpath.c */
int it_cmd(i_t *, char *);
char *duplicate_chars(char *, int, int);
char *findthe_path(i_t *, char *, char *);

/* linkedlists1.c */

size_t linkedlist_length(const list_str *);
char **list_TOstr(list_str *);
size_t print_linkedlist(const list_str *);
list_str *node_startWith(list_str *, char *, char );
ssize_t get_nodeindex(list_str *, list_str *);

/**convert_number**/
char *convert_number(int number, int base);
void reverse_string(char *str);

/* variables.c */
int isChain(i_t *i, char *buffer, size_t *o);
void chainCheck(i_t *i, char *buffer, size_t *o, size_t j, size_t length);
int replaceAlias(i_t *i);
int replaceVariables(i_t *i);
int replaceStr(char **old_str, char *new_str);

/*shellMainloop.c */
int shellLoop(i_t *i, char **arvector);
int find_exit_changD(i_t *i);
void findCmd(i_t *i);
void forkCmd(i_t *i);


/* HIS.C */

char *getHisfile(i_t *i);
int writeHistory(i_t *i);
int readHistory(i_t *i);
int build_hlist(i_t *i, char *buff, int linec);
int renumberHis(i_t *i);




/* alias_history*/
int _CDhistory(i_t *);
int _filealias(i_t *);

/* input_buffer.c */
ssize_t getInput(i_t *);
int _getl(i_t *, char **, size_t *);
void sHandler(int);

/* info.c */
void clear_i(i_t *);
void set_i(i_t *, char **);
void free_i(i_t *, int);

#endif
