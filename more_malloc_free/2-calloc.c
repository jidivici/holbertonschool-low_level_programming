#include "main.h"
#include <stdlib.h>
#include "main.h"
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
/**
 * _calloc - allocates memory for an array using malloc
 * @nmemb: number of elements in the array
 * @size: size of each element in bytes
 *
 * Return: pointer to the allocated memory initialized to 0,
 * or NULL if the allocation fails
 */
void *_calloc(unsigned int nmemb, unsigned int size)
{
	char *ptr = NULL;
	unsigned int i = 0;

	if (size == 0 || nmemb == 0)
		return (NULL);
	ptr = malloc(nmemb * size);
	if (ptr == NULL)
		return (NULL);
	for (i = 0; i < nmemb * size; i++)
		ptr[i] = 0;
	return (ptr);
}
