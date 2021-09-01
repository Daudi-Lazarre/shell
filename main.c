#include "holberton.h"

/**
 * goodbye - exits shell
 * @input: input from getline
 * @path: path variable double pointer
 * @command: command parsed
 */
void goodbye(char *input, char **path, char **command)
{
	if (input)
		free(input);
	if (path)
		free(path);
	if (command)
		free(command);

	exit(0);
}
/**
 * main - Big boi shell
 * @ac: argument count
 * @av: argument vectors
 * @env: environment variables
 * Return: 0 success, 1 error
 */
int main(int ac __attribute__((unused)), char **av, char **env)
{
	int exit_code = 0, loop = 1;
	char *input = NULL, **command = NULL, **path = NULL;
	size_t size;

	path = _getpath(env);
	/* get the path info from environment variables */
	while (loop)
	{
		new_prompt();
		if (getline(&input, &size, stdin) == -1)
		{
			goodbye(input, path, NULL);
		}
		if (loop)
		{
			/* parse input to get command and arguments */
			command = parse_input(input, &size);
			if ((_strcmp(command[0], "exit") == 0))
			{
				goodbye(input, path, command);
			}
			exit_code = run_command(command, path, env, av);
			free(command);
		}
		if (exit_code == 0 || exit_code == 1)
			loop = 0;
	}
	goodbye(input, path, command);

	return (0);
}
