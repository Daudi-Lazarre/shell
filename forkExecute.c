#include "holberton.h"

/**
 * execute - Forks and executes command received by user.
 * @command: Contains command and arguments
 * @env: contains the environment variables
 * @av: argv
 *
 * Return: 0 or 1 error, 2 success.
 */

int execute(char **command, char **env, char **av)
{
	int status;
	pid_t myPid;

	/* check if command was received */
	if (!command || !env)
		return (1);

	/* child process error */
	myPid = fork();

	if (myPid < 0)
	{
		perror("Fork failure. Get a spoon instead.");
		return (1);
	}

	/* If it is a child process */
	else if (myPid == 0)
	{
		if (execve(command[0], command, env) == -1)
		{
			_puts(av[0]);
			_puts(": ");
			_puts("1: ");
			_puts(command[0]);
			_puts(": not found\n");
			return (1);
		}
		return (2);
	}
	else
	{
		waitpid(myPid, &status, WUNTRACED);
	}

	return (2);
}
