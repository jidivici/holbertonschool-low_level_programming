#include <stdlib.h>
#include "main.h"
/**
* jack_bauer - give absolute of number n
* @n: for number
*
* Return: int positive or neg
*/
int main (void)
{
	int hours = 0;
	int minutes = 0;

	for (hours = 0; hours < 24; hours++)
	{
		for (minutes  = 0; minutes < 60; minutes++)
		{
			_putchar((hours / 10) + '0');
			_putchar((hours % 10) + '0');
			_putchar(':');
			_putchar((minutes / 10) + '0');
			_putchar((minutes % 10) + '0');
			_putchar('\n');
		}
	}
	return (0);
}
