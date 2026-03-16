#include "main.h"
#include <stdio.h>
int found_prime_number(int n, int i)
{
	if (i * i > n)
		return (1);
	if (n % i == 0)
		return (0);
	return found_prime_number(n, ++i);
}

int is_prime_number(int n)
{
	if (n <= 1)
		return (0);
	return found_prime_number(n, 2);
}
