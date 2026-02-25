#include <stdlib.h>
#include "main.h"
/**
* print_alphabet_x10 - writes alphabet 10x S/output
* i: num of rep
* c: select letter
*
* Return: None
*/
void print_alphabet_x10(void)
{
	int i;
	char c;

	for (i = 0; i < 10; i++)
	{
		for (c = 'a'; c <= 'z'; c++)
			_putchar(c);
		_putchar('\n');
	}
}

