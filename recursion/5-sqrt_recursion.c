#include "main.h"
#include <stdio.h>
/**
 * found_sqrt - helper function that searches for the square root of n
 * @n: number to compute the square root of
 * @i: current number being tested as a possible square root
 *
 * Return: the square root if found, or -1 if none exists
 */
int found_sqrt(int n, int i)
{
	if (i * i == n)
		return (i);
	if (i * i > n)
		return (-1);
	return (found_sqrt(n, i + 1));
}
/**
 * _sqrt_recursion - returns the natural square root of a number
 * @n: number to compute the square root of
 *
 * Return: natural square root of n, or -1 if n has no natural square root
 */
int _sqrt_recursion(int n)
{
	int i = 0;

	if (n == 0)
		return (0);
	return (found_sqrt(n, i));
}
