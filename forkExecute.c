#include "holberton.h"
#include <sys/wait.h>
#include <unistd.h>
#include <stdbool.h>

/**
 * Execute - Executes the input received from user
 */

int execute(int ac __attribute__((unused)), char **av)
{
	int status;
	bool background = false;
	pid_t myPid;

	/* background process */
	while ((strchr(av[ac-1], '&') != NULL) /* when ampersand exists */ )
	{
		background = true;
		av[ac-1] = NULL;
		ac--;
	}

	/* child process error */
	myPid = fork();
	if (myPid < 0)
	{
		_puts("Fork failure. Get a spoon instead.");
	}
	return (0);

	/* If it is a child process */
	if (myPid == 0)
	{
		if (execvp(av[0], av) == 0)
			_puts("Program run failure.");
		return (0);
	}
	else
	{
		if (!background)
		{
			while (wait(&status) != myPid)
				;
		}
	}

	/* Nothing happens until child is done with execution*/
	wait(NULL);
	return (0);
}
