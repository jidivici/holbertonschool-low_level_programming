#include <stdlib.h>
#include <string.h>
#include <stdio.h>
#include "lists.h"
/**
 * insert_dnodeint_at_index - Inserts a new node at a given index
 * @h: double pointer to the head of the list
 * @idx: index where the new node should be added
 * @n: value to store in the new node
 *
 * This function inserts a new node at the specified position
 * in the list. If idx is 0, the node is added at the beginning.
 * If idx is equal to the length of the list, the node is added
 * at the end.
 *
 * Return: pointer to the new node, or NULL if it fails
 */
dlistint_t *insert_dnodeint_at_index(dlistint_t **h, unsigned int idx, int n)
{
	dlistint_t *curr = *h;
	unsigned int i = 0;
	dlistint_t *new_node;

	if (idx == 0)
		return (add_dnodeint(h, n));
	while (curr)
	{
		if (i == idx)
			break;
		curr = curr->next;
		i++;
	}
	if (i == idx && curr == NULL)
		return (add_dnodeint_end(h, n));
	if (curr == NULL)
		return (NULL);
	new_node = malloc(sizeof(*new_node));
	if (new_node == NULL)
		return (NULL);
	new_node->n = n;
	new_node->prev = curr->prev;
	new_node->next = curr;

	curr->prev->next = new_node;
	curr->prev = new_node;
	return (new_node);
}
