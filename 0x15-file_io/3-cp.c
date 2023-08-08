#include <stdio.h>
#include <stdlib.h>
#include <fcntl.h>
#include <unistd.h>
#include "main.h"

/**
 * close_and_exit - Closes file descriptors and exits the program.
 * @code: The exit code to use.
 * @fd1: The first file descriptor to close.
 * @fd2: The second file descriptor to close.
 */
void close_and_exit(int code, int fd1, int fd2)
{
	if (fd1 != -1)
		close(fd1);
	if (fd2 != -1)
		close(fd2);
	exit(code);
}

/**
 * read_write_and_exit - Reads from one file descriptor and writes to another.
 * @fln3: The source file descriptor for reading.
 * @fln4: The destination file descriptor for writing.
 * @argv: Array of command-line arguments.
 */
void read_write_and_exit(int fln3, int fln4, char **argv)
{
	ssize_t reading;
	char text[1024];

	while ((reading = read(fln3, text, sizeof(text))) > 0)
	{
		if (write(fln4, text, reading) == -1)
		{
			dprintf(2, "Error: Can't write to %s\n", argv[2]);
			close_and_exit(99, fln3, fln4);
		}
	}
	if (reading == -1)
	{
		dprintf(2, "Error: Can't read from %s\n", argv[1]);
		close_and_exit(98, fln3, fln4);
	}
}

/**
 * main - Entry point of the program.
 * @argc: The number of command-line arguments.
 * @argv: An array of strings containing the arguments.
 * Return: 0 on success, or an appropriate exit code on failure.
 */
int main(int argc, char **argv)
{
	int fln3, fln4;

	if (argc != 3)
	{
		dprintf(2, "Usage: %s file_from file_to\n", argv[0]);
		exit(97);
	}

	fln3 = open(argv[1], O_RDONLY);
	if (fln3 == -1)
	{
		dprintf(2, "Error: Can't read from %s\n", argv[1]);
		exit(98);
	}

	fln4 = open(argv[2], O_WRONLY | O_CREAT | O_TRUNC, 0664);
	if (fln4 == -1)
	{
		dprintf(2, "Error: Can't write to %s\n", argv[2]);
		close(fln3);
		exit(99);
	}

	read_write_and_exit(fln3, fln4, argv);

	close_and_exit(0, fln3, fln4);

	return (0);
}

