#include <stdio.h>
/**
* main - entry point
*
* Return: 0 (sucess)
*/

int main(void)
{
	int i = 0;
	char *number = "0, 1, 2, 3, 4, 5, 6, 7, 8, 9\n";

	while (number[i] != '\n')
	{
		putchar(number[i]);
		i++;
	}
	putchar(',');
	putchar(' ');
	putchar('\n');
	return (0);
}
