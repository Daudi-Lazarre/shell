#include "holberton.h"

/**
 * main - Big boi shell
 * @ac: argument count
 * @av: argument vectors
 * @env: environment variables
 8
 * Return: 0 success, 1 error
 */
int main(int ac __attribute__((unused)), char **av, char **env)
{
	int exit_code = 0, loop = 1;
	char *input = NULL, **command = NULL, **path = NULL;
	size_t size;
	
	(void) av;

	/* get the path info from environment variables */
	while (loop)
	{
		path = _getpath(env);
		new_prompt();
		if (getline(&input, &size, stdin) == -1)
		{
			loop = 0;
			exit_code = 1;
		}
		if (loop)
		{
			/* parse input to get command and arguments */
			command = parse_input(input, &size);
			exit_code = run_command(command, path, env);
			free(command);
		}
		if (exit_code == 0 || exit_code == 1)
			loop = 0;
		free(path);
	}
	free(input);

	return (exit_code);
}
