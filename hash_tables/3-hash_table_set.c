#include <stdlib.h>
#include <string.h>
#include <stdio.h>
#include "hash_tables.h"
/**
 * create_node - creates a new hash node
 * @key: key to store in the node
 * @value: value associated with the key
 *
 * Description:
 * This function allocates memory for a new hash node and duplicates
 * the key and value using strdup. It initializes the next pointer to NULL.
 * If memory allocation fails, the function frees any allocated memory
 * and returns NULL.
 *
 * Return: pointer to the newly created node, or NULL on failure
 */
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
/**
 * hash_table_set - adds or updates an element in a hash table
 * @ht: pointer to the hash table
 * @key: key associated with the value
 * @value: value to store
 *
 * Description:
 * This function inserts a new key/value pair into the hash table.
 * If the key already exists, the value is updated by replacing the old one.
 * If the key does not exist, a new node is created and added at the
 * beginning of the linked list at the corresponding index.
 *
 * Return: 1 on success, 0 on failure
 */
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
