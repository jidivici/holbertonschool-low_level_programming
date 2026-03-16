#include "main.h"
#include <stdio.h>
#include <stdlib.h>

/**
* _strcpy - function copy string src to dest
* @dest: array you want print
* @src: taille de l array
*
* Return: char *
*/
char *_strcpy(char *dest, char *src)
{
	char *p = dest;

	while (*src)
	{
		*dest = *src;
		dest++;
		src++;
	}
	*dest = '\0';
	return (p);
}
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
 * argstostr - concatenates all the arguments of a program into a single string
 * @ac: the number of arguments
 * @av: array of strings representing the arguments
 *
 * Return: pointer to a newly allocated string containing all arguments
 *         separated by a newline character, or NULL if ac is 0, av is NULL,
 *         or memory allocation fails
 *
 * Description: This function first calculates the total length required to
 *              store all arguments plus a newline after each one. It then
 *              allocates memory for the resulting string, copies each
 *              argument into it sequentially, appends a newline after each,
 *              and finally terminates the string with a null character.
 */
char *argstostr(int ac, char **av)
{
	char *str = NULL;
	int total_len = 0, i = 0, j = 0, k = 0;

	if (ac == 0 || av == NULL)
		return (NULL);
	for (i = 0; i < ac; i++)
		total_len += _strlen(av[i]) + 1;
	str = malloc((total_len + 1) * sizeof(char));
	if (str == NULL)
		return (NULL);
	for (i = 0; i < ac; i++)
	{
		for (j = 0; j < _strlen(av[i]); j++)
			str[k++] = av[i][j];
		str[k++] = '\n';
	}
	str[k] = '\0';
	return (str);
}
