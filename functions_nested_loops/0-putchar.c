#include <stdlib.h>
#include <unistd.h>
/**
* putchar - setting char
*
* Return: char in standar output
*/
int _putchar(char c)
{
	return (write(1, &c, 1));
}

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
