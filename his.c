#include "shell.h"

/**
 * *getHisfile - history file
 * @i: structuralArgument
 *
 * Return: allocated string
 */

char *getHisfile(i_t *i)
{
	char *buff, *d;

	d = _envData(i, "HOME=");
	if (!d)
		return (NULL);
	buff = malloc(sizeof(char) * (_stringlen(d) + _stringlen(HISTORY_FILE) + 2));
	if (!buff)
		return (NULL);
	buff[0] = 0;
	_strcpy(buff, d);
	_stringcat2(buff, "/");
	_stringcat2(buff, HISTORY_FILE);
	return (buff);
}

/**
 * writeHistory - creates a file or  from  existing file
 * @i: the parameter struct
 *
 * Return: 1 on success, else -1
 */
int writeHistory(i_t *i)
{
	ssize_t fdis;
	char *file_name = getHisfile(i);
	list_str *nod_e = NULL;

	if (!file_name)
		return (-1);

	fdis = open(file_name, O_CREAT | O_TRUNC | O_RDWR, 0644);
	free(file_name);
	if (fdis == -1)
		return (-1);
	for (nod_e = i->history; nod_e; nod_e = nod_e->next)
	{
		_putsfdis(nod_e->string, fdis);
		_putfdis('\n', fdis);
	}
	_putfdis(BUFFER_FLUSH, fdis);
	close(fdis);
	return (1);
}

/**
 * readHistory - readsHistory
 * @i: structuralArgument
 *
 * Return: histcount , 0 otherwise
 */
int readHistory(i_t *i)
{
	int j, l = 0, linec = 0;
	ssize_t fdis, len, f_size = 0;
	struct stat str;
	char *buff = NULL, *file_name = getHisfile(i);

	if (!file_name)
		return (0);

	fdis = open(file_name, O_RDONLY);
	free(file_name);
	if (fdis == -1)
		return (0);
	if (!fstat(fdis, &str))
		f_size = str.st_size;
	if (f_size < 2)
		return (0);
	buff = malloc(sizeof(char) * (f_size + 1));
	if (!buff)
		return (0);
	len = read(fdis, buff, f_size);
	buff[f_size] = 0;
	if (len <= 0)
		return (free(buff), 0);
	close(fdis);
	for (j = 0; j < f_size; j++)
		if (buff[j] == '\n')
		{
			buff[j] = 0;
			build_hlist(i, buff + l, linec++);
			l = j + 1;
		}
	if (l != j)
		build_hlist(i, buff + l, linec++);
	free(buff);
	i->histcount = linec;
	while (i->histcount-- >= HISTORY_MAX)
		_deletenodeatindex(&(i->history), 0);
	renumberHis(i);
	return (i->histcount);
}

/**
 * build_hlist - adds to a history linkedlist
 * @i: StructureArguments.
 * @buff: buffer
 * @linec: the history linecount, histcount
 *
 * Return: Always 0
 */
int build_hlist(i_t *i, char *buff, int linec)
{
	list_str *nod_e = NULL;

	if (i->history)
		nod_e = i->history;
	addto_end(&nod_e, buff, linec);

	if (!i->history)
		i->history = nod_e;
	return (0);
}

/**
 * renumberHis - renumbers history
 * @i: StructureArguments. Used to maintain
 *
 * Return: histcount
 */
int renumberHis(i_t *i)
{
	list_str *nod_e = i->history;
	int c = 0;

	while (nod_e)
	{
		nod_e->number = c++;
		nod_e = nod_e->next;
	}
	return (i->histcount = c);
}
