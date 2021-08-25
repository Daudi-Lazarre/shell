#include "holberton.h"

/**
 * Big boi shell
 */
int main(int ac __attribute__((unused)), char **av, char **env)
{
	pid_t myPid, parentPid;
	int i;
	char *input = NULL, **command, **path = NULL;
	size_t size;
	ssize_t status;

	myPid = getpid();
	parentPid = getppid();

	_puts("----------------------------------\n");
	_puts("Diagnostics: \n\n");
	printf("My PID: %u\n", myPid);
	printf("Parent PID: %u\n", parentPid);

	/* prints all argv values */
	for(i = 0; av[i]; i++)
		printf("av[%d]: %s\n", i, av[i]);

	_puts("----------------------------------\n");
	
	/* get the path info from environment variables */
	path = _getpath(env);
	while (1)
	{
		new_prompt();
		status = getline(&input, &size, stdin);
		if (status == -1)
			exit(1);
		/* parse input to get command and arguments */
		command = parse_input(input, &size);
		
		/* run to dispatcher to check builtins, use func ptr*/
		
		if ((_strcmp(command[0], "exit") == 0))
			exit(0);

		else if ((_strcmp(command[0], "env") == 0))
			print_env(env);
		
		else if ((_strcmp(command[0], "path") == 0))
		{
			for (i = 0; path[i]; i++)
				printf("path[%d]: %s\n", i, path[i]);
		}

		else if (_strcmp(command[0], "\n") != 0)
		{
			for (i = 0; command[i]; i++)
			{
				_puts(command[i]);
				if (command[i + 1])
					_puts(" | ");
			}
			_puts("\n");
		}
		
		free(command);
	}
	return (0);
}
