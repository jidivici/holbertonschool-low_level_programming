#include "main.h"
#include <stdio.h>
/**
 * wildcmp - compares two strings and returns 1 if they can be considered
 *           identical, allowing for the wildcard character '*' in s2
 * @s1: first string to compare
 * @s2: second string to compare, may contain '*' as a wildcard
 *
 * Return: 1 if the strings match, 0 otherwise
 *
 * Description: The wildcard '*' in s2 can match zero or more characters
 *              in s1. The function uses recursion to check all possibilities.
 */
int wildcmp(char *s1, char *s2)
{
	if (*s1 == '\0' && *s2 == '\0')
		return (1);
	if (*s2 == '*')
		return (wildcmp(s1, s2 + 1) || (*s1 && wildcmp(s1 + 1, s2)));
	if (*s1 == *s2)
		return (wildcmp(s1 + 1, s2 + 1));
	return (0);
}
