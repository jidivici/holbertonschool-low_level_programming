#include <stdio.h>
#include "main.h"
/**
* print_array - print int array
* @a: array you want print
* @n: taille de l array
*
* Return: nothing
*/
void print_array(int *a, int n)
{
	int i = 0;

	for (i = 0; i < n; i++)
		{
		printf("%d", a[i]);
		if (i < n - 1)
			printf(", ");
		}
	printf("\n");
}
