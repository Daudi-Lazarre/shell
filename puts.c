#include <stdio.h>
#include "holberton.h"

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
