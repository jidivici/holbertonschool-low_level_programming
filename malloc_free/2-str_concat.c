#include "main.h"
#include <stdlib.h>
#include <stdio.h>
/**
* _strlen - return len of str
* @s: char str
*
* Return: result of a * b
*/
int _strlen(char *s)
{
	int i = 0;

	while (s[i] != '\0')
		i++;
	return (i);
}
/**
 * str_concat - concatenates two strings into a newly allocated memory
 * @s1: first string
 * @s2: second string
 *
 * Return: pointer to the new string containing s1 followed by s2,
 * or NULL if memory allocation fails
 */
char *str_concat(char *s1, char *s2)
{
	int len = _strlen(s1) + _strlen(s2) + 1;
	int i = 0, j = 0, len_s1 = _strlen(s1);
	char *array_1 = _strdup(s1);
	char *array_2 = _strdup(s2);
	char *concat_arr = malloc(len * sizeof(char));

	if (concat_arr == NULL)
		return (NULL);
	while (array_1[i] != '\0' && array_2[j] != '\0')
	{
		concat_arr[i] = array_1[i];
		concat_arr[j + len_s1] = array_2[j];
		i++, j++;
	}
	concat_arr[i] = '\0';
	return (concat_arr);
}
