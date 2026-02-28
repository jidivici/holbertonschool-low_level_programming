#include "main.h"
#include <stdio.h>
/**
* fizz_buzz - replace multiple of 3 and 5
*
* Return: void
*/
void fizz_buzz(void)
{
	int i = 0;

	for (; i < 100; i++)
		{
		if (i % 3 == 0 && i % 5 == 0)
			printf("FizzBuzz\n");
		else if (i % 3 == 0)
			printf("Fizz\n");
		else if (i % 5 == 0)
			printf("Buzz\n");
		else
			printf("%d\n", i);
		}
}