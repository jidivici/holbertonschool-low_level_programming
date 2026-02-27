#include <stdlib.h>
#include "main.h"
/**
* _isupper - check caracter if upper
* @c: the caracter tested
*
* Return: 0(sucess) or 1 (fail)
*/
int _isupper(int c)
{
	if ((c >= 'A' && c <= 'Z'))
		return (1);
	else
		return (0);
}
