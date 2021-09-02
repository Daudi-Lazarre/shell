#include "holberton.h"

/**
 * _itoa - changes int to string
 * @num: number
 * @str: string
 * @base: BASS
 * Return: string
 */

char *_itoa(int num, char *str, int base)
{
	int i = 0;

	/* Handle 0 explicitly, otherwise empty string will be printed for 0 */
	if (num == 0)
	{
		str[i++] = '0';
		str[i] = '\0';
		return (str);
	}

	/* Process individual digits */
	while (num != 0)
	{
		int rem = num % base;

		str[i++] = (rem > 9) ? (rem - 10) + 'a' : rem + '0';

		num = num / base;
	}

	str[i] = '\0'; /* Append string terminator */

	/* Reverse the string */
	rev_string(str);

	return (str);
}
