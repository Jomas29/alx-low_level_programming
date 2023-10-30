#include <stdio.h>
#include <stdlib.h>
#include <fcntl.h>
#include <unistd.h>

#define BUFFER_SIZE 1024

/**
 * handle_error - Handles errors and exits the program
 *
 * @code: The exit code.
 * @file_name: The name of the file associated with the error.
 * @fd_from: File descriptor for the source file.
 * @fd_to: File descriptor for the destination file.
 */
void handle_error(int code, const char *file_name, int fd_from, int fd_to)
{
	switch (code)
	{
		case 97:
			dprintf(2, "Usage: cp file_from file_to\n");
			break;
		case 98:
			dprintf(2, "Error: Can't read from file %s\n", file_name);
			break;
		case 99:
			dprintf(2, "Error: Can't write to %s\n", file_name);
			break;
		case 100:
			dprintf(2, "Error: Can't close fd %d\n", fd_from);
			break;
		default:
			break;
	}
	if (fd_from != -1)
		close(fd_from);
	if (fd_to != -1)
		close(fd_to);
	exit(code);
}

/**
 * main -  Copies the content of one file to another file.
 *
 * @ac: The number of arguments.
 * @av: The array of arguments.
 *
 * Return: 0 on success, various exit codes on failure.
 */
int main(int ac, char **av)
{
	int fd_from, fd_to;
	ssize_t read_bytes, write_bytes;
	char buffer[BUFFER_SIZE];

	if (ac != 3)
		handle_error(97, NULL, -1, -1);


	fd_from = open(av[1], O_RDONLY);
	if (fd_from == -1)
		handle_error(98, av[1], -1, -1);


	fd_to = open(
			av[2],
			O_WRONLY | O_CREAT | O_TRUNC,
			S_IRUSR | S_IWUSR | S_IRGRP | S_IWGRP | S_IROTH
		    );
	if (fd_to == -1)
		handle_error(99, av[2], fd_from, -1);


	while ((read_bytes = read(fd_from, buffer, BUFFER_SIZE)) > 0)
	{
		write_bytes = write(fd_to, buffer, read_bytes);
		if (write_bytes == -1 || write_bytes != read_bytes)
			handle_error(99, av[2], fd_from, fd_to);

	}

	if (read_bytes == -1)
		handle_error(98, av[1], fd_from, fd_to);

	if (close(fd_from) == -1 || close(fd_to) == -1)
		handle_error(100, NULL, fd_from, fd_to);

	return (0);
}

