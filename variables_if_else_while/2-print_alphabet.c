#include <stdio.h>
/**
* main - entry point
*
* Return: 0 (sucess)
*/
int main(void)
{
	char *alphabet = "abcdefghijklmnopqrstuvwxyz\n";
	int i = 0;

	while (alphabet[i] != '\n')
		putchar(alphabet[i++]);
	putchar('\n');
	return (0);
}
