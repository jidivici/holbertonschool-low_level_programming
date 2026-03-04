#include <stdio.h>
#include "main.h"
/**
* _strcmp - check if two char * identics
* @s1: first str compare
* @s2: second str compare
*
* Return: 0 they are identic or substrc the first caractere diff
*/
int _strcmp(char *s1, char *s2)
{
	while ((*s1 != '\0') && (*s2 != '\0') && (*s1 == *s2))
		return (*s1 - *s2);
	return (*s1 - *s2);
}
