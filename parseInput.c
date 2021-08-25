#include "holberton.h"

/**
 *parse_string - breaks up a string into an array of strings
 *@input: string to break up
 *
 *Return: Array of strings on success.
 */
char **parse_input(char *input, size_t *size)
{
	size_t bufferSize = *size;
	int cursor = 0;

	char **strings;
	char *string;

	if (!input)
		return (0);

	strings = _allocate(sizeof(char *), bufferSize);

	if (!strings)
	{
		free(strings);
		exit(1);
	}

	string = strtok(input, " \n\t\r");

	while (string)
	{
		strings[cursor] = string;
		cursor++;
		string = strtok(NULL, " \n\t\r");
	}

	if (!strings[0])
		strings[0] = "\n";

	return (strings);
}
