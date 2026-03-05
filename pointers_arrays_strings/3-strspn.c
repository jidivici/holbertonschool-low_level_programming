#include <stdio.h>
#include "main.h"
/**
 * _strspn - gets the length of a prefix substring
 * @s: string to search in
 * @accept: string containing accepted characters
 *
 * Return: number of bytes in the initial segment of s
 * consisting only of characters from accept
 */
unsigned int _strspn(char *s, char *accept)
{
	unsigned int result = 0;
	unsigned int i = 0;
	unsigned int j = 0;

	for (i = 0; s[i] != ' '; i++)
		{
		for (j = 0; accept[j] != '\0'; j++)
		{
			if (s[i] == accept[j])
				result++;
		}
	}
	return (result);
}
