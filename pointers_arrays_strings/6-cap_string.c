#include "main.h"
#include <stdio.h>
/**
 * separator - checks if a character is a word separator
 * @c: character to check
 *
 * Return: 1 if c is a separator, 0 otherwise
 */
int separator(char c)
{
	char separators[] = " \t\n,;.!?\"(){}";
	int i = 0;

	for (; separators[i] != '\0'; i++)
	{
		if (separators[i] == c)
			return (1);
	}
	return (0);
}
/**
 * cap_string - capitalizes the first letter of each word in a string
 * @s: string to modify
 *
 * Return: pointer to the modified string
 */
char *cap_string(char *s)
{
	int i = 0;
	char *beg_point = s;

	while (s[i] != '\0')
	{
		if (s[i] >= 'a' && s[i] <= 'z' && separator(s[i - 1]))
			s[i] = (s[i] - 32);
		i++;
	}
	return (beg_point);
}
