#include "main.h"
/**
 * reverse_array - reverse the content of an array of integers
 * @a: array of integers to reverse
 * @n: number of elements in the array
 *
 * Return: void
 */
void reverse_array(int *a, int n)
{
	int i = 0;
	int temp;

	if (n <= 1)
		return;

	for (i = 0; i < n / 2; i++)
	{
		temp = a[i];
		a[i] = a[n - 1 - i];
		a[n - 1 - i] = temp;
	}
}
