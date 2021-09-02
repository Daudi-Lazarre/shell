#include "holberton.h"
/**
 * _getenv - retrieves an environment variable
 * @variable: environment variable to retrieve
 * @env: environment variables
 *
 * Return: Environment variable data
 */
char *_getenv(char *variable, char **env)
{
	int i;
	int j;
	int match;
	int length = 0;

	if (!env)
		return (NULL);

	length = _strlen(variable);

	for (i = 0; env[i] != 0; i++)
	{
		match = 0;

		for (j = 0; env[i][j] && j < length; j++)
		{
			if (env[i][j] == variable[j])
				match++;
		}
		if (match == length && env[i][match] == '=')
			return (env[i]);
	}

	return (NULL);
}
