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
	int len1 = 0, len2 = 0;
	int i = 0, j = 0, k = 0;
	char *concat;

	if (s1)
		len1 = _strlen(s1);
	if (s2)
		len2 = _strlen(s2);
	concat = malloc(len1 + len2 + 1);
	if (concat == NULL)
		return (NULL);
	while (i < len1 + len2)
	{
		if (j < len1)
			concat[i] = s1[j++];
		else
			concat[i] = s2[k++];
		i++;
	}
	concat[i] = '\0';
	return (concat);
}
/**
 * main - check the code
 *
 * Return: Always 0.
 */
int main(void)
{
    char *s;

    s = str_concat("Best ", "School");
    if (s == NULL)
    {
        printf("failed\n");
        return (1);
    }
    printf("%s\n", s);
    free(s);
    return (0);
}
