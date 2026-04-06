BINARY FILE OPERATIONS IN C

Description

This project implements basic file operations in C using system calls:
read, write, open, and close.

It includes functions to:
- read a text file
- create a file
- append text to a file
- copy content from one file to another

---

Compilation

gcc -Wall -Werror -Wextra -pedantic -std=gnu89 *.c -o cp

---

Files

main.h  
Contains all prototypes and required includes.

read_textfile.c  
ssize_t read_textfile(const char *filename, size_t letters);  
Reads a file and prints it to stdout.

create_file.c  
int create_file(const char *filename, char *text_content);  
Creates or truncates a file and writes content into it.

append_text_to_file.c  
int append_text_to_file(const char *filename, char *text_content);  
Appends text to the end of a file.

3-cp.c  
Copies content from one file to another.  
Usage: ./cp file_from file_to
- Exit 97: wrong arguments
- Exit 98: can't read file_from
- Exit 99: can't write to file_to
- Exit 100: can't close a file descriptor
