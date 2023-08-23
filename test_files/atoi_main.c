#include "shell.h"
#include <stdio.h>

/**
 * main - check the code
 *
 * Return: Always 0.
 */
int main(void)
{
    int nb;

    nb =  _atointeger("98");
    printf("%d\n", nb);
    nb =  _atointeger("-402");
    printf("%d\n", nb);
    nb =  _atointeger("          ------++++++-----+++++--98");
    printf("%d\n", nb);
    nb =  _atointeger("214748364");
    printf("%d\n", nb);
    nb =  _atointeger("0");
    printf("%d\n", nb);
    nb =  _atointeger("Suite 402");
    printf("%d\n", nb);
    nb =  _atointeger("         +      +    -    -98 Battery Street; San Francisco, CA 94111 - USA             ");
    printf("%d\n", nb);
    nb =  _atointeger("---++++ -++ Sui - te -   402 #cisfun :)");
    printf("%d\n", nb);
    return (0);
}
