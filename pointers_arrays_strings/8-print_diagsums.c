#include "main.h"
#include <stdio.h>
/**
 * print_diagsums - prints the sum of the two diagonals of a square matrix
 * @a: pointer to the first element of the matrix
 * @size: size of the square matrix
 *
 * Return: nothing
 */
void print_diagsums(int *a, int size)
{

	int i = 0, left_diag = 0, right_diag = 0;

	for (i = 0; i < size; i++)
	{
		left_diag = left_diag + a[i * size + i];
		right_diag = right_diag + a[i * size + (size - 1 - i)];
	}
	printf("%d, %d\n", left_diag, right_diag);
}
