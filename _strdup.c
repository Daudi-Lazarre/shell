#include "holberton.h"
#include <stdlib.h>

/**
 * _strdup - Returns pointer to copy of string given as param
 * @str: Source string
 *
 * Return: NULL if insufficient memory, ptr to new string otherwise
 */
char *_strdup(char *str)
{
	char *new_str;
	int i;
	int length = 0;

	if (!str)
		return (NULL);

	for (i = 0; str[i]; i++)
		length++;

	new_str = malloc(sizeof(char) * (length + 1));

	if (!new_str)
		return (NULL);

	for (i = 0; str[i]; i++)
		new_str[i] = str[i];

	new_str[length] = '\0';

	return (new_str);
}
