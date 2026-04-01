# Doubly Linked Lists

## Description

This project implements and manipulates doubly linked lists in C.
A doubly linked list is a data structure where each node contains a value and two pointers: one to the next node and one to the previous node.

## Objectives

- Understand how doubly linked lists work
- Manage dynamic memory allocation and deallocation
- Handle pointers (`next` and `prev`) correctly
- Implement common list operations

## Data Structure

/**
* struct dlistint_s - doubly linked list
* @n: integer
* @prev: points to the previous node
* @next: points to the next node
*
* Description: doubly linked list node structure
*
*/
typedef struct dlistint_s
{
    int n;
    struct dlistint_s *prev;
    struct dlistint_s *next;
} dlistint_t;

Functions
•	print_dlistint : prints all elements of the list
•	dlistint_len : returns the number of elements
•	add_dnodeint : adds a node at the beginning
•	add_dnodeint_end : adds a node at the end
•	free_dlistint : frees the entire list
•	get_dnodeint_at_index : returns the node at a given index
•	sum_dlistint : returns the sum of all node values
•	insert_dnodeint_at_index : inserts a node at a specific index
•	delete_dnodeint_at_index : deletes a node at a specific index

COMPILATION : gcc -Wall -Werror -Wextra -pedantic -std=gnu89 -o output