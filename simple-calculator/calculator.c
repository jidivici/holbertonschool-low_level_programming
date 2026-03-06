#include <stdio.h>
/**
 * ope - handle the operation choose
 * @code: operation number entered by the user
 *
 * Return: 1 if done
 */
int ope(int code)
{
	int a, b = 0;
	double sum = 0;

	printf("A: ");
	scanf("%d", &a);
	printf("B: ");
	scanf("%d", &b);
	if (code == 1)
		sum = (a + b);
	else if (code == 2)
		sum = (a - b);
	else if (code == 3)
		sum = (a * b);
	else if (code == 4)
		{
			if (b == 0)
			{
				printf("Error: division by zero\n");
				return (1);
			}
			else
			{
				sum = (double)a / b;
				printf("Result: %.1f\n", sum);
				return (1);
			}
		}
	printf("Result: %.0f\n", sum);
	return (1);
}
/**
 * print_menu - displays calculator menu
 *
 * Return: nothing
 */
void print_menu(void)
{
	printf("1) Add\n");
	printf("2) Subtract\n");
	printf("3) Multiply\n");
	printf("4) Divide\n");
	printf("0) Quit\n");
	printf("Choice: ");
}
/**
 * checker - validates user choice
 * @code: operation number entered by the user
 *
 * Return: 0 if user quits, 1 otherwise
 */
int checker(int code)
{
	if (code == 0)
	{
		printf("Bye!\n");
		return (0);
	}
	else if (code > 4 || code < 0)
		{
		printf("Invalid choice\n");
		printf("Choice: ");
		return (0);
		}
	return (1);
}
/**
 * main - program entry point
 *
 * Return: 0 when program exits
 */
int main(void)
{
	int code = 1;

	print_menu();
	while (code != 0)
	{
		scanf("%d", &code);
		if (checker(code))
		{
			if (ope(code))
				print_menu();
		}
	}
	return (0);
}
