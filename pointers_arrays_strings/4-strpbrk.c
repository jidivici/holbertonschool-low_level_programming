#include "main.h"
#include <stdio.h>
/**
 * _strpbrk - searches a string for any of a set of bytes
 * @s: string to scan
 * @accept: string containing the characters to match
 *
 * Return: pointer to the first character in s that matches
 * one of the characters in accept, or NULL if no match is found
 */
char *_strpbrk(char *s, char *accept)
{
	int i = 0, j = 0;

	if (accept == NULL || accept == s || s == NULL)
		return (NULL);
	for (; s[i] != '\0'; i++)
	{
		for (j = 0; accept[j] != '\0'; j++)
		{
			if (s[i] == accept[j])
				return (&s[i]);
		}
	}
	return (NULL);
}
