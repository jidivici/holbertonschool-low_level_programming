#include "main.h"
#include <stdio.h>
/**
 * switch_ope - executes operation based on user choice
 * @code: operation number selected by the user
 *
 * Return: 1 after executing operation
 */
int switch_ope(int code)
{
	switch (code)
	{
		case 1:
			addition();
			return (1);
		case 2:
			substract();
			return (1);
		case 3:
			multiplication();
			return (1);
		case 4:
			division();
			return (1);
	}
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
			if (switch_ope(code))
				print_menu();
		}
	}
	return (0);
}
