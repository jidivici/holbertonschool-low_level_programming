#include "main.h"
#include <stdio.h>
#include <stdlib.h>
/**
 * count_words - counts the number of words in a string
 * @s: string to analyze
 *
 * Return: number of words found in the string
 */
int count_words(char *s)
{
	int i = 0, words = 0;

	while (s[i])
	{
		if (s[i] != ' ' && (i == 0 || s[i - 1] == ' '))
			words++;
		i++;
	}
	return (words);
}
/**
 * word_len - calculates the length of a word in a string
 * @s: string containing the word
 * @start: index where the word starts
 *
 * Return: length of the word
 */
int word_len(char *s, int start)
{
	int len = 0;

	while (s[start + len] && s[start + len] != ' ')
		len++;
	return (len);
}
/**
 * strtow - splits a string into words
 * @str: string to split
 *
 * Return: pointer to an array of strings (words),
 * or NULL if the string is empty or memory allocation fails
 */
char **strtow(char *str)
{
	int word = 0;
	int i = 0, len = 0, j = 0, k = 0;
	char **ptr = NULL;

	if (str == NULL || *str == '\0')
		return (NULL);
	word = count_words(str);
	ptr = malloc((word + 1) * sizeof(char *));
	if (ptr == NULL)
		return (NULL);
	for (i = 0; i < word; i++)
	{
		while (str[j] == ' ')
			j++;
		len = word_len(str, j);

		ptr[i] = malloc(len + 1);
		if (!ptr[i])
		{
			for (k = 0; k < i; k++)
				free(ptr[k]);
			free(ptr);
			return (NULL);
		}
		for (k = 0; k < len; k++)
			ptr[i][k] = str[j + k];
		ptr[i][len] = '\0';
		j += len;
	}
	ptr[i] = NULL;
	return (ptr);
}
