#include <stdio.h>
#include "dog.h"
/**
 * init_dog - initialize a struct dog with given values
 * @d: pointer to the dog structure to initialize
 * @name: name of the dog
 * @age: age of the dog
 * @owner: owner of the dog
 *
 * Return: nothing
 */
void init_dog(struct dog *d, char *name, float age, char *owner)
{
	if (d == NULL)
		return;
	d->name = name;
	d->age = age;
	d->owner = owner;
}
