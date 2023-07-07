#include "main.h"

/**
 * _memcpy - Copies n bytes from memory area src to memory area dest.
 * @dest: The destination memory area.
 * @src: The source memory area.
 * @n: The number of bytes to be copied.
 *
 * Return: A pointer to the destination memory area.
 */
char *_memcpy(char *dest, char *src, unsigned int n)
{
    char *ptr = dest;

    while (n > 0)
    {
        *dest = *src;
        dest++;
        src++;
        n--;
    }

    return ptr;
}
