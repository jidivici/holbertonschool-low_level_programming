#include <stdio.h>
/**
* row_sum - row * col
* @row: ligne
* @cols: colonne
*
* Return: none
*/
int row_sum(int row, int cols)
{
	int c;
	int sum = 0;

	for (c = 1; c <= cols; c++)
		sum += row * c;

	return (sum);
}
/**
* total_sum - sum * row
* @rows: ligne
* @cols: colonne
*
* Return: total
*/
int total_sum(int rows, int cols)
{
	int r;
	int total = 0;
	int current = 0;

	for (r = 1; r <= rows; r++)
	{
		current += row_sum(r, cols);
		total = current;
	}

	return (total);
}

/**
* main - row * sum
*
* Return: none
*/
int main(void)
{
	printf("%d\n", total_sum(3, 3));
	return (0);
}
