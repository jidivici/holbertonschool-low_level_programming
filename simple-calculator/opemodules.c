#include "main.h"
#include <stdio.h>
/**
 * division - performs integer division
 *
 * Return: nothing
 */
void division(void)
{
	int a, b, sum = 0;

	printf("A: ");
	scanf("%d", &a);
	printf("B: ");
	scanf("%d", &b);
	sum = (a / b);
	printf("Result: %d\n", sum);
}
/**
 * multiplication - multiplies two integers
 *
 * Return: nothing
 */
void multiplication(void)
{
	int a, b, sum = 0;

	printf("A: ");
	scanf("%d", &a);
	printf("B: ");
	scanf("%d", &b);
	sum = (a * b);
	printf("Result: %d\n", sum);
}
/**
 * substract - subtracts two integers
 *
 * Return: nothing
 */
void substract(void)
{
	int a, b, sum = 0;

	printf("A: ");
	scanf("%d", &a);
	printf("B: ");
	scanf("%d", &b);
	sum = (a - b);
	printf("Result: %d\n", sum);
}
/**
 * addition - adds two integers
 *
 * Return: nothing
 */
void addition(void)
{
	int a, b, sum = 0;

	printf("A: ");
	scanf("%d", &a);
	printf("B: ");
	scanf("%d", &b);
	sum = (a + b);
	printf("Result: %d\n", sum);
}
