Valgrind Analysis

This document analyzes Valgrind results for aliasing_example, 
heap_example, and crash_example.

	1.	aliasing_example

Observed result with gcc AddressSanitizer:
•	heap-use-after-free
•	READ of size 4
•	invalid address: 0xb87000920

Important values:
•	a = 0xb87000920
•	b = 0xb87000920 (alias)
•	allocated region: [0xb87000920, 0xb87000940)

Classification:
•	use-after-free (heap)

Explanation:
•	malloc allocates 20 bytes (5 ints)
•	a points to start of block
•	b = a → both point same memory
•	free(a) releases block
•	b still points same address (dangling)

Memory mistake:
•	reading b[2] → invalid read inside freed block
•	writing b[3] → invalid write after free

Precise description:
•	pointer still valid value but memory lifetime ended
•	AddressSanitizer shows region marked as “fd” (freed)

Extra notes from output:
•	“8 bytes inside of 20-byte region” confirms correct index calculation
•	crash happens exactly at aliasing_example.c:42

Conclusion:
•	this is not NULL pointer bug
•	this is use-after-free caused by aliasing

	2.	heap_example

Observed leaks result:
•	1 leak for 16 bytes
•	ROOT LEAK from person_new

Classification:
•	memory leak due to lost ownership

Explanation:
•	person_new allocates two blocks:
•   struct Person and name string
•	bob is fully freed (both allocations released)
•	alice is partially freed:
•	struct is freed
•	name is not freed

Memory mistake:
•	The pointer to alice->name is lost after freeing alice

Precise description:
•	Leak caused by freeing container structure without freeing owned heap field
•	This is a classic ownership violation


	3.	crash_example

Valgrind behavior:
•	Invalid write of size 4
•	Address 0x0 (NULL)

Classification:
•	NULL pointer dereference

Explanation:
•	n = 0
•	allocate_numbers returns NULL
•	nums receives NULL
•	nums[0] = 42 writes to address 0x0

Memory mistake:
•	Writing through a NULL pointer

Precise description:
•	This is not a heap mistake
•	It is an invalid memory access

AI ERROR AND CORRECTION

Incorrect AI statement:
“The crash is caused by malloc(0) returning NULL.”

Why it is incorrect:
•	malloc(0) is implementation-defined and may return a valid pointer
•	In this program malloc is not called because of the guard (n <= 0)

Correct explanation:
•	The crash is caused by dereferencing a NULL pointer
•	The bug is the absence of a NULL check before using nums

All issues demonstrate incorrect memory lifetime management:
•	accessing memory after free
•	losing references to allocated memory
•	using NULL pointers without validation