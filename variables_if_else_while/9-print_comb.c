#include <stdio.h>
/**
* main - entry point
*
* Return: 0 (sucess)
*/
void separator(void)
{
	putchar(',');
	putchar(' ');
}

int main(void)
{
	char c = '0';

	for (c = '0'; c <= '9'; c++)
	{
		putchar(c);
		if (c == '9') {
			putchar('\n');
			return (0);
		}
		separator();
	}
	return (0);
}
