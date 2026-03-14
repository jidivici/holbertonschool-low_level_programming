#ifndef MAIN_H
#define MAIN_H

int _putchar(char c);
int _strlen(char *str);
char *_strdup(char *str);
/**
 * struct dog - structure representing a dog
 * @name: name of the dog
 * @age: age of the dog
 * @owner: owner of the dog
 */
typedef struct dog
{
	char *name;
	float age;
	char *owner;
} dog_t;

dog_t *new_dog(char *name, float age, char *owner);
void free_dog(dog_t *d);
#endif
