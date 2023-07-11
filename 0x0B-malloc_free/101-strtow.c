#include "main.h"
#include <stdlib.h>
#include <string.h>

/**
 * count_words - Counts the number of words in a string
 * @str: The string to count words from
 *
 * Return: Number of words in the string
 */
int count_words(char *str)
{
	int count = 0;
	int in_word = 0;
	int i;

	for (i = 0; str[i] != '\0'; i++)
	{
		if (str[i] != ' ')
		{
			if (!in_word)
			{
				in_word = 1;
				count++;
			}
		}
		else
		{
			in_word = 0;
		}
	}

	return (count);
}

/**
 * allocate_words - Allocates memory for an array of words
 * @word_count: Number of words
 *
 * Return: Pointer to the allocated array of words, or NULL if it fails
 */
char **allocate_words(int word_count)
{
	char **words;

	words = malloc((word_count + 1) * sizeof(char *));
	if (words == NULL)
		return (NULL);

	return (words);
}

/**
 * extract_word - Extracts a word from a string
 * @str: The string to extract from
 * @start: Starting index of the word in the string
 * @length: Length of the word
 *
 * Return: Pointer to the extracted word, or NULL if it fails
 */
char *extract_word(char *str, int start, int length)
{
	int i;
	char *word;

	word = malloc((length + 1) * sizeof(char));
	if (word == NULL)
		return (NULL);

	for (i = 0; i < length; i++)
		word[i] = str[start + i];
	word[i] = '\0';

	return (word);
}

/**
 * strtow - Splits a string into words
 * @str: The string to split
 *
 * Return: Pointer to an array of strings (words), or NULL if it fails
 */
char **strtow(char *str)
{
	char **words;
	int word_count, word_index = 0;
	int word_start = -1;
	int i, j;

	if (str == NULL || *str == '\0')
		return (NULL);

	word_count = count_words(str);
	if (word_count == 0)
		return (NULL);

	words = allocate_words(word_count);
	if (words == NULL)
		return (NULL);

	for (i = 0; str[i] != '\0'; i++)
	{
		if (str[i] != ' ')
		{
			if (word_start == -1)
				word_start = i;
		}
		else
		{
			if (word_start != -1)
			{
				int word_length = i - word_start;
				char *word = extract_word(str, word_start, word_length);

				if (word == NULL)
				{
					for (j = 0; j < word_index; j++)
						free(words[j]);
					free(words);
					return (NULL);
				}

				words[word_index++] = word;

				word_start = -1;
			}
		}
	}

	if (word_start != -1)
	{
		int word_length = i - word_start;
		char *word = extract_word(str, word_start, word_length);

		if (word == NULL)
		{
			for (j = 0; j < word_index; j++)
				free(words[j]);
			free(words);
			return (NULL);
		}

		words[word_index++] = word;
	}

	words[word_index] = NULL;

	return (words);
}
