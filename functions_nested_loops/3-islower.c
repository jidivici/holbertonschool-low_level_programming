#include <stdlib.h>
#include "main.h"
/**
* _islower -  S/output
* @c: int use ascii table
*
* Return: None
*/
int _islower(int c)
{
	if (c >= 'a' && c <= 'z')
		return (1);
	else
		return (0);
}
