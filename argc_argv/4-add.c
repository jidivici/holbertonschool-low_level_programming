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
 * is_number - checks if a string contains only digits
 * @s: string to check
 *
 * Return: 1 if the string is a number, 0 otherwise
 */
int is_number(char *s)
{
	int i = 0;

	while (s[i] != '\0')
	{
		if (s[i] < '0' || s[i] > '9')
			return (0);
		i++;
	}
	return (1);
}
/**
 * main - prints addition of argumments
 * @argc: number of command line arguments
 * @argv: array of command line arguments
 *
 * Return: 0 on success 1 if error
 */
int main(int argc, char **argv)
{
	int i = 1, result = 0;

	for (; i < argc; i++)
	{
		if (!is_number(argv[i]))
		{
			printf("Error\n");
			return (1);
		}
		result += _atoi(argv[i]);
	}
	printf("%d\n", result);
	return (0);
}
