#include <stdio.h>
#include "shell.h"  /* Assuming shell.h is in the same directory as main.c */

/**
 * main - Entry point
 * Return: 1 is fail, 0 is success.
*/
int main(void)
{
int *myNumber = (int *)malloc(sizeof(int));  /* Allocate memory for an int */
if (myNumber == NULL)
{
printf("Memory allocation failed.\n");
return (1); /* Return an error code */
}
*myNumber = 42;  /* Assign a value to the allocated memory */
printf("Value before free: %d\n", *myNumber);
/* Free the allocated memory and set the pointer to NULL */
free_memory((void **)&myNumber);
/* Now, myNumber is NULL and should not be used */
printf("Value after free: %p\n", (void *)myNumber);
return (0);
}
