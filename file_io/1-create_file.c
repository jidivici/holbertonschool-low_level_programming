#include "main.h"
#include <stdio.h>
#include <fcntl.h>
#include <stdlib.h>
#include <unistd.h>
/**
 * create_file - Creates a file and writes text content into it
 * @filename: Name of the file to create
 * @text_content: Content to write into the file
 *
 * Description:
 * The file is created with permissions rw-------
 * If the file already exists, it is truncated.
 *
 * Return: 1 on success, -1 on failure
 */
int create_file(const char *filename, char *text_content)
{
	int fd, len = 0;

	if (!filename)
		return (0);
	fd = open(filename, O_CREAT | O_WRONLY | O_TRUNC, 0600);
	if (fd == -1)
		return (-1);
	if (text_content)
	{
		while (text_content[len])
			len++;
		if (write(fd, text_content, len) == -1)
		{
			close(fd);
			return (0);
		}
	}
	close(fd);
	return (1);
}
