#include "holberton.h"

/**
 * findpath - checks for a valid path
 * @command: command to look for
 * @path: pointer to a pointer of paths to check
 *
 * Return: Pointer to the command, modified or not.
 */
char *findpath(char *command, char **path)
{
	int i, j, cursor;
	char *temp = NULL;

	if (!command || !path)
		exit(1);

	for (i = 0; path[i]; i++)
	{
		temp = malloc(sizeof(char) * (_strlen(command) + _strlen(path[i]) + 2));
		if (!temp)
		{
			perror("Failed to malloc temp");
			exit(1);
		}
		cursor = 0;


		for (j = 0; path[i][j]; j++, cursor++)
			temp[cursor] = path[i][j];
		temp[cursor] = '/';
		cursor++;

		for (j = 0; command[j]; j++, cursor++)
			temp[cursor] = command[j];

		temp[cursor] = '\0';

		if (access(temp, X_OK) == 0)
		{
			command = _strdup(temp);
			free(temp);
			return (command);
		}
		free(temp);
	}
	return (command);
}
