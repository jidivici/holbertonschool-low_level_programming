#include <stdlib.h>
#include <string.h>
#include <stdio.h>
#include "lists.h"
/**
 * sum_dlistint - Computes the sum of all elements in a doubly linked list
 * @head: pointer to the head of the list
 *
 * This function traverses the list and adds up the values stored
 * in each node.
 *
 * Return: the sum of all node values, or 0 if the list is empty
 */
int sum_dlistint(dlistint_t *head)
{
	dlistint_t *curr = head;
	int sum = 0;

	if (head == NULL)
		return (0);
	while (curr != NULL)
	{
		sum += curr->n;
		curr = curr->next;
	}
	return (sum);
}
