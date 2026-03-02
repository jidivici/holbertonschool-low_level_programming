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
* print_rev - print string reverse
* @s: pointer str print
*
* Return: nothing
*/
void print_rev(char *s)
{
	int i = _strlen(s);

	while (i >= 0)
	{
		_putchar(s[i]);
		i--;
	}
	_putchar('\n');
}
