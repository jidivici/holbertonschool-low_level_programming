#include <stdio.h>
/**
* swap_int - swap value pointer a to pointer b
* @a: pointer int first switch
* @b: pointer int second switch
*
* Return: result of a * b
*/
void swap_int(int *a, int *b)
{
	int tmp = *a;
	*a = *b;
	*b = tmp;
}
