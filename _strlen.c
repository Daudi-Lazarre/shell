#include "holberton.h"

/**
 * _strlen - calculates length of string
 * @s: pointer to string
 *
 * Return: length of string (int)
 */
int _strlen(char *s)
{
	int length = 0;

	while (*s != 0) /* loop through char array by pointer */
	{
		s++;
		length++;
	}

	return (length);
}
