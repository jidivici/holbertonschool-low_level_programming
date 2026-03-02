#include <stdio.h>
#include "main.h"
/**
* _strlen - return len of table
* @s: table would take mesure
*
* Return: int len of table
*/
int _strlen(char *s)
{
	int i = 0;

	while (s[i] != '\0')
		i++;
	return (i);
}
/**
* puts_half - print half table
* @str: char would print half
*
* Return: nothing
*/
void puts_half(char *str)
{
	int i = 0;
	int j = _strlen(str) / 2;

	while (str[i] != '\0')
	{
		if (i >= j)
			_putchar(str[i]);
		i++;
	}
	_putchar('\n');
}
