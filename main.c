#include "holberton.h"
/**
 * Big boi shell
 */
int main(int ac __attribute__((unused)), char **av, char **env)
{
	pid_t myPid, parentPid;
	int i;
	char *input = NULL, **command;
	size_t size;
	ssize_t status;
	//char **path;

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
	//path = get_path(env);
	while (1)
	{
		new_prompt();
		status = getline(&input, &size, stdin);
		if (status == -1)
			perror("Error reading input");
		/* parse input to get command and arguments */
		command = parse_input(input);
		
		if ((_strcmp(command[0], "exit") == 0))
			exit(0);

		else if ((_strcmp(command[0], "env") == 0))
			print_env(env);

		else if (_strcmp(command[0], "\n") != 0)
		{
			_puts(input);
			_puts("\n");
		}
		
		free(command);
	}
	return (0);
}
