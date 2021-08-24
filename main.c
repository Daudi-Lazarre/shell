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
 * _puts - writes an array of chars. No newline
 * @str: pointer to string
 *
 */
void _puts(char *str)
{
	while (*str != 0) /* loop through char array by pointer */
	{
		_putchar(*str);
		str++;
	}
}
/**
 * new_prompt - starts a new prompt
 */
void new_prompt(void)
{
	_putchar('$');
	_putchar(' ');
}

/**
 * _strcmp - Compares two strings
 * @s1: pointer to string 1
 * @s2: pointer to string 2
 *
 * Return: Negative if s1 < s2; 0 if equal, Positive if 1 > 2
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
 * print_env - prints all environment variables
 */
void print_env(char **env)
{
	int i;
	for(i = 0; env[i]; i++)
		printf("env[%d]: %s\n", i, env[i]);
}
	
/**
 * main - Entry point of simple shell program.
 *
 * Return: Always 0.
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
