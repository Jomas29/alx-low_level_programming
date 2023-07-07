#include "main.h"

/**
 * _strspn - Calculates the length of the initial segment of s which consists
 * entirely of characters in accept.
 * @s: The string to be searched.
 * @accept: The string containing the characters to search for.
 *
 * Return: The number of bytes in the initial segment of s which consist
 * only of characters from accept.
 */
unsigned int _strspn(char *s, char *accept)
{
    unsigned int count = 0;

    while (*s && _strchr(accept, *s))
    {
        count++;
        s++;
    }

    return count;
}
