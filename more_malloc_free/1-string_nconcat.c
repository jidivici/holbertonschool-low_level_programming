#include <stdlib.h>
#include "main.h"
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
 * string_nconcat - concatenates n bytes of s2 to s1
 * @s1: first string (can be NULL)
 * @s2: second string (can be NULL)
 * @n: maximum number of bytes from s2 to concatenate
 *
 * Return: pointer to newly allocated string, or NULL if malloc fails
 */
char *string_nconcat(char *s1, char *s2, unsigned int n)
{
	unsigned int len1 = 0, len2 = 0;
	unsigned int i, j;
	char *concat;

	if (s1 != NULL)
		len1 = _strlen(s1);
	if (s2 != NULL)
		len2 = _strlen(s2);
	if (n > len2)
		n = len2;
	concat = malloc(len1 + n + 1);
	if (concat == NULL)
		return (NULL);
	for (i = 0; i < len1; i++)
		concat[i] = s1[i];
	for (j = 0; j < n; j++)
		concat[i + j] = s2[j];
	concat[i + j] = '\0';
	return concat;
}
