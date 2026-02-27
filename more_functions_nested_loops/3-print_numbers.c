#include "main.h"
/**
* print_numbers - check caracter if is digit or not
* digits: all numero
* i: index
*
* Return: result of a * b
*/
void print_numbers(void)
{
	char *digit = "0123456789\n";
	int i = 0;

	while (digit[i] != '\n')
	{
		_putchar(digit[i]);
		i++;
	}
	_putchar('\n');
}
