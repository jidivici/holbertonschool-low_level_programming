#include <stdio.h>
#include "main.h"
/**
* _atoi - function took char return first int content in char
* @s: array you want to take the first int
*
* Return: int
*/
unsigned long _atoi(char *s)
{
	int find = 0, sign = 1;
	unsigned long result = 0;

	while (*s)
		{
		if (*s == '-' && find == 0)
			sign = -sign;
		if (*s >= '0' && *s <= '9')
		{
			result = result * 10 + (*s - '0');
			find = 1;
		}
		else if (find == 1)
			return (sign * result);
		s++;
		}
	return (sign * result);
}
