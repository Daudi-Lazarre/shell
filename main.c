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
 * new_prompt - starts a new prompt
 */
void new_prompt(void)
{
	_putchar('\n');
	_putchar('$');
	_putchar(' ');
}

/**
 * _strcmp - Compares two strings
 * @s1: pointer to string 1
 * @s2: pointer to string 2
 *
 * Return: -diff if 1 LT 2 0 if 1 EQ 2 +diff if 1 GT 2
 */
int _strcmp(char *s1, char *s2)
{
	int i = 0;
	int retval = 0;

	while ((s1[i] && s2[i]) && (s1[i] == s2[i]))
		i++;

	retval = s1[i] - s2[i];

	return (retval);
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

	printf("My PID: %u\n", myPid);
	printf("Parent PID: %u\n", parentPid);

	/* prints all argv values */
	for(i = 0; av[i]; i++)
		printf("av[%d]: %s\n", i, av[i]);
	
	new_prompt();

	while (getline(&input, &size, stdin) != -1)
	{
		/* check if exit command */
		if (_strcmp(input, "exit\n") == 0)
			exit(1);

		/* todo: check if env command */

		printf("%s", input);
		new_prompt();
	}
	return (0);
}
