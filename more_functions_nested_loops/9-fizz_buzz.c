#include "main.h"
#include <stdio.h>
/**
* main - replace multiple of 3 and 5
*
* Return: void
*/
int main(void)
{
	int i = 0;

	for (; i < 100; i++)
		{
		if (i % 3 == 0 && i % 5 == 0)
			printf("FizzBuzz ");
		else if (i % 3 == 0)
			printf("Fizz ");
		else if (i % 5 == 0)
			printf("Buzz ");
		else
			printf("%d ", i);
		}
	return (0);
}