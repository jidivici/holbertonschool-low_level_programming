#include <stdio.h>
#include "function_pointers.h"
/**
 * array_iterator - executes a function on each element of an array
 * @array: pointer to the array of integers
 * @size: number of elements in the array
 * @action: pointer to a function applied to each element
 *
 * Return: void
 */
void array_iterator(int *array, size_t size, void (*action)(int))
{
	unsigned int i = 0;

	if (array == NULL || action == NULL || size == 0)
		return;
	for (i = 0; i < size; i++)
		action(array[i]);
}
