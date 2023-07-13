#include "main.h"
#include <stdlib.h>
#include <string.h>

/**
 * _calloc - Allocates memory for an array using malloc
 * @nmemb: The number of elements in the array
 * @size: The size of each element in bytes
 *
 * Return: A pointer to the allocated memory, or NULL if allocation fails
 */
void *_calloc(unsigned int nmemb, unsigned int size)
{
void *ptr;
unsigned int total_size;

/* Check for zero nmemb or size */
if (nmemb == 0 || size == 0)
return (NULL);

/* Calculate the total size */
total_size = nmemb * size;

/* Allocate memory using malloc */
ptr = malloc(total_size);

/* Check if allocation fails */
if (ptr == NULL)
return (NULL);

/* Set the allocated memory to zero */
memset(ptr, 0, total_size);

return (ptr);
}
