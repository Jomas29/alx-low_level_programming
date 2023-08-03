#include <stdio.h>
#include "main.h"

/**
 * flip_bits - Returns the number of bits needed to flip
 * @n: The first number.
 * @m: The second number.
 *
 * Return: The number of bits needed to flip.
 */
unsigned int flip_bits(unsigned long int n, unsigned long int m)
{
	unsigned long int flipp = n ^ m;
	unsigned int count = 0;

	while (flipp > 0)
	{
		count += flipp & 1;
		flipp >>= 1;
	}

	return (count);
}

