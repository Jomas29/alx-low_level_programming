#include <fcntl.h>
#include <unistd.h>
#include <stdlib.h>
#include "main.h"

/**
 * create_file - Creates a file and writes text to it
 * @filename: Name of the file to create
 * @text_content: string to write to the file
 *
 * Return: 1 on success, -1 on failure
 */
int create_file(const char *filename, char *text_content)
{
	int fln, written, len;

	if (filename == NULL)
		return (-1);

	fln = open(filename, O_WRONLY | O_CREAT | O_TRUNC, 0600);
	if (fln == -1)
		return (-1);

	if (text_content != NULL)
	{
		len = 0;
		while (text_content[len] != '\0')
			len++;

		written = write(fln, text_content, len);
		if (written == -1)
		{
			close(fln);
			return (-1);
		}
	}

	close(fln);
	return (1);
}

