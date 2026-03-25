#ifndef MAIN_H
#define MAIN_H

#include <stddef.h>

int _putchar(char c);
int _strlen(char *str);
char *_strdup(char *str);
/**
 * struct list_s - singly linked list
 * @str: string stored in the node
 * @len: length of the string
 * @next: pointer to the next node
 */
typedef struct list_s
{
	char *str;
	size_t len;
	struct list_s *next;
} list_t;

size_t print_list(const list_t *h);
size_t list_len(const list_t *h);
list_t *add_node(list_t **head, const char *str);

#endif
