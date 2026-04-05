#include <stdlib.h>
#include <string.h>
#include <stdio.h>
#include "hash_tables.h"
/**
 * hash_table_delete - free all node from hash table
 * @ht: hash table
 *
 * Return: nothing
 */
void hash_table_delete(const hash_table_t *ht)
{
	unsigned long int i;
	hash_node_t *curr;
	hash_node_t *tmp;

	if (!ht)
		return;
	for (i = 0; i < ht->size; i++)
	{
		curr = ht->array[i];
		tmp = ht->array[i];
		while (curr)
		{
			tmp = curr->next;
			free(curr->key);
			free(curr->value);
			free(curr);
			curr = tmp;
		}
	}
	free(ht->array);
}
