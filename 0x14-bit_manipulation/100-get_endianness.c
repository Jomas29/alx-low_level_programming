#include <stdio.h>
#include "main.h"

/**
 * get_endianness - Checks the endianness of the machine.
 *
 * Return: 0 if big endian, 1 if little endian.
 */
int get_endianness(void)
{
	unsigned int i = 1;
	char *mem = (char *)&i;

	return (mem[0] ? 1 : 0);
}

