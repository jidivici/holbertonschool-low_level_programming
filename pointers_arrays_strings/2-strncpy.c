#include <stdio.h>
#include "main.h"
/**
* _strlen - return len of str
* @s: char str
*
* Return: result of a * b
*/
int _strlen(char *s)
{
	int i = 0;

	while (s[i] != '\0')
		i++;
	return (i);
}

/**
* _strncpy - function copy string n caracter src to dest
* @dest: array you want print
* @src: taille de l array
* @n: number of caracter want to copying
*
* Return: char *
*/
char *_strncpy(char *dest, char *src, int n)
{
	char *p = dest;
	int i = 0;
	int j = _strlen(src);

	for (; i < n; i++)
	{
		if (i >= j)
			{
			*dest = '\0';
			dest++;
			}
		else
		{
			*dest = *src;
			dest++;
			src++;
		}
	}
	return (p);
}
