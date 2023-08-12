#include "shell.h"

/**
 * it_cmd - Check if a file is an executable command
 * @i: The info struct
 * @pathway: the Path
 * Return: 1 if true, 0 otherwise
 */

int it_cmd(i_t *i, char *pathway)
{
struct stat s;
(void)i;
if (!pathway || stat(pathway, &s))
return (0);
if (s.st_mode & S_IFREG)
{
return (1);
}
return (0);
}

/**
 * duplicate_chars - Duplicates characters
 * @pathwaystr: PATH string
 * @begin: Starting index
 * @stophere: Stopping index
 * Return: Pointer to duplicated string
 */
char *duplicate_chars(char *pathwaystr, int begin, int stophere)
{
static char buffer[1024];
int j = 0; /* i*/
int x = 0; /* k */
for (x = 0, j = begin; j < stophere; j++)
if (pathwaystr[j] != ':')
buffer[x++] = pathwaystr[j];
buffer[x] = 0;
return (buffer);
}

/**
 * findthe_path - Finds cmd in the PATH
 * @i: The i struct (not used here)
 * @pathwaystr: PATH string
 * @cd: The cmd to find
 * Return: Full path of cmd if found, or NULL
 */
char *findthe_path(i_t *i, char *pathwaystr, char *cd)
{
int j = 0, currsol_pos = 0;
char *pathway;
if (!pathwaystr)
return (NULL);
if ((_stringlen(cd) > 2) && startWith(cd, "./"))
{
if (it_cmd(i, cd))
return (cd);
}
while (1)
{
if (!pathwaystr[j] || pathwaystr[j] == ':')
{
pathway = duplicate_chars(pathwaystr, currsol_pos, j);
if (!*pathway)
_stringcat2(pathway, cd);
else
{
_stringcat2(pathway, "/");
_stringcat2(pathway, cd);
}
if (it_cmd(i, pathway))
return (pathway);
if (!pathwaystr[j])
break;
currsol_pos = j; /* Adjusted to skip ':' */
}
j++;
}
return (NULL);
}
