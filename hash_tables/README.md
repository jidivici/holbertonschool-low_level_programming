# Hash Tables in C

## Description

This project implements both standard and sorted hash tables in C.

A hash table is a data structure that maps keys to values using a hash function.
Collisions are handled using chaining (linked lists).

The sorted hash table extends this structure by maintaining elements in a
sorted doubly linked list.

---

## Data Structures

### `struct hash_node_s`

```c
/**
 * struct hash_node_s - Node of a hash table
 *
 * @key: The key (string), unique in the hash table
 * @value: The value associated with the key
 * @next: Pointer to the next node in case of collision
 *
 * Description:
 * This structure represents a node stored in a hash table bucket.
 * It is used in collision handling with linked lists.
 */
typedef struct hash_node_s
{
	char *key;
	char *value;
	struct hash_node_s *next;
} hash_node_t;

/**
 * struct hash_table_s - Hash table data structure
 *
 * @size: Size of the array
 * @array: Array of pointers to linked lists (buckets)
 *
 * Description:
 * This structure represents a standard hash table using
 * chaining for collision resolution.
 */
typedef struct hash_table_s
{
	unsigned long int size;
	hash_node_t **array;
} hash_table_t;

/**
 * struct shash_node_s - Node of a sorted hash table
 *
 * @key: The key (string), unique in the hash table
 * @value: The value associated with the key
 * @next: Pointer to the next node in the bucket (collision list)
 * @sprev: Pointer to the previous node in sorted order
 * @snext: Pointer to the next node in sorted order
 *
 * Description:
 * This structure extends hash_node_s by adding a doubly linked list
 * to maintain elements sorted by key.
 */
typedef struct shash_node_s
{
	char *key;
	char *value;
	struct shash_node_s *next;
	struct shash_node_s *sprev;
	struct shash_node_s *snext;
} shash_node_t;

/**
 * struct shash_table_s - Sorted hash table data structure
 *
 * @size: Size of the array
 * @array: Array of pointers to linked lists (buckets)
 * @shead: Pointer to the head of the sorted linked list
 * @stail: Pointer to the tail of the sorted linked list
 *
 * Description:
 * This structure represents a hash table with an additional
 * sorted doubly linked list to allow ordered traversal.
 */
typedef struct shash_table_s
{
	unsigned long int size;
	shash_node_t **array;
	shash_node_t *shead;
	shash_node_t *stail;
} shash_table_t;
