#include "main.h"
#include <stdio.h>
/**
 * found_palindrome - recursively checks if a substring is a palindrome
 * @s: string to check
 * @start: starting index of the substring
 * @len: ending index of the substring
 *
 * Return: 1 if the substring is a palindrome, 0 otherwise
 *
 */
int found_palindrome(char *s, int start, int len)
{
	if (start >= len)
		return (1);
	if (s[start] != s[len])
		return (0);
	return (found_palindrome(s, start + 1, len - 1));
}
/**
 * is_palindrome - checks if a string is a palindrome
 * @s: string to check
 *
 * Return: 1 if s is a palindrome, 0 otherwise
 */
int is_palindrome(char *s)
{
	int len = _strlen(s);

	return (found_palindrome(s, 0, len - 1));
}
