#include <stdlib.h>
#include <string.h>
#include <stdio.h>
#include "lists.h"
/**
 * delete_dnodeint_at_index - Deletes a node at a given index
 * @head: double pointer to the head of the list
 * @index: index of the node to delete
 *
 * This function removes the node at the specified position
 * in the list and updates the surrounding pointers.
 *
 * Return: 1 if successful, -1 if it fails
 */
int delete_dnodeint_at_index(dlistint_t **head, unsigned int index)
{
	dlistint_t *curr = *head;
	unsigned int i = 0;

	if (!head || !*head)
		return (-1);
	while (curr && i < index)
	{
		curr = curr->next;
		i++;
	}
	if (!curr)
		return (-1);
	if (curr->prev == NULL)
		*head = curr->next;
	if (curr->prev)
		curr->prev->next = curr->next;
	if (curr->next)
		curr->next->prev = curr->prev;
	free(curr);
	return (1);
}
