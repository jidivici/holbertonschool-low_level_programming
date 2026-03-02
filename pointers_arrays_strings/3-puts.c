#include <stdio.h>
/**
* _puts - print string with \n
* @s: string printed
*
* Return: result of a * b
*/
int _puts(char *s)
{
	int i = 0;

	while (s[i] != '\0'|| s[i] != '\n')
	{
		putchar(s[i]);
		i++;
	}
	putchar('\n');
	return (0);
}
