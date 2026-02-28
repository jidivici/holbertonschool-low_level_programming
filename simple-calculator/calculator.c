#include "main.h"
#include <stdio.h>
/**
* total_sum - sum * row
* @rows: ligne
* @cols: colonne
*
* Return: total
*/
int operation(int code)
{
	printf("1) Add\n");
	printf("2) Subtract\n");
	printf("3) Multiply\n");
	printf("4) Divide\n");
	printf("0) Quit\n");
	scanf("%d", &code);
	printf("%d\n", code);
	return code;
}

int main(void)
{
	int code = 0;

	while (1)
	{
		operation(code);
		return (0);
	}
}