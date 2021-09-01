#include "holberton.h"
/**
 * run_command - runs the supplied command
 * @command: pointer to a pointer of chars with the command
 * @path: variable to the path
 * @env: env variable
 *
 * Return: 0 for success but exit. 1 for error but exit. 2 for continue
 */
int run_command(char **command, char **path, char **env, char **av)
{
	int i, exit_code = 2;

	if ((_strcmp(command[0], "exit") == 0))
		return (0);
	else if ((_strcmp(command[0], "env") == 0))
		print_env(env);
	else if ((_strcmp(command[0], "path") == 0))
	{
		for (i = 0; path[i]; i++)
		{
			_puts(path[i]);
			_puts("\n");
		}
	}
	else if (_strcmp(command[0], "\n") != 0)
	{
		command[0] = findpath(command[0], path);
		if (access(command[0], X_OK) == 0)
		{
			exit_code = execute(command, env, av);
			free(command[0]);
		}
		else
		{
			_puts(av[0]);
			_puts(": ");
			_puts("1: ");
			_puts(command[0]);
			_puts(": not found\n");
		}
	}
	return (exit_code); /* 2 means proceed */
}
