#include <stdlib.h>
#include <string.h>
#include <stdio.h>
#include "lists.h"
/**
 * dlistint_len - Counts the number of elements in a doubly linked list
 * @h: pointer to the head of the list
 *
 * This function traverses the list and counts each node.
 *
 * Return: the number of elements in the list
 */
size_t dlistint_len(const dlistint_t *h)
{
	size_t n = 0;
	const dlistint_t *curr = h;

	while (curr)
	{
		n++;
		curr = curr->next;
	}
	return (n);
}
