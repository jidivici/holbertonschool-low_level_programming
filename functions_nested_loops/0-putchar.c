#include <stdlib.h>
#include "main.h"
/**
* main - entry point
*
* Return: 0 (sucess)
*/
int main(void)
{
	char *centence = "_putchar\n";
	int i = 0;

	while (centence[i] != '\n')
		_putchar(centence[i++]);
	_putchar('\n');
	return (0);
}
