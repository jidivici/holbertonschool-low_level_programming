#include <stdlib.h>
#include <string.h>
#include <stdio.h>
#include "hash_tables.h"

hash_node_t *create_node(const char *key, const char *value)
{
	hash_node_t *new_node;

	new_node = malloc(sizeof(hash_node_t));
	if (new_node == NULL)
		return (NULL);

	new_node->key = strdup(key);
	new_node->value = strdup(value);

	if (new_node->key == NULL || new_node->value == NULL)
	{
		free(new_node->key);
		free(new_node->value);
		free(new_node);
		return (NULL);
	}

	new_node->next = NULL;
	return (new_node);
}

int hash_table_set(hash_table_t *ht, const char *key, const char *value)
{
	unsigned long int h_index;
	hash_node_t *node;
	hash_node_t *curr;

	if (ht == NULL || key == NULL || *key == '\0' || value == NULL)
		return (0);

	h_index = key_index((unsigned const char *)key, ht->size);
	curr = ht->array[h_index];

	while (curr)
	{
		if (strcmp(curr->key, key) == 0)
		{
			free(curr->value);
			curr->value = strdup(value);
			return (1);
		}
		curr = curr->next;
	}

	node = create_node(key, value);
	if (node == NULL)
		return (0);

	node->next = ht->array[h_index];
	ht->array[h_index] = node;

	return (1);
}
