#include "main.h"
/**
* print_square - forming n*n square with'#'
* @n: indice of the square
*
* Return: void
*/
void print_square(int n)
{
	int i, j;

	for (i = 0; i < n && n > 0; i++)
	{
		for (j = 0; j < n; j++)
		{
			_putchar('#');
		}
		_putchar('\n');
	}
	if (n <= 0)
		_putchar('\n');
}
