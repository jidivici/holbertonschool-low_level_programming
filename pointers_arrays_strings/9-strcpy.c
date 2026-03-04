#include <stdio.h>
#include "main.h"
/**
* _strcpy - function copy string src to dest
* @dest: array you want print
* @src: taille de l array
*
* Return: char *
*/
char *_strcpy(char *dest, char *src)
{
	char *p = dest;

	while (*src)
	{
		*dest = *src;
		dest++;
		src++;
	}
	*dest = '\0';
	return (p);
}
