#include <stddef.h>
#include "shell.h"
/**
 * main - Entry point
 * Returns: 0 is success
*/

void *_memset(void *s, int c, size_t n)
{
unsigned char *p = s;
while (n > 0)
{
*p = (unsigned char)c;
p++;
n--;
}
return (s);
}

int main()
{
char arr[10];
_memset(arr, 'A', sizeof(arr));
/* Now the 'arr' should be filled with 'A' characters */
return (0);
}
