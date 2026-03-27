#include <stdlib.h>
#include <string.h>
#include <stdio.h>
#include "lists.h"
/**
 * free_list - Frees all nodes of a linked list
 * @head: pointer to the head of the list
 *
 * This function traverses the linked list and frees each node,
 * including the memory allocated for the stored string (if any).
 * After execution, all memory used by the list is released.
 */
void free_list(list_t *head)
{
	list_t *curr;

	while (head != NULL)
	{
		curr = head->next;
		free(head->str);
		free(head);
		head = curr;
	}
}
