#include "holberton.h"
/**
 * run_command - runs the supplied command
 * @command: pointer to a pointer of chars with the command
 * @path: variable to the path
 * @env: env variable
 * @av: argv
 *
 * Return: 0 for success but exit. 1 for error but exit. 2 for continue
 */
int run_command(char **command, char **path, char **env, char **av)
{
	int i, exit_code = 2;
	char *cmd = NULL;

	if ((_strcmp(command[0], "env") == 0))
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
		cmd = findpath(command[0], path);
		if (access(cmd, X_OK) == 0)
		{
			exit_code = execute(cmd, command, env, av);
		}
		else
		{
			_puts(av[0]);
			_puts(": ");
			_puts("1: ");
			_puts(cmd);
			_puts(": not found\n");
		}
		if(cmd)
			free(cmd);
	}
	return (exit_code); /* 2 means proceed */
}
