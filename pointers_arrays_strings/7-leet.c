#include "main.h"
#include <stdio.h>
/**
 * leet - encodes a string into 1337 (leet) speak
 * @s: string to encode
 *
 * Return: pointer to the modified string
 */
char *leet(char *s)
{
	int i = 0, j = 0;
	char *letters = "aAeEoOtTlL";
	char *numbers = "4433007711";

	for (; s[i] != '\0'; i++)
	{
		for (j = 0; letters[j] != '\0'; j++)
		{
			if (s[i] == letters[j])
				s[i] = numbers[j];
		}
	}
	return (s);
}
