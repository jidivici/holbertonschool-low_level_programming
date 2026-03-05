#include <stdio.h>
#include "main.h"
/**
 * _memcpy - copies memory area n char of src in dest
 * @dest: destination buffer where bytes are copied
 * @src: source buffer to copy from
 * @n: number of bytes to copy
 *
 * Return: pointer to the destination buffer
 */
char *_memcpy(char *dest, char *src, unsigned int n)
{
	unsigned int i = 0;

	while (i < n)
		{
		dest[i] = src[i];
		i++;
		}
	return (dest);
}
