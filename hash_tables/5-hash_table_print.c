#include <stdlib.h>
#include <string.h>
#include <stdio.h>
#include "hash_tables.h"
/**
 * hash_table_print - prints a hash table
 * @ht: hash table
 *
 * Return: nothing
 */
void hash_table_print(const hash_table_t *ht)
{
	unsigned long int i, cot = 1;
	hash_node_t *curr;

	if (!ht)
		return;
	printf("{");
	for (i = 0; i < ht->size; i++)
	{
		curr = ht->array[i];
		while (curr)
		{
			if (!cot)
				printf(", ");
			printf("'%s': '%s'", curr->key, curr->value);
			cot = !cot;
			curr = curr->next;
		}
	}
	printf("}\n");
}
