#include "main.h"
#include <stdio.h>
#include <stdlib.h>
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
		int n, fd;
		char *buff = NULL;

		buff = malloc(letters * sizeof(char) + 1);
		fd = open(filename, O_RDONLY);
		if (fd == -1)
			return (-1);
		n = read(fd, buff, letters);
		if (n == -1)
			return (-1);
		buff[n] = '\0';
		write(1, buff, letters);
		close(fd);
		free(buff);
		return (n);
}
