#include "holberton.h"

/**
 * _allocate - allocate memory for an array of element
 * 		all size bytes long, all at 0
 * @num: number of elements
 * @size: size in bytes
 *
 * Return: pointer to allocated memory, or NULL if fail
 */
void *_allocate(size_t num, size_t size)
{
	char *ptr;
	size_t i;

	if (!num)
		return (NULL);

	if (!size)
		return (NULL);

	ptr = malloc(num * size);

	if (!ptr)
	{
		free(ptr);
		return (NULL);
	}

	for (i = 0; i < (num * size); i++)
		ptr[i] = 0;

	return (ptr);
}
