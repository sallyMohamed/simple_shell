#include "shell.h"
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int main(void)
{
    /* Declare variables */
    char arr[10];
    unsigned int i;
    char *str1 = "Hello, World!";
    char *str2 = "GPT-3.5";
    char **stringArray;
    char *oldBlock;
    char *newBlock;

    /* Example usage of _memoryset */
    _memoryset(arr, 'A', sizeof(arr));
    for (i = 0; i < sizeof(arr); i++)
    {
        printf("%c ", arr[i]);
    }
    printf("\n");

    /* Example usage of F_Free */
    stringArray = malloc(sizeof(char *) * 3);
    if (!stringArray)
        return 1;
    stringArray[0] = strdup(str1);
    stringArray[1] = strdup(str2);
    stringArray[2] = NULL;
    F_Free(stringArray);

    /* Example usage of _relocate */
    oldBlock = strdup("Old Block");
    if (!oldBlock)
        return 1;
    newBlock = _relocate(oldBlock, strlen(oldBlock) + 1, 20);
    printf("Old Block: %s\n", oldBlock);
    printf("New Block: %s\n", newBlock);
    free(newBlock);
    free(oldBlock);

    return 0;
}
