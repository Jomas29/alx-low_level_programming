#include <stdio.h>
#include <stdlib.h>
#include <fcntl.h>
#include <unistd.h>
#include "main.h"

/**
 * main - copies the content of a file to another file
 *
 * @argc: argument count
 * @argv: argument vector
 *
 * Return: Always 0.
 */
int main(int argc, char **argv)
{
	int fln_1, fln_2, reading, written;
	char space[1024];

	if (argc != 3)
	{
		dprintf(STDERR_FILENO, "Usage: %s file_from file_to\n", argv[0]);
		exit(97);
	}

	fln_1 = open(argv[1], O_RDONLY);
	if (fln_1 == -1)
	{
		dprintf(STDERR_FILENO, "Error: Can't read from file %s\n", argv[1]);
		exit(98);
	}

	fln_2 = open(argv[2], O_WRONLY | O_CREAT | O_TRUNC, 0664);
	if (fln_2 == -1)
	{
		dprintf(STDERR_FILENO, "Error: Can't write to %s\n", argv[2]);
		exit(99);
	}

	while ((reading = read(fln_1, space, sizeof(space))) > 0)
	{
		written = write(fln_2, space, reading);
		if (written == -1)
		{
			dprintf(STDERR_FILENO, "Error: Can't write to %s\n", argv[2]);
			close(fln_1);
			close(fln_2);
			exit(99);
		}
	}

	if (reading == -1)
	{
		dprintf(STDERR_FILENO, "Error: Can't read from file %s\n", argv[1]);
		close(fln_1);
		close(fln_2);
		exit(98);
	}

	if (close(fln_1) == -1)
	{
		dprintf(STDERR_FILENO, "Error: Can't close fd %d\n", fln_1);
		exit(100);
	}

	if (close(fln_2) == -1)
	{
		dprintf(STDERR_FILENO, "Error: Can't close fd %d\n", fln_2);
		exit(100);
	}

	return (0);
}

