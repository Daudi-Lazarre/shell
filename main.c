#include <stdio.h>
#include <unistd.h>
#include <stdlib.h>
#include "holberton.h"
/**
 * Big boi shell
 */
int main(int ac __attribute__((unused)), char **av, char **env)
{
	pid_t myPid;
	pid_t parentPid;
	int i;
	char *input = NULL;
	size_t size;

	myPid = getpid();
	parentPid = getppid();

	_puts("----------------------------------\n");
	_puts("Diagnostics: \n\n");
	printf("My PID: %u\n", myPid);
	printf("Parent PID: %u\n", parentPid);

	/* prints all argv values */
	for(i = 0; av[i]; i++)
		printf("av[%d]: %s\n", i, av[i]);

	/* prints all environment variables */
	print_env(env);

	_puts("----------------------------------\n\n");

	new_prompt();

	while (getline(&input, &size, stdin) != -1)
	{
  		/* check if exit command */
		if (_strcmp(input, "exit\n") == 0)
			exit(1);

		/* check if env command */
		if (_strcmp(input, "env\n") == 0)
			print_env(env);

		_puts(input);
		new_prompt();
	}
	return (0);
}
