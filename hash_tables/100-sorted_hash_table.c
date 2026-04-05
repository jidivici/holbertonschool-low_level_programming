#include <stdlib.h>
#include <string.h>
#include <stdio.h>
#include "hash_tables.h"
/**
 * shash_table_create - Crée une table de hachage
 * @size: Taille du tableau (nombre de buckets)
 *
 * Alloue une structure hash_table_t ainsi qu’un tableau de pointeurs
 * vers des listes chaînées initialisées à NULL.
 *
 * Return: Pointeur vers la table créée, ou NULL en cas d’échec
 */
shash_table_t *shash_table_create(unsigned long int size)
{
	shash_table_t *hash_table;
	unsigned int i = 0;

	if (size == 0)
		return (NULL);
	hash_table = malloc(sizeof(shash_table_t));
	if (hash_table == NULL)
		return (NULL);
	hash_table->size = size;
	hash_table->array = malloc(sizeof(shash_node_t *) * size);
	if (hash_table->array == NULL)
		return (NULL);
	for (i = 0; i < hash_table->size; i++)
		hash_table->array[i] = NULL;
	return (hash_table);
}
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
shash_node_t *create_node(const char *key, const char *value)
{
	shash_node_t *new_node;

	new_node = malloc(sizeof(shash_node_t));
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
 * update_value - updates the value of an existing key
 * @head: head of the linked list at a given index
 * @key: key to search
 * @value: new value to assign
 *
 * This function traverses the linked list to find a node with
 * the matching key.
 *
 * If found, it frees the old value and replaces it with the new one.
 *
 * Return: 1 if the key was found and updated, 0 otherwise
 */
int update_value(shash_node_t *head, const char *key, const char *value)
{
	shash_node_t *curr = head;

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
	return (0);
}
/**
* insert_sorted - inserts a node into the sorted linked list
* @ht: pointer to the sorted hash table
* @node: node to insert
*
* This function inserts the node into the sorted doubly linked list
* while maintaining alphabetical order based on the key.
*
* It updates:
* - sprev and snext pointers
* - head (shead) if necessary
* - tail (stail) if inserted at the end
*
* Return: void
*/
void insert_sorted(shash_table_t *ht, shash_node_t *node)
{
	shash_node_t *tmp;

	node->sprev = NULL;
	node->snext = NULL;

	if (!ht->shead)
	{
		ht->shead = node;
		ht->stail = node;
		return;
	}

	if (strcmp(node->key, ht->shead->key) < 0)
	{
		node->snext = ht->shead;
		ht->shead->sprev = node;
		ht->shead = node;
		return;
	}
	tmp = ht->shead;
	while (tmp->snext && strcmp(tmp->snext->key, node->key) < 0)
		tmp = tmp->snext;
	node->snext = tmp->snext;
	node->sprev = tmp;
	if (tmp->snext)
		tmp->snext->sprev = node;
	else
		ht->stail = node;
	tmp->snext = node;
}
/**
* shash_table_set - adds or updates an element in a hash table
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
int shash_table_set(shash_table_t *ht, const char *key, const char *value)
{
	unsigned long int index;
	shash_node_t *node;

	if (!ht || !key || *key == '\0' || !value)
		return (0);
	index = key_index((const unsigned char *)key, ht->size);
	if (update_value(ht->array[index], key, value))
		return (1);
	node = create_node(key, value);
	if (!node)
		return (0);
	node->next = ht->array[index];
	ht->array[index] = node;
	insert_sorted(ht, node);
	return (1);
}
/**
 * shash_table_print - prints the sorted hash table
 * @ht: pointer to the hash table
 *
 * This function prints all key/value pairs of the sorted hash table
 * in ascending order based on the keys.
 *
 * It traverses the sorted doubly linked list (shead → stail)
 * instead of the hash table array, ensuring ordered output.
 *
 * The output format is:
 * {'key1': 'value1', 'key2': 'value2', ...}
 *
 * Return: void
 */
void shash_table_print(const shash_table_t *ht)
{
	shash_node_t *curr;
	int first = 1;

	if (!ht)
		return;
	printf("{");
	curr = ht->shead;
	while (curr)
	{
		if (!first)
			printf(", ");
		printf("'%s': '%s'", curr->key, curr->value);
		first = 0;
		curr = curr->snext;
	}
	printf("}\n");
}
/**
 * shash_table_print_rev - prints the sorted hash table in reverse order
 * @ht: pointer to the hash table
 *
 * This function prints all key/value pairs of the sorted hash table
 * in reverse order, starting from the tail of the sorted linked list
 * (stail) and going backward using the sprev pointer.
 *
 * Return: void
 */
void shash_table_print_rev(const shash_table_t *ht)
{
	shash_node_t *curr;
	int first = 1;

	if (!ht)
		return;
	printf("{");
	curr = ht->stail;
	while (curr)
	{
		if (!first)
			printf(", ");
		printf("'%s': '%s'", curr->key, curr->value);
		first = 0;
		curr = curr->sprev;
	}
	printf("}\n");
}
/**
 * shash_table_delete - deletes a sorted hash table
 * @ht: pointer to the hash table
 *
 * This function frees all the memory allocated for the sorted
 * hash table.
 *
 * It performs the following steps:
 * - Traverses the sorted linked list (shead → snext)
 * - Frees each node:
 *      → key
 *      → value
 *      → node itself
 * - Frees the array of buckets
 * - Frees the hash table structure
 *
 * After this function is called, the hash table should no longer be used.
 *
 * Return: void
 */
void shash_table_delete(shash_table_t *ht)
{
	shash_node_t *curr, *tmp;

	if (!ht)
		return;
	curr = ht->shead;
	while (curr)
	{
		tmp = curr;
		curr = curr->snext;
		free(tmp->key);
		free(tmp->value);
		free(tmp);
	}
	free(ht->array);
	free(ht);
}
