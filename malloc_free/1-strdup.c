#include "main.h"
#include <stdlib.h>
/**
 * _strdup - returns a pointer to a newly allocated space in memory
 * which contains a copy of the string given as a parameter
 * @str: string to duplicate
 *
 * Return: pointer to the duplicated string, or NULL if str is NULL
 * or if memory allocation fails
 */
char *_strdup(char *str)
{
	char *array;
	int i = 0;

	if (str == NULL)
		return (NULL);
	while (str[i] != '\0')
		i++;
	array = malloc(sizeof(char) * (i + 1));
	if (array == NULL)
		return (NULL);
	for (i = 0; str[i] != '\0'; i++)
		array[i] = str[i];
	array[i] = '\0';
	return (array);
}
