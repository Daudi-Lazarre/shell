#include "holberton.h"

/**
 * _getpath - retrieves paths from environment variables
 * @env: environment variables
 *
 * Return: Pointer to pointer of paths or NULL
 */
char **_getpath(char **env)
{
	char *string;
	char *ptr;
	char *path = NULL;
	char **paths = NULL;
	int cursor = 0;

	string = _strdup(_getenv("PATH", env));
	ptr = string;
	if (string && ptr)
		paths = _allocate(sizeof(char *), _strlen(ptr));

	if (!paths)
	{
		free(paths);
		exit(1);
	}
	path = strtok(ptr, "=");
	path = strtok(NULL, ":");

	while (path)
	{
		paths[cursor] = path;
		cursor++;
		path = strtok(NULL, ":");
	}
	free(string);

	return (paths);
}
