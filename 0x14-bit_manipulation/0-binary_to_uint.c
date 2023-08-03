#include "main.h"
#include <stddef.h>

/**
 * binary_to_uint - Converts binary number to an unsigned int.
 * @b: Pointer to a string
 *
 * Return: The unsigned int
 */
unsigned int binary_to_uint(const char *b)
{
	unsigned int res = 0;
	int i;

	if (b == NULL)
		return (0);

	for (i = 0; b[i] != '\0'; i++)
	{
		if (b[i] != '0' && b[i] != '1')
			return (0);
	}

	for (i = 0; b[i] != '\0'; i++)
	{
		res = res << 1;
		if (b[i] == '1')
			res |= 1;
	}

	return (res);
}

