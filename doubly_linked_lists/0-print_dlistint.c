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

}
/**
 * main - check the code
 *
 * Return: Always EXIT_SUCCESS.
 */
int main(void)
{
	dlistint_t *head;
	dlistint_t *new;
	dlistint_t hello = {8, NULL, NULL};
	size_t n;

	head = &hello;
	new = malloc(sizeof(dlistint_t));
	if (new == NULL)
	{
		dprintf(2, "Error: Can't malloc\n");
		return (EXIT_FAILURE);
	}
	new->n = 9;
	head->prev = new;
	new->next = head;
	new->prev = NULL;
	head = new;
	n = dlistint_len(head);
	printf("-> %lu elements\n", n);
	free(new);
	return (EXIT_SUCCESS);
}