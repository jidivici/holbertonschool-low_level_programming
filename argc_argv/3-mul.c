#include <stdio.h>
#include "main.h"
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
