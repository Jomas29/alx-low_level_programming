#include "main.h"
#include <stdlib.h>
#include <string.h>

/**
 * strtow - Splits a string into words
 * @str: The string to split
 *
 * Return: Pointer to an array of strings (words), or NULL if it fails
 */
char **strtow(char *str)
{
	char **words, *word;
	int i, j, k, count = 0, len = 0;

	if (str == NULL || *str == '\0')
		return (NULL);

	for (i = 0; str[i]; i++)
		count += (str[i] != ' ' && (str[i + 1] == ' ' || str[i + 1] == '\0'));

	words = malloc((count + 1) * sizeof(char *));
	if (words == NULL)
		return (NULL);

	for (i = 0, j = 0; str[i]; i++)
	{
		if (str[i] != ' ')
		{
			len = 0;
			while (str[i + len] != ' ' && str[i + len])
				len++;

			word = malloc((len + 1) * sizeof(char));
			if (word == NULL)
			{
				for (k = 0; k < j; k++)
					free(words[k]);
				free(words);
				return (NULL);
			}

			for (k = 0; k < len; k++)
				word[k] = str[i++];
			word[k] = '\0';

			words[j++] = word;
		}
	}

	words[j] = NULL;
	return (words);
}
