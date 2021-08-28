#include "holberton.h"

/**
 * pointer_release - release pointers in double pointer
 * @ptr:  pointer to release
 */
void pointer_release(char **ptr)
{
	int i = 0;

	if (ptr[i])
	{
		while (ptr[i])
		{
			free(ptr[i]);
			i++;
		}

		free(ptr);
	}
}
