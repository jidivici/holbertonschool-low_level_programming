#include <stdlib.h>
#include <string.h>
#include <stdio.h>
#include "lists.h"
/**
* add_node_end - Adds a new node at the end of a linked list
* @head: double pointer to the head of the list
* @str: string to duplicate and store in the new node
*
* This function creates a new node containing a copy of the given string,
* then appends it to the end of the list. If the list is empty,
* the new node becomes the first element.
*
* Return: pointer to the newly added node, or NULL on failure
*/
list_t *add_node_end(list_t **head, const char *str)
{
	list_t *new;
	list_t *last = *head;
	size_t len = 0;

	while (str[len])
		len++;
	new = malloc(sizeof(list_t));
	if (new == NULL)
		return (NULL);
	new->str = strdup(str);
	if (new->str == NULL)
	{
		free(new);
		return (NULL);
	}
	new->len = len;
	new->next = NULL;
	if (*head == NULL)
	{
		*head = new;
		return (new);
	}
	while (last->next != NULL)
		last = last->next;
	last->next = new;
	return (new);
}
