#include "main.h"

/**
 * _memset - Fills the first n bytes of the memory area pointed to by s with a constant byte.
 * @s: A pointer to the memory area to be filled.
 * @b: The character to fill the memory area with.
 * @n: The number of bytes to be filled.
 *
 * Return: A pointer to the filled memory area.
 */
char *_memset(char *s, char b, unsigned int n)
{
    char *ptr = s;

    while (n > 0)
    {
        *s = b;
        s++;
        n--;
    }

    return ptr;
}
