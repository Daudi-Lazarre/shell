#include <stdio.h>
#include "holberton.h"
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
