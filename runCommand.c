#include "holberton.h"
/**
 * run_command - runs the supplied command
 * @command: pointer to a pointer of chars with the command
 * @path: variable to the path
 * @env: env variable
 *
 * Return: 0 for success but exit. 1 for error but exit. 2 for continue
 */
int run_command(char **command, char **path, char **env)
{
	int i;

	if ((_strcmp(command[0], "exit") == 0))
		return (1);
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
		printf("Command is: %s\n", command[0]);
		if (access(command[0], X_OK) == 0)
		{
			execute(command, env);
			free(command[0]);
		}
		else
			_puts("simple shell: no such file or directory\n");
	}
	return (0);
}
