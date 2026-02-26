#include <stdlib.h>
#include "main.h"
/**
* times_table - print table of 9 with putchar
*
* Return: int positive or neg
*/
void times_table(void)
{
	int i, j, result;

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
