#include "holberton.h"

/**
 * execute - Forks and executes command received by user.
 * @command: Contains command and arguments
 * @env: contains the environment variables
 *
 * Return: 1 error, 0 success.
 */

int execute(char **command, char **env)
{
	int status;
	pid_t myPid;

	/* check if command was received */
	if (!command || !env)
		exit(1);

	/* child process error */
	myPid = fork();

	if (myPid < 0)
	{
		perror("Fork failure. Get a spoon instead.");
		exit(1);
	}

	/* If it is a child process */
	else if (myPid == 0)
	{
		if (execve(command[0], command, env) == -1)
		{
			perror("simple shell");
			exit(1);
		}
		exit(0);
	}
	else
	{
		waitpid(myPid, &status, WUNTRACED);
	}

	return (0);
}
