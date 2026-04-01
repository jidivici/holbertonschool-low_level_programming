#include <stdlib.h>
#include <string.h>
#include <stdio.h>
#include "lists.h"
/**
 * free_dlistint - Frees all nodes of a doubly linked list
 * @head: pointer to the head of the list
 *
 * This function traverses the list and frees each node,
 * releasing all allocated memory.
 */
void free_dlistint(dlistint_t *head)
{
	dlistint_t *curr;
	dlistint_t *next;

	if (head == NULL)
		return;
	curr = head;
	while (curr)
	{
		next = curr->next;
		free(curr);
		curr = next;
	}
}
