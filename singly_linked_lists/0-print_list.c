#include <stdlib.h>
#include <string.h>
#include <stdio.h>
#include "lists.h"
/**
 * print_list - prints all elements of a list_t list
 * @h: pointer to head of list
 *
 * Return: number of nodes
 */
size_t print_list(const list_t *h)
{
	size_t count = 0;

	while (h)
	{
		if (h->str == NULL)
			printf("[%lu] (nil)\n", count);
		else
			printf("[%lu] %s\n", count,  h->str);
		h = h->next;
		count++;
	}
	return (count);
}
