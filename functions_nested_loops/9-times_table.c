#include <stdlib.h>
#include "main.h"
/**
* jack_bauer - print all clock from 00:00 to 23:59
*
* Return: int positive or neg
*/
void main(void)
{
	int i = 0;
	int j = 0;
	int result = 0;

	for (i = 0; i <= 9; i++)
	{
		for (j = 0; j <= 9; j++)
		{
			result = i * j;

			if (j != 0)
			{
				_putchar(',');
				_putchar(' ');
			}

			if (result >= 10)
				_putchar((result / 10) + '0');
			else
				_putchar(' ');

			_putchar((result % 10) + '0');
		}
		_putchar('\n');
	}
}
