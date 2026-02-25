#include <stdlib.h>
#include "main.h"
#include <stdio.h>
/**
* print_last_digit - give absolute of number n
* @n: for number
*
* Return: int positive or neg
*/
int print_last_digit(int n)
{
	int last_digit = n % 10;

	if (last_digit < 0)
		last_digit = -last_digit;
	_putchar(last_digit + '0');
	return (last_digit);
}
