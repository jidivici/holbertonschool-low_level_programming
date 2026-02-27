#include <stdlib.h>
#include "main.h"
/**
* print_to_98 - print n -> 98 number
* @n: number where begin the program
*
* Return: none
*/
void print_to_98(int n)
{

	while (n != 98)
		{
		if (n < 0)
		{
			_putchar('-');
			n = -n;
			if ((n / 10) != 0)
				_putchar(n / 10 + '0');
			_putchar(n % 10 + '0');
			_putchar(',');
			_putchar(' ');
			n = -n;
		}
		if (n >= 0 && n <= 99)
		{
			if ((n / 10) != 0)
				_putchar(n / 10 + '0');
			_putchar(n % 10 + '0');
			_putchar(',');
			_putchar(' ');
		}
		if (n > 99)
		{
			if (n / 100 != 0)
				_putchar((n / 100) + '0');
			_putchar((n / 10) % 10 + '0');
			_putchar(n % 10 + '0');
			_putchar(',');
			_putchar(' ');
		}
		if (n > 98)
			n--;
		else
			n++;
	}
	_putchar('9');
	_putchar('8');
	_putchar('\n');
}
