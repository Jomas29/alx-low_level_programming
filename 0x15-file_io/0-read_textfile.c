#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <fcntl.h>
#include "main.h"

/**
 * read_textfile - Reads a text file and prints it to the POSIX
 * @filename: The name of the file to read.
 * @letters: The number of letters to read and print.
 *
 * Return: The actual number of letters read and printed.
 */

ssize_t read_textfile(const char *filename, size_t letters)
{
	int file;
	int bytes_read, bytes_written;
	char *buffer;

	if (filename == NULL || letters == 0)
		return (0);

	buffer = malloc(sizeof(char) * (letters));
	if (buffer == NULL)
		return (0);

	file = open(filename, O_RDONLY);
	if (file == -1)
	{
		free(buffer);
		return (0);
	}

	bytes_read = read(file, buffer, letters);
	if (bytes_read == -1)
	{
		free(buffer);
		close(file);
		return (0);
	}

	bytes_written = write(STDOUT_FILENO, buffer, bytes_read);
	free(buffer);
	close(file);
	if (bytes_written != bytes_read)
		return (0);
	return (bytes_read);
}
