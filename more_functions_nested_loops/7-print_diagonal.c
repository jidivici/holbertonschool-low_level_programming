#include "main.h"
/**
* print_diagonal - print n '/'
* @n: iteration of diagonale with '\'
*
* Return: void
*/
void print_diagonal(int n)
{
	int i, j;

	for (i = 0; i < n && n > 0; i++)
	{
		for (j = 0; j < n; j++)
			{
			if (j == i)
				_putchar('\\');
			else if (j < i)
				_putchar(' ');
			}
		_putchar('\n');
	}
	if (n <= 0)
		_putchar('\n');
}
