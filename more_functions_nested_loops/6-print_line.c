#include "main.h"
/**
* print_line - print n '_'
* @n: iteration of '_'
*
* Return: void
*/
void print_line(int n)
{
	if (n > 0)
	{
		for (; n > 0; n--)
			_putchar('_');
	}
	_putchar('\n');
}
