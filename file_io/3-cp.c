#include "main.h"
/**
 * exit_usage - prints usage error message and exits with code 97
 *
 * Return: void
 */
static void exit_usage(void)
{
	dprintf(STDERR_FILENO, "Usage: cp file_from file_to\n");
	exit(97);
}
/**
 * exit_read_error - prints read error message,
 * closes fds, and exits with code 98
 * @file_from: name of the file that cannot be read
 * @fd_from: file descriptor of source file
 * @fd_to: file descriptor of destination file
 *
 * Return: void
 */
static void exit_read_error(const char *file_from, int fd_from, int fd_to)
{
	dprintf(STDERR_FILENO, "Error: Can't read from file %s\n", file_from);
	if (fd_from != -1)
		close(fd_from);
	if (fd_to != -1)
		close(fd_to);
	exit(98);
}
/**
 * exit_write_error - prints write error
 * message, closes fds, and exits with code 99
 * @file_to: name of the file that cannot be written to
 * @fd_from: file descriptor of source file
 * @fd_to: file descriptor of destination file
 *
 * Return: void
 */
static void exit_write_error(const char *file_to, int fd_from, int fd_to)
{
	dprintf(STDERR_FILENO, "Error: Can't write to %s\n", file_to);
	if (fd_from != -1)
		close(fd_from);
	if (fd_to != -1)
		close(fd_to);
	exit(99);
}
/**
 * exit_close_error - prints close error message and exits with code 100
 * @fd: file descriptor that failed to close
 *
 * Return: void
 */
static void exit_close_error(int fd)
{
	dprintf(STDERR_FILENO, "Error: Can't close fd %d\n", fd);
	exit(100);
}
/**
 * main - copies the content of one file to another
 * @argc: number of arguments passed to the program
 * @argv: array of arguments:
 *        argv[1] is the source file
 *        argv[2] is the destination file
 *
 * Description: opens the source file in read mode and the destination
 * file in write mode, then copies the content using a 1024-byte buffer.
 * Handles all possible errors according to specifications.
 *
 * Return: 0 on success
 */
int main(int argc, char *argv[])
{
	int fd_from = -1, fd_to = -1, r, w;
	char buffer[1024];

	if (argc != 3)
		exit_usage();
	fd_from = open(argv[1], O_RDONLY);
	if (fd_from == -1)
		exit_read_error(argv[1], -1, -1);
	fd_to = open(argv[2], O_WRONLY | O_CREAT | O_TRUNC, 0664);
	if (fd_to == -1)
		exit_write_error(argv[2], fd_from, -1);
	while ((r = read(fd_from, buffer, 1024)) > 0)
	{
		w = write(fd_to, buffer, r);
		if (w != r)
			exit_write_error(argv[2], fd_from, fd_to);
	}
	if (r == -1)
		exit_read_error(argv[1], fd_from, fd_to);
	if (close(fd_from) == -1)
		exit_close_error(fd_from);
	if (close(fd_to) == -1)
		exit_close_error(fd_to);
	return (0);
}
