#include <stdarg.h>
#include "variadic_functions.h"
/**
 * sum_them_all - sums all the integers passed as arguments
 * @n: number of arguments
 *
 * Return: sum of all arguments, or 0 if n is 0
 */
int sum_them_all(const unsigned int n, ...)
{
	va_list args;
	unsigned int i;
	int x = 0;

	if (n == 0)
		return (0);
	va_start(args, n);
	for (i = 0; i < n; i++)
	{
		x = x + va_arg(args, int);
	}
	va_end(args);
	return (x);
}
