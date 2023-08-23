#include "shell.h"

/**
 * _exitCmd - exitShell
 * @i: StructureArguments
 *  Return: exitsWithExit status
 */
int _exitCmd(i_t *i)
{
	int e_check;

	if (i->argvactor[1])
	{
		e_check = _strErrortoi(i->argvactor[1]);
		if (e_check == -1)
		{
			i->status = 2;
			say_error(i, "Wrong  number: ");
			_inputputs(i->argvactor[1]);
			_inputputchar('\n');
			return (1);
		}
		i->error_num = _strErrortoi(i->argvactor[1]);
		return (-2);
	}
	i->error_num = -1;
	return (-2);
}

/**
 * _changdir - changeDirectory
 * @i: StructureArguments.
 *  Return:  0
 */


/**
 * _cd_builtin - Implements the builtin command cd
 *
 * @i: The structure containing command and arguments
 * Return: Always 0
 */
int _cd_builtin(i_t *i)
{
    char *new_dir = i->argvactor[1];

    if (!new_dir) {
        new_dir = _envData(i, "HOME=");
        if (!new_dir)
            new_dir = _envData(i, "pwd=");
    } else if (_stringcomp(new_dir, "-") == 0) {
        new_dir = _envData(i, "O_pwd=");
        if (!new_dir) {
            _puts("No previous directory stored\n");
            return (1);
        }
    }

    char *current_dir = getcwd(NULL, 0);
    if (!current_dir) {
        say_error(i, "getcwd failed");
        return (1);
    }

    int chdir_result = chdir(new_dir);
    if (chdir_result == -1) {
        say_error(i, "chdir failed");
        free(current_dir);
        return (1);
    }

    _setEnvo(i, "O_pwd", current_dir);
    _setEnvo(i, "pwd", getcwd(NULL, 0));
    free(current_dir);

    return (0);
}
/*int _changdir(i_t *i)
{
	char *x, *directory, buffer_size[1024];
	int chdirectory;

	x = getcwd(buffer_size, 1024);
	if (!x)
		_puts(" >> Error <<\n");
	if (!i->argvactor[1])
	{
		directory = _envData(i, "HOME=");
		if (!directory)
			chdirectory =
				chdir((directory = _envData(i, "pwd=")) ? directory : "/");
		else
			chdirectory = chdir(directory);
	}
	else if (_stringcomp(i->argvactor[1], "-") == 0)
	{
		if (!_envData(i, "O_pwd="))
		{
			_puts(x);
			_putchar('\n');
			return (1);
		}
		_puts(_envData(i, "O_pwd=")), _putchar('\n');
		chdirectory =
			chdir((directory = _envData(i, "O_pwd=")) ? directory : "/");
	}
	else
		chdirectory = chdir(i->argvactor[1]);
	if (chdirectory == -1)
	{
		say_error(i, "change directory faild ");
		_inputputs(i->argvactor[1]), _inputputchar('\n');
	}
	else
	{
		_setEnvo(i, "O_pwd", _envData(i, "pwd="));
		_setEnvo(i, "pwd", getcwd(buffer_size, 1024));
	}
	return (0);
}*/

/**
 * _CDhelp - changeCurrent directory help
 * @i: StructureArguments.
 *  Return: Always 0
 */
int _CDhelp(i_t *i)
{
	char **argu_arr;

	argu_arr = i->argvactor;
	_puts("Sorry this not developed \n");
	if (0)
		_puts(*argu_arr);
	return (0);
}
