#include <stdio.h>
/**
* main - entry point
*
* Return: 0 (sucess)
*/
int main(void)
{
	char *low_alphabet = "abcdfghijklmnoprstuvwxyz\n";
	int i = 0;

	while (low_alphabet[i] != '\n')
		putchar(low_alphabet[i++]);
	putchar('\n');
	return (0);
}
