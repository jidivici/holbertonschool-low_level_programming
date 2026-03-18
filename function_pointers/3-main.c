#include "3-calc.h"
#include <stdlib.h>
/**
 * main - entry point of the calculator program
 * @argc: number of arguments
 * @argv: array of arguments (number1 operator number2)
 *
 * Description: this program performs a simple calculation based on the
 * operator provided as argument. It selects the correct function using
 * get_op_func and applies it to the given operands.
 *
 * Return: 0 on success, 98 on error
 */
int main(int argc, char **argv)
{
	int a = 0, b = 0;
	int (*op)(int a, int b) = NULL;

	if (argc != 4)
	{
		printf("Error\n");
		exit(98);
	}
	a = atoi(argv[1]);
	b = atoi(argv[3]);
	op = get_op_func(argv[2]);
	if (op == NULL)
	{
		printf("Error\n");
		exit(99);
	}
	printf("%d\n", op(a, b));
	return (0);
}
