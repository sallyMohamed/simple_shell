#include "shell.h"

/**
 **_stringcopy - copyString
 *@destin: destination stringTOcopied
 *@sorce: sourceString
 *@sn: Numbercharacters copied
 *Return: concatenatedString
 */
char *_stringcopy(char *destin, char *sorce, int sn)
{
	int c, x;
	char *strig = destin;

	c = 0;
	while (sorce[c] != '\0' && c < sn - 1)
	{
		destin[c] = sorce[c];
		c++;
	}
	if (c < sn)
	{
		x = c;
		while (x < sn)
		{
			destin[x] = '\0';
			x++;
		}
	}
	return (strig);
}

/**
 **_stringcat - concatenateStrings
 *@destin: String One
 *@sorce: string two
 *@sn: bytes used
 *Return: the concatenated string
 */
char *_stringcat(char *destin, char *sorce, int sn)
{
	int c, x;
	char *strig = destin;

	c = 0;
	x = 0;
	while (destin[c] != '\0')
		c++;
	while (sorce[x] != '\0' && x < sn)
	{
		destin[c] = sorce[x];
		c++;
		x++;
	}
	if (x < sn)
		destin[c] = '\0';
	return (strig);
}

/**
 **_stringchar - locateCharacter in string
 *@strig: string parsed
 *@chart: character
 *Return: (string) pointer toMemory
 */
char *_stringchar(char *strig, char chart)
{
	do {
		if (*strig == chart)
			return (strig);
	} while (*strig++ != '\0');

	return (NULL);
}
