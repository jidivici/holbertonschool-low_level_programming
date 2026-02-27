#include <stdio.h>
/**
* print_table - print table multiplication
* @size: number of table
*
* Return: none
*/
void print_table(int size)
{
	int row, col;

	for (row = 1; row <= size; row++)
	{
		for (col = 1; col <= size; col++)
			printf("%d ", row * col);
		printf("\n");
	}
}

/**
* main - print somme
*
* Return: 0
*/
int main(void)
{
	print_table(4);
	return (0);
}
