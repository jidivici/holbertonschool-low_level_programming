# Hash Tables - C

## Description
Implémentation d'une table de hachage en C (paires clé/valeur, accès rapide O(1)).

## Compilation
gcc -Wall -Werror -Wextra -pedantic *.c -o hash_tables

## Structures
typedef struct hash_node_s
{
	char *key;
	char *value;
	struct hash_node_s *next;
} hash_node_t;

typedef struct hash_table_s
{
	unsigned long int size;
	hash_node_t **array;
} hash_table_t;

## Fonctions
- hash_table_create : crée la table
- hash_djb2 : fonction de hash
- key_index : calcule l’index
- hash_table_set : ajoute / modifie
- hash_table_get : récupère une valeur
- hash_table_print : affiche la table
- hash_table_delete : libère la mémoire

## Collisions
Gestion par chaînage (liste liée).

## Bonnes pratiques
- vérifier malloc
- utiliser strdup
- free correctement
- strcmp pour comparer les clés

## Complexité
- accès / insertion : O(1)
- pire cas : O(n)
