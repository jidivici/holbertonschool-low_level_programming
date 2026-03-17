#include <stdio.h>
#include "function_pointers.h"
/**
 * int_index - searches for an integer using a comparison function
 * @array: pointer to the array of integers
 * @size: number of elements in the array
 * @cmp: pointer to a function used to compare values
 *
 * Return: index of the first element for which cmp returns non-zero,
 * or -1 if no element matches or if size is less than or equal to 0
 */
int int_index(int *array, int size, int (*cmp)(int))
{
	int i = 0;

	if (size <= 0 || array == NULL || cmp == NULL)
		return -1;
	for (i = 0; i < size; i++)
	{
		if (cmp(array[i]) == 1)
			break;
	}
	return i;
}
