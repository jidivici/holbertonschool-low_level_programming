#include <stdlib.h>
#include <string.h>
#include <stdio.h>
#include "lists.h"
/**
 * add_dnodeint_end - Adds a new node at the end of a doubly linked list
 * @head: double pointer to the head of the list
 * @n: value to store in the new node
 *
 * This function creates a new node and appends it at the end
 * of the list. If the list is empty, the new node becomes the head.
 *
 * Return: pointer to the new node, or NULL if allocation fails
 */
dlistint_t *add_dnodeint_end(dlistint_t **head, const int n)
{
	dlistint_t *new_node;
	dlistint_t *curr;

	new_node = malloc(sizeof(*new_node));
	if (new_node == NULL)
		return (NULL);
	new_node->n = n;
	new_node->next = NULL;
	if (*head == NULL)
	{
		new_node->prev = NULL;
		*head = new_node;
		return (new_node);
	}
	curr = *head;
	while (curr->next != NULL)
		curr = curr->next;
	new_node->prev = curr;
	curr->next = new_node;
	return (new_node);
}
