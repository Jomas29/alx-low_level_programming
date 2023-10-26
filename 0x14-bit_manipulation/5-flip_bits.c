#include "main.h"

/**
 * flip_bits - Number of bits to flip to get from one number to another.
 * @n: The first number.
 * @m: The second number.
 *
 * Return: The number of bits needed to flip.
 */
unsigned int flip_bits(unsigned long int n, unsigned long int m)
{
	unsigned int c = 0;
	unsigned long int res = n ^ m;

	while (res)
	{
		c += res & 1;
		res >>= 1;
	}

	return (c);
}

