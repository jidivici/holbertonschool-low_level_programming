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
	if (dest == NULL || src == NULL)
		return NULL;
	char *p = dest;
	while
		((*dest++ = *src++));
	return (p);
}
