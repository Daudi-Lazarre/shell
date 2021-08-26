#include "holberton.h"
#include <sys/wait.h>
#include <unistd.h>
#include <stdbool.h>

/**
 * Execute - Executes the input received from user
 */

int execute(char **command, char **env)
{
	int status;
	pid_t myPid;

	/* check if command was received */
	if (!command || !env)
		return (-1);

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
			free(command);
			perror("Program run failure.");
			exit(1);
		}
		exit(0);
	}
	else
	{
		waitpid(myPid, &status, WUNTRACED);
	}

	return (1);
}
