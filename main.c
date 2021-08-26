#include "holberton.h"

/**
 * Big boi shell
 */
int main(int ac __attribute__((unused)), char **av, char **env)
{
	int i;
	char *input = NULL, **command = NULL, **path = NULL;
	size_t size;
	ssize_t status;
	int tty = 0;

	/* are we a tty? */
	if (isatty(STDIN_FILENO) == 1)
		tty = 1;
	/* get the path info from environment variables */
	path = _getpath(env);
	while (1)
	{
		if(tty)
			new_prompt();
		status = getline(&input, &size, stdin);
		if (status == -1)
			exit(1);
		/* parse input to get command and arguments */
		command = parse_input(input, &size);
		
		/* TODO: use function pointer */
		
		if ((_strcmp(command[0], "exit") == 0))
			exit(0);

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
				execute(command, env);
			else
				_puts("simple shell: no such file or directory\n");
		}
		else
			free(command);
		
		free(input);
	}
	return (0);
}
