#include <stdlib.h>
#include <string.h>
#include <stdio.h>
#include "lists.h"
/**
 * get_dnodeint_at_index - Returns the node at a given index
 * @head: pointer to the head of the list
 * @index: index of the node to retrieve
 *
 * This function traverses the doubly linked list from the head
 * until it reaches the specified index and returns the corresponding node.
 * If the index is out of range, the function returns NULL.
 *
 * Return: pointer to the node at the given index, or NULL if it fails
 */
dlistint_t *get_dnodeint_at_index(dlistint_t *head, unsigned int index)
{
	dlistint_t *curr = head;
	unsigned int i = 0;

	if (curr == NULL)
		return (NULL);
	while (curr->next != NULL)
	{
		if (i == index)
			return (curr);
		i++;
		curr = curr->next;
	}
	return (NULL);
}
