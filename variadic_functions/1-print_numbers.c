#include "variadic_functions.h"
#include <stdarg.h>
#include <stdio.h>
/**
 * print_numbers - prints a variable number of integers
 * @separator: string printed between numbers, or NULL for no separator
 * @i: total number of integers to print
 *
 * Description: this function prints each integer followed by the separator
 * except after the last number
 *
 * Return: void
 */
void print_numbers(const char *separator, const unsigned int i, ...)
{
	va_list args;
	unsigned int j = 0, num = 0;

	if (separator == NULL || i == 0)
		return;
	va_start(args, i);
	for (j = 0; j < i; j++)
	{
		num = va_arg(args, unsigned int);
		printf("%d", num);
		if (j < i - 1)
			printf("%s", separator);
	}
	printf("\n");
	va_end(args);
}
