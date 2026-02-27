#include <stdio.h>
/**
* sum_to_n - print n -> 98 number
* @n: number of iteration
*
* Return: none
*/
int sum_to_n(int n)
{
	int i;
	int sum = 0;

	for (i = 1; i <= n; i++)
		sum = sum + i;

	return (sum);
}

/**
* main - print somme
*
* Return: 0
*/
int main(void)
{
	printf("%d\n", sum_to_n(10));
	return (0);
}
