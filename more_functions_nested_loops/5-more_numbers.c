#include "main.h"
/**
* more_numbers - check caracter if is digit or not
* digits: all numero
* i: index
* j: repetition
*
* Return: result of a * b
*/
void main(void)
{
	char *digit = "01234567891011121314\n";
	int i, j = 0;

	for (j = 0; j <= 9; j++)
	{
		while (digit[i] != '\n')
		{
			_putchar(digit[i]);
			i++;
		}
		_putchar('\n');
		i = 0;
	}
	if ( j == 1)
		_putchar('\n');
}
