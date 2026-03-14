#include <stdio.h>
#include <stdlib.h>
#include "dog.h"
/**
 * free_dog - free the memory allocated for a dog structure
 * @d: pointer to the dog structure to free
 *
 * Return: nothing
 */
void free_dog(dog_t *d)
{
	free(d->name);
	free(d->owner);
	free(d);
}