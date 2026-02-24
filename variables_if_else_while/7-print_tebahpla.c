#include <stdio.h>
/**
* main - entry point
*
* Return: 0 (sucess)
*/
int main(void)
{
	int i = 0;
	char *number = "zyxwvutsrqponmlkjihgfedcba\n";

	while (number[i] != '\n')
	{
		putchar(number[i]);
		i++;
	}
	putchar('\n');
	return (0);
}
