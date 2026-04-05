#include <stdlib.h>
#include <string.h>
#include <stdio.h>
#include "hash_tables.h"

/**
 * hash_table_get - Retrieves a value associated with a key in a hash table
 * @ht: The hash table to search in
 * @key: The key to look for
 *
 * Description: This function uses the key to compute the index using
 * the hash function, then traverses the linked list at that index
 * to find the matching key. If found, it returns the corresponding value.
 *
 * Return: The value associated with the key, or NULL if the key is not found
 * or if ht or key is NULL
 */
char *hash_table_get(const hash_table_t *ht, const char *key)
{
	unsigned long int index;
	hash_node_t *curr;

	if (ht == NULL || key == NULL)
		return (NULL);
	index = key_index((const unsigned char *)key, ht->size);
	curr = ht->array[index];
	while (curr)
	{
		if (strcmp(curr->key, key) == 0)
			return (curr->value);
		curr = curr->next;
	}
	return (NULL);
}
