#include "holberton.h"
/**
 * new_prompt - starts a new prompt
 */
void new_prompt(void)
{
	if (isatty(STDIN_FILENO) == 1)
		_puts("$ ");
}
