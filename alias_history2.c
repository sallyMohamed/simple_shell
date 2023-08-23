#include "shell.h"

/**
 * _CDhistory - history list
 *
 * @i: StructureArguments. Used to maintain
 *
 * Return: Always 0
 */
int _CDhistory(i_t *i) {
    print_linkedlist(i->history);
    return (0);
}

/**
 * unsetAlias - removes an alias
 * @i: parameter struct
 * @name: the alias name
 *
 * Return: 0 success, 1 error
 */
int unsetAlias(i_t *i, char *name) {
    return _deletenodeatindex(&(i->aliasnode), get_nodeindex(i->aliasnode, node_startWith(i->aliasnode, name, '=')));
}

/**
 * setAlias - sets or updates an alias
 * @i: structural argument
 * @s: alias definition string (e.g., "name=value")
 *
 * Return: 0 success, 1 error
 */
int setAlias(i_t *i, char *s) {
    char *value = _stringchar(s, '=');
    if (!value)
        return (1);
    
    if (!*++value)
        return unsetAlias(i, s);

    unsetAlias(i, s);
    return (addto_end(&(i->aliasnode), s, 0) == NULL) ? 0 : 1;
}

/**
 * sayAlias - prints an alias in the format "name='value'"
 * @alias: the alias node
 * 
 * Return: Always 0 success, 1 error
 */
int sayAlias(list_str *alias) {
    if (alias) {
        char *value = _stringchar(alias->string, '=');
        if (value) {
            *_stringchar(alias->string, '=') = '\0';  // Temporary modification for printing
            printf("%s='%s'\n", alias->string, value + 1);
            *_stringchar(alias->string, '=') = '=';  // Restore the original string
            return 0;
        }
    }
    return 1;
}

/**
 * _filealias - handles alias operations from files or command-line arguments
 * @i: structural argument
 *
 * Return: Always 0
 */
int _filealias(i_t *i) {
    int j;
    char *value = NULL;
    list_str *alias;

    if (i->argcounter == 1) {
        alias = i->aliasnode;
        while (alias) {
            sayAlias(alias);
            alias = alias->next;
        }
        return 0;
    }

    for (j = 1; i->argvactor[j]; j++) {
        value = _stringchar(i->argvactor[j], '=');
        if (value)
            setAlias(i, i->argvactor[j]);
        else
sayAlias(node_startWith(i->aliasnode, i->argvactor[j], '='));
}
return 0;
}
