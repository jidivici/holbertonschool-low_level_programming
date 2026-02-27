#include "main.h"
/**
* more_numbers - check caracter if is digit or not
* digits: all numero
* i: index
* j: repetition
*
* Return: result of a * b
*/
void more_numbers(void)
{
	char *digit = "0135678910111214\n";
	int i, j = 0;

	for (j = 0; j <= 9; j++)
	{
		while (digit[i] != '\n')
		{
			_putchar(digit[i]);
			i++;
		}
		_putchar('\n');
	}
	_putchar('\n');
}
