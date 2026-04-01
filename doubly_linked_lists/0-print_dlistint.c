#include <stdlib.h>
#include <string.h>
#include <stdio.h>
#include "lists.h"
/**
 * print_dlistint - Prints all elements of a doubly linked list
 * @h: pointer to the head of the list
 *
 * This function traverses the list from the head to the end
 * and prints the value of each node.
 *
 * Return: the number of nodes in the list
 */
size_t print_dlistint(const dlistint_t *h)
{
	size_t n = 0;
	const dlistint_t *curr = h;

	while (curr)
	{
		printf("%d\n", curr->n);
		curr = curr->next;
		n++;
	}
	return n;
}
