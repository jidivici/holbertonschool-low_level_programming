#include <stdlib.h>
#include <string.h>
#include <stdio.h>
#include "lists.h"
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
