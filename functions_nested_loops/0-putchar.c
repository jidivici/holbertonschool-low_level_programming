#include <stdlib.h>
#include <unistd.h>
/**
 * _putchar - writes the character c to stdout
 * @c: The character to print
 *
 * Return: On success 1.
 * On error, -1 is returned, and errno is set appropriately.
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
