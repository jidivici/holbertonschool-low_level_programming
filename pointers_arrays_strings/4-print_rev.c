#include <stdio.h>
#include "main.h"
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
		putchar(s[i]);
		i--;
	}
	putchar('\n');
}
