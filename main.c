#include <stdio.h>
#include <unistd.h>
#include <stdlib.h>
/**
 * main - PID
 *
 * Return: Always 0.
 */
int main(int ac __attribute__((unused)), char **av)
{
	pid_t myPid;
	pid_t parentPid;
	myPid = getpid();
	parentPid = getppid();
	int i;
	char *input = NULL;
	size_t size;

	printf("%u\n", myPid);
	printf("%u\n", parentPid);

	while (1)
	{
		if (getline(&input, &size, stdin) == -1)
			printf("No line\n");
		else
			printf("%s\n", input);
		// do prompt
		// read input
		// parse string
		// is exit? 
		// is wildcard?
		
		for(i = 0; av[i]; i++)
		{
			printf("av[%d]: %s\n", i, av[i]);
		}
		exit(1);
	}
	return (0);
}
