#include <stdio.h>
#include "shell.h"

int main(void)
{
char str1[] = "hello";
char str2[] = "world";
char str3[] = "hello";
char str4[] = "world";
int len1 = _stringlen(str1);
int len2 = _stringlen(str2);
int comp_result1 = _stringcomp(str1, str2);
int comp_result2 = _stringcomp(str3, str4);
char *haystack = "hello_world";
char *needle = "hello";
char *result = startWith(haystack, needle);
char dest[50] = "Hello, ";
char source[] = "world!";
_stringcat2(dest, source);
printf("Length of str1: %d\n", len1);
printf("Length of str2: %d\n", len2);
printf("Comparison result between str1 and str2: %d\n", comp_result1);
printf("Comparison result between str3 and str4: %d\n", comp_result2);
if (result)
{
printf("'%s' starts with '%s'\n", haystack, needle);
}
else
{
printf("'%s' does not start with '%s'\n", haystack, needle);
}
printf("Concatenated string: %s\n", dest);
return (0);
}
