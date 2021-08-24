#include <stdio.h>
#include <unistd.h>
#include <stdlib.h>

/**
 * _putchar - writes the character c to stdout
 * @c: The character to print
 *
 * Return: On success 1.
 * On error, -1 is returned, and errno is set appropriately.
 */
int _putchar(char c)
{
        return (write(1, &c, 1));
}

/**
 * main - Entry point of simple shell program.
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

	//printf("%u\n", myPid);
	//printf("%u\n", parentPid);

	while (1)
	{
		/* do initial prompt */
		_putchar('$');
		_putchar(' ');

		/* read input */
		if (getline(&input, &size, stdin) == -1)
			printf("No line\n");
		else
			printf("%s\n", input);

		// parse string
		// is exit? 
		// is wildcard?
		
		
		/* prints all argv values */
		for(i = 0; av[i]; i++)
		{
			printf("av[%d]: %s\n", i, av[i]);
		}
		exit(1);
	}
	return (0);
}
