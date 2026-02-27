#include "main.h"
/**
* print_most_numbers - check caracter if is digit or not
* digits: all numero
* i: index
*
* Return: result of a * b
*/
void print_most_numbers(void)
{
	char *digit = "01356789\n";
	int i = 0;

	while (digit[i] != '\n')
	{
		_putchar(digit[i]);
		i++;
	}
	_putchar('\n');
}
