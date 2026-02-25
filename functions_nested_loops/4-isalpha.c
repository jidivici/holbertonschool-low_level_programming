#include <stdlib.h>
#include "main.h"
/**
* _isalpha -  S/output
* @c: int use ascii table
*
* Return: None
*/
int _isalpha(int c)
{
	if ((c >= 'a' && c <= 'z') || (c >= 'A' && c <= 'Z'))
		return (1);
	else
		return (0);
}