#include <stdio.h>
#include "main.h"
/**
* _strncat - concatenates n par of src to dest
* @dest: destination string (must have enough space)
* @src: source string to append
* @n: par of src would take
*
* Return: pointer to dest
*/
char *_strncat(char *dest, char *src, int n)
{
	int j = 0;
	char *beg_point = dest;

	while (*dest)
		dest++;
	while (j != n && src[j] != '\0')
	{
		*dest = src[j];
		dest++;
		j++;
	}
	dest[j] = '\0';
	return (beg_point);
}
