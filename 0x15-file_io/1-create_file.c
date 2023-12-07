#include <stdio.h>
#include <stdlib.h>
#include <fcntl.h>
#include <unistd.h>
#include "main.h"
#include <string.h>

/**
 * create_file - Creates a file and writes text content to it.
 * @filename: The name of the file to create.
 * @text_content: A NULL-terminated string to write to the file.
 *
 * Return: 1 on success, -1 on failure.
 */
int create_file(const char *filename, char *text_content)
{
	int text_file;
	int bytes_written;

	if (filename == NULL)
		return (-1);

	text_file = open(filename, O_WRONLY | O_CREAT | O_TRUNC, 0600);

	if (text_file == -1)
		return (-1);

	if (text_content != NULL)
	{
		bytes_written = write(text_file, text_content, strlen(text_content));

		if (bytes_written == -1)
		{
			close(text_file);
			return (-1);
		}
	}

	close(text_file);
	return (1);
}

