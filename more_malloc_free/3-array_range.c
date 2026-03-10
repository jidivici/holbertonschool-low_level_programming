#include "main.h"
#include <stdlib.h>
/**
 * array_range - creates an array of integers from min to max
 * @min: the minimum value to include in the array
 * @max: the maximum value to include in the array
 *
 * Return: pointer to the newly allocated array, or NULL if
 *         min > max or if memory allocation fails
 */
int *array_range(int min, int max)
{
	int *ptr = NULL;
	int i = 0;

	if (min > max)
		return (NULL);
	ptr = malloc((max - min + 1) * sizeof(int));
	if (ptr == NULL)
		return (NULL);
	for (i = min; i <= max; i++)
		ptr[i] = min + i;
	return (ptr);
}
