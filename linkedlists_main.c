#include "shell.h"
/**
 * main - Entry point
 * Return: 0 is success.
*/

int main(void)
{
list_str *list = NULL;
/* Example usage of addto_start and addto_end functions */
addto_start(&list, "First Node", 0);
addto_end(&list, "Second Node", 1);
addto_end(&list, "Third Node", 2);

/* Example usage of say_stringlist function */
say_stringlist(list);

/* Example usage of _deletenodeatindex function */
_deletenodeatindex(&list, 1);

/* Print the list after deletion */
say_stringlist(list);

/* Free the memory used by the list */
_freelist(&list);

return (0);
}
