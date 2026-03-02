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
	int i = _strlen(s) + 1;

	while (i > 0)
	{
		_putchar(s[i]);
		i--;
	}
	_putchar('\n');
}
