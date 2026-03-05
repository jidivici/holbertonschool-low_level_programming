#include "main.h"
/**
* _strchr - locate first occur of char in s
* @s: string to search in
* @c: character to locate
*
* Return: pointer to the first occurrence of the character,
* or NULL if the character is not found
*/
char *_strchr(char *s, char c)
{
	while (*s)
	{
		if (*s == c)
			return (s);
		s++;
	}
	return (0);
}
