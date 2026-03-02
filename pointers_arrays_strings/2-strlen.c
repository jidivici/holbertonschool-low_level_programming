#include <stdio.h>
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
