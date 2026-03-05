#include "main.h"
#include <stdio.h>
/**
 * _memset - fills char * with a constant byte n time
 * @s: pointer to the memory area to fill
 * @b: byte used to fill the memory
 * @n: number of bytes to fill
 *
 * Return: pointer to the filled memory area
 */
char *_memset(char *s, char b, unsigned int n)
{
	unsigned int i = 0;

	if (s == NULL)
		return (NULL);
	while (i <= n - 1)
	{
		s[i] = b;
		i++;
	}
	return (s);
}
