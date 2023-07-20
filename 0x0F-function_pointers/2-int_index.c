#include "function_pointers.h"

/**
 * int_index - Searches for an integer in an array.
 * @array: Pointer to the integer array.
 * @size: Size of the array.
 * @cmp: Pointer to the function used to compare values.
 *
 * Return: Index of the first matching element, or -1.
 */
int int_index(int *array, int size, int (*cmp)(int))
{
if (array != NULL && cmp != NULL && size > 0)
{
int i;
for (i = 0; i < size; i++)
{
if (cmp(array[i]))
return (i);
}
}
return (-1);
}
