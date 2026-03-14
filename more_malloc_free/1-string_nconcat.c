#include <stdlib.h>
#include "main.h"
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
	unsigned int i = 0, j = 0;
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
		concat[i + j] = s2 ? s2[j] : 0;
	if (s2 == NULL)
		concat[i + len1] = '\0';
	concat[i + j] = '\0';
	return concat;
}

int main(void)
{
	char *concat;

	concat = string_nconcat("best", NULL, 0);
	printf("%s\n", concat);
	free(concat);
	return (0);
}
