#include <stdlib.h>
#include "main.h"
/**
* print_alphabet - writes alphabet S/output
 * @void
 *
 * Return: None
 */

void print_alphabet(void)
{
	char *alphabet = "abcdefghijklmnopqrstuvwxyz";

	while (*alphabet)
		_putchar(*alphabet++);
	_putchar('\n');
}
