#include <stdio.h>
/**
* main - entry point
*
* Return: 0 (sucess)
*/
int main(void)
{
	char *low_alphabet = "abcdefghijklmnopqrstuvwxyz\n";
	char *upp_alphabet = "ABCDEFGHIJKLMNOPQRSTUVWXYZ\n";
	int i = 0;

	while (low_alphabet[i] != '\n')
		putchar(low_alphabet[i++]);
	i = 0;
	while (upp_alphabet[i] != '\n')
		putchar(upp_alphabet[i++]);
	putchar('\n');
	return (0);
}
