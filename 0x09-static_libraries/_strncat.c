#include "main.h"

/**
 * _strncat - Concatenates two strings, using at most n bytes from src.
 * @dest: The destination string.
 * @src: The source string.
 * @n: The maximum number of bytes from src to be appended.
 *
 * Return: A pointer to the resulting string.
 */
char *_strncat(char *dest, char *src, int n)
{
    char *ptr = dest;

    while (*dest)
        dest++;

    while (*src && n > 0)
    {
        *dest = *src;
        dest++;
        src++;
        n--;
    }

    *dest = '\0';

    return ptr;
}
