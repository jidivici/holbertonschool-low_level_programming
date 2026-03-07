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

/**
 * main - prints multiplication of argumments
 * @argc: number of command line arguments
 * @argv: array of command line arguments
 *
 * Return: 0 on success
 */
int main(int argc, char **argv)
{
	int i = 1, result = 1;

	if (argc <= 1)
	{
		printf("Error\n");
		return (1);
	}
	for (; i < argc; i++)
		result = result * _atoi(argv[i]);
	printf("%d\n", result);
	return (0);
}
