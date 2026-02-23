#include <stdio.h>

/**
* main - entry point
*
* Return: 0 (sucess)
*/

int main(void)
{
	int i;
	float f;
	long int l;
	long long int ll;
	char c;

	printf("Size of a char: %d bytes(s)\n", (int)sizeof(c));
	printf("Size of an int: %d bytes(s)\n", (int)sizeof(i));
	printf("Size of a long int: %d bytes(s)\n", (int)sizeof(l));
	printf("Size of a long long int: %d bytes(s)\n", (int)sizeof(ll));
	printf("Size of a float: %d bytes(s)\n", (int)sizeof(f));
	return (0);
}
