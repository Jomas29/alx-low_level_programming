#include "main.h"
#include <stdlib.h>

/**
 * argstostr - Concatenates all the arguments of the program
 * @ac: The number of arguments
 * @av: The array of arguments
 *
 * Return: Pointer to the concatenated string, or NULL if it fails
 */
char *argstostr(int ac, char **av)
{
	char *concatenated;
	int total_length = 0, i, j, k = 0;

	if (ac == 0 || av == NULL)
		return (NULL);

	/* Calculate the total length of the arguments */
	for (i = 0; i < ac; i++)
	{
		for (j = 0; av[i][j] != '\0'; j++)
			total_length++;
		total_length++; /* Account for the newline character */
	}

	/* Allocate memory for the concatenated string */
	concatenated = malloc(sizeof(char) * (total_length + 1));
	if (concatenated == NULL)
		return (NULL);

	/* Copy the arguments into the concatenated string */
	for (i = 0; i < ac; i++)
	{
		for (j = 0; av[i][j] != '\0'; j++, k++)
			concatenated[k] = av[i][j];
		concatenated[k] = '\n';
		k++;
	}
	concatenated[k] = '\0'; /* Add the null terminator */

	return (concatenated);
}
