#include "main.h"
#include <stdio.h>
/**
 * found_prime_number - recursively checks if n is divisible by i
 * @n: number to test for primality
 * @i: current divisor being tested
 *
 * Return: 1 if n is prime, 0 if n is not prime
 */
int found_prime_number(int n, int i)
{
	if (i * i > n)
		return (1);
	if (n % i == 0)
		return (0);
	return (found_prime_number(n, ++i));
}
/**
 * is_prime_number - checks if a number is prime
 * @n: number to test for primality
 *
 * Return: 1 if n is prime, 0 if n is not prime
 */
int is_prime_number(int n)
{
	if (n <= 1)
		return (0);
	return (found_prime_number(n, 2));
}
