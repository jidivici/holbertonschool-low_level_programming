#ifndef POINTER_H
#define POINTER_H

#include <stdio.h>

int _putchar(char c);
int _strlen(char *str);
void print_name(char *name, void (*f)(char *));
void array_iterator(int *array, size_t size, void (*action)(int));

#endif
