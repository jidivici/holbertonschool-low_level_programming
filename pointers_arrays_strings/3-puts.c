#include <stdio.h>
#include "main.h"
/**
* _puts - print string with \n
* @s: string printed
*
* Return: result of a * b
*/
int _puts(char *s)
{
	int i = 0;

	while (s[i] != '\0')
	{
		_putchar(s[i]);
		i++;
	}
	_putchar('\n');
	return (0);
}
