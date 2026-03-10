#include <stdio.h>
#include <stdlib.h>
#include <string.h>
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
#include "main.h"
#include <stdio.h>
#include <stdlib.h>

/**
 * main - check the code
 *
 * Return: Always 0.
 */
int main(void)
{
	char *concat;

	concat = string_nconcat("Best ", "School !!!", 6);
	printf("%s\n", concat);
	free(concat);
	return (0);
}
