#include <stdarg.h>
#include "variadic_functions.h"
/**
 * print_strings - prints a variable number of strings
 * @separator: string printed between each string, or NULL if no separator
 * @n: number of strings to print
 *
 * Description: this function prints each string argument. If a string is
 * NULL, it prints "(nil)" instead. The separator is not printed after
 * the last string.
 *
 * Return: void
 */
void print_strings(const char *separator, const unsigned int n, ...)
{
	va_list args;
	unsigned int i = 0;
	const char *s = separator;

	va_start(args, n);
	for (i = 0; i < n; i++)
	{
		s = va_arg(args, char *);
		if (s != NULL)
			printf("%s ", s);
		if (separator != NULL && i < n - 1)
			printf("%s", separator);
	}
	printf("\n");
}
