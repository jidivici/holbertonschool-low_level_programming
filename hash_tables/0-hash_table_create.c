#include <stdlib.h>
#include <string.h>
#include <stdio.h>
#include "hash_tables.h"
/**
 * hash_table_create - Crée une table de hachage
 * @size: Taille du tableau (nombre de buckets)
 *
 * Alloue une structure hash_table_t ainsi qu’un tableau de pointeurs
 * vers des listes chaînées initialisées à NULL.
 *
 * Return: Pointeur vers la table créée, ou NULL en cas d’échec
 */
hash_table_t *hash_table_create(unsigned long int size)
{
	hash_table_t *hash_table;
	unsigned int i = 0;

	if (size == 0)
		return (NULL);
	hash_table = (hash_table_t *)malloc(sizeof(hash_table_t));
	if (hash_table == NULL)
		return (NULL);
	hash_table->size = size;
	hash_table->array = malloc(hash_table->size * sizeof(char *));
	if (hash_table->array == NULL)
		return (NULL);
	for (i = 0; i < hash_table->size; i++)
		hash_table->array[i] = NULL;
	return (hash_table);
}
