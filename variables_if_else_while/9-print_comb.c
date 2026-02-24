#include <stdio.h>
/**
* separator - print ', '
*
* Return: none
*/
void separator(void)
{
	putchar(',');
	putchar(' ');
}
/**
* main - entry point
*
* Return: 0 (sucess)
*/
int main(void)
{
	char c = '0';

	for (c = '0'; c <= '9'; c++)
	{
		putchar(c);
		if (c == '9')
		{
			putchar('\n');
			return (0);
		}
		separator();
	}
	return (0);
}
