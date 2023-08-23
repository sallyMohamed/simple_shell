#include "shell.h"
int main(void)
{
list_str *head = NULL;
size_t length;
list_str *nod_e;
size_t i;
char **strings;
char *string;
size_t j;
size_t printed;
list_str *matchingNode;
ssize_t index;
/* Example usage of the addto_start function */
addto_start(&head, "Hello", 1);
addto_start(&head, "World", 2);
/* Example usage of the addto_end function */
addto_end(&head, "GPT", 3);
addto_end(&head, "3.5", 4);
/* Example usage of the linkedlist_length function */
length = linkedlist_length(head);
printf("Linked list length: %lu\n", (unsigned long)length);
/* Example usage of the linkedlist_strings function */
if (!head || length == 0)
return (1);
strings = malloc(sizeof(char *) * (length + 1));
if (!strings)
return (1);
for (i = 0, nod_e = head; nod_e; nod_e = nod_e->next, i++)
{
string = malloc(_stringlen(nod_e->string) + 1);
if (!string)
{
for (j = 0; j < i; j++)
free(strings[j]);
free(strings);
return (1);
}
string = _strcpy(string, nod_e->string);
strings[i] = string;
}
strings[i] = NULL;
/*usage of print_linkedlist function*/
printed = print_linkedlist(head);
printf("Printed elements: %lu\n", (unsigned long)printed);
/*usage of node_startWith function*/
matchingNode = node_startWith(head, "Wor", -1);
if (matchingNode)
printf("Match:%s\n", matchingNode->string);
/*usage of get_nodeindex function */
index = get_nodeindex(head, head->next);
printf("Index of second node: %ld\n", (long)index);
/* Free memory allocated for strings */
for (i = 0; strings[i]; i++)
free(strings[i]);
free(strings);
/*Freememoryallocated for linked list*/
_freelist(&head);
return 0;
}
