#include "holberton.h"
/**
 * print_env - prints all environment variables
 * @env: environment variable list
 */
void print_env(char **env)
{
	int i;

	for (i = 0; env[i]; i++)
		_puts(env[i]);
}
