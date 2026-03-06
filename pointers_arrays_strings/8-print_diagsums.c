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
	int i = 0, j = 0;

	for (i = 0; i < size; i++)
		{
		for (j = 0; j < size; j++)
			printf("%d\t", a[i * size + j]);
		}
	printf("\n");
}
