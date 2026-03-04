#include <stdio.h>
#include "main.h"
/**
* _strcat - concatenates src to dest
* @dest: destination string (must have enough space)
* @src: source string to append
*
* Return: pointer to dest
*/
char *_strcat(char *dest, char *src)
{
	int	i = 0, j = 0;
	char *beg_point = dest;

	while (dest[i] != '\0')
		i++;
	while (src[j] != '\0')
	{
		dest[i] = src[j];
		i++;
		j++;
	}
	dest[i] = '\0';
	return (beg_point);
}
