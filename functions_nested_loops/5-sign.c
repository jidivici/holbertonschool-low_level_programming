#include <stdlib.h>
#include "main.h"
/**
* print_sign -  S/output
* @n: for number
*
* Return: int positive or neg
*/
int print_sign(int n)
{
	if (n == 0)
	{
		_putchar('0');
		return (0);
	}
	if (n < 0)
	{
		_putchar('-');
		return (-1);
	}
	if (n > 0)
	{
		_putchar('+');
		return (1);
	}
	return (0);
}
