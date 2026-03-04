#include <stdio.h>
#include "main.h"
/**
* _strcat - concatenates src to dest
* @dest: destination string (must have enough space)
* @src: source string to append
*
* Return: pointer to dest
*/
char *_strcat(char *dest, char *src)
{
	int	i = 0, j = 0;
	char *beg_point = dest;

	while (dest[i] != '\0')
		i++;
	while (src[j] != '\0')
	{
		dest[i] = src[j];
		i++;
		j++;
	}
	dest[i] = '\0';
	return (beg_point);
}

int main(void)
{
	char s1[98] = "Hello ";
	char s2[] = "World!\n";
	char *ptr;

	printf("%s\n", s1);
	printf("%s", s2);
	ptr = _strcat(s1, s2);
	printf("%s", s1);
	printf("%s", s2);
	printf("%s", ptr);
	return (0);
}
