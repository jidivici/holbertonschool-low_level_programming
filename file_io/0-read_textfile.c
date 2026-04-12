#include "main.h"
#include <stdio.h>
#include <fcntl.h>
#include <stdlib.h>
#include <unistd.h>
/**
 * read_textfile - Reads a text file and prints it to stdout
 * @filename: Name of the file to read
 * @letters: Number of letters to read and print
 *
 * Return: Number of letters actually read and printed
 *         0 if the file cannot be opened or read, or if filename is NULL
 */
ssize_t read_textfile(const char *filename, size_t letters)
{
		int fd;
		ssize_t n;
		char *buff = NULL;

		if (!filename)
			return (0);
		fd = open(filename, O_RDONLY);
		if (fd == -1)
			return (0);
		buff = malloc(letters * sizeof(char));
		if (!buff)
			return (0);
		n = read(fd, buff, letters);
		if (n == -1)
		{
			close(fd);
			free(buff);
			return (0);
		}
		write(1, buff, n);
		free(buff);
		close(fd);
		return (n);
}
