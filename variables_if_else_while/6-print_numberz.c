#include <stdio.h>
/**
* main - entry point
*
* Return: 0 (sucess)
*/
int main(void)
{
	int i = 0;
	char *number="0123456789\n";

	while (number[i] != '\n')
	{
		putchar(number[i]);
		i++;
	}
	putchar('\n');
	return (0);
}
