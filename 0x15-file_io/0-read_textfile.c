#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <fcntl.h>
#include "main.h"

/**
 * reading_textfile - Reads a text file and prints it to POSIX
 * @filename: The name of the file to reading.
 * @letters: The number of letters to reading and print.
 *
 * Return: The actual number of letters reading and printed.
 */
ssize_t read_textfile(const char *filename, size_t letters)
{
	int fln, reading, written;
	char *thread;

	if (filename == NULL)
		return (0);

	fln = open(filename, O_RDONLY);
	if (fln == -1)
		return (0);

	thread = malloc(letters);
	if (thread == NULL)
	{
		close(fln);
		return (0);
	}

	reading = read(fln, thread, letters);
	if (reading == -1)
	{
		free(thread);
		close(fln);
		return (0);
	}

	written = write(STDOUT_FILENO, thread, reading);
	free(thread);
	close(fln);

	if (written == reading)
		return (written);

	return (0);
}

