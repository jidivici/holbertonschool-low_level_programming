#include <stdio.h>
#include "main.h"
/**
* _strlen - return len of str
* @s: char str
*
* Return: nothibg
*/
int _strlen(char *s)
{
	int i = 0;

	while (s[i] != '\0')
		i++;
	return (i);
}

/**
* rev_string - print reverse str
* @s: char str
*
* Return: nothing
*/
void rev_string(char *s)
{
	int i = _strlen(s) - 1;
	int j = 0;
	char tmp;

	while (i > j)
	{
		tmp = s[j];
		s[j] = s[i];
		s[i] = tmp;
		i--;
		j++;
	}
}
