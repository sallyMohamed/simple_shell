#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <sys/types.h>
#include <sys/stat.h>
#include "shell.h"

int itis_cmd(i_t *i, char *pathway);
char *duplicate_chars(char *pathwaystr, int begin, int stophere);
char *findthe_path(i_t *i, char *pathwaystr, char *cmd);


/**
 * main - Entry point
 * Return: Always 0 (Success)
 */
int main(void)
{
i_t i; /* Define the structure i_t */
char *pathwaystr = "/usr/bin:/bin:/usr/local/bin"; /* Example PATH */
char *cmd = "ls"; /* Example command to find */
char *full_path = findthe_path(&i, pathwaystr, cmd);
if (full_path)
{
printf("Found executable at: %s\n", full_path);
}
else
{
printf("Executable not found in PATH.\n");
}
return (0);
}
