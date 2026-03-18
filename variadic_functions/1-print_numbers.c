#include "variadic_functions.h"
#include <stdarg.h>
#include <stdio.h>

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
/**
 * main - check the code
 *
 * Return: Always 0.
 */
int main(void)
{
	print_numbers(", ", 4, 0, 98, -1024, 402);
	return (0);
}
