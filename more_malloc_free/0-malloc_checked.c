#include "main.h"
#include <stdlib.h>
/**
 * malloc_checked - allocates memory using malloc
 * @b: number of bytes to allocate
 *
 * Return: pointer to the allocated memory
 * if malloc fails, the process is terminated with status 98
 */
void *malloc_checked(unsigned int b)
{
	return malloc((size_t) b);
}
