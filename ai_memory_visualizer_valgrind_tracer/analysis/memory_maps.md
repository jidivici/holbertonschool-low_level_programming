Memory Maps Analysis

This document describes memory behavior for three programs: aliasing_example, heap_example, and stack_example.
The analysis is based on real outputs and corrected where needed.

STACK VS HEAP (baseline)

Stack:
•	Stores function frames (locals, parameters, return address)
•	Lifetime: from function entry to function return
•	Automatically freed
•	Grows toward lower addresses (observed in stack_example)

Heap:
•	Stores dynamically allocated memory (malloc)
•	Lifetime: from allocation to free
•	Must be managed manually
•	Multiple pointers can reference the same allocation (aliasing)

	1.	aliasing_example

Key steps:
1.	main allocates array with make_numbers
2.	a receives heap address
3.	b = a creates alias
4.	free(a) frees memory
5.	b is still pointing to same address (dangling)
6.	program reads and writes through b (invalid)

Observed output:
a=0xb87000920 b=0xb87000920 a[2]=22 b[2]=22
after free(a): b=0xb87000920 (dangling)
reading b[2]=1024
wrote b[3]=1234

Memory map:

Stack (main):
•	a -> 0xb87000920
•	b -> 0xb87000920 (alias of a)
•	n = 5

Heap before free:
•	block at 0xb87000920 contains 5 ints
•	values initialized: [0, 11, 22, 33, 44]

After free(a):
•	heap block is released
•	a and b still hold same address
•	both are dangling pointers

Important:
•	b[2] = 1024 is not original value (22)
•	memory has been reused or corrupted
•	writing b[3] is undefined behavior

Conclusion:
•	aliasing means multiple pointers share same memory
•	freeing once invalidates all aliases


	2.	heap_example

Key steps:
1.	person_new allocates struct Person
2.	allocates name string separately
3.	returns pointer to struct
4.	bob is fully freed
5.	alice is partially freed (name not freed)

Observed output:
alice=0xc96c24020 name=0xc97008000 age=30
bob=0xc96c24040 name=0xc97008010 age=41

Leak report:
•	16 bytes leaked from person_new
•	corresponds to alice->name

Memory map:

Stack (main):
•	alice -> 0xc96c24020
•	bob   -> 0xc96c24040

Heap:
•	alice struct at 0xc96c24020
•	alice->name at 0xc97008000
•	bob struct at 0xc96c24040
•	bob->name at 0xc97008010

Free operations:
•	free(bob->name)
•	free(bob)
•	free(alice) (but not alice->name)

Result:
•	alice->name still allocated
•	no pointer references it anymore
•	memory leak confirmed

Variable lifetimes:
•	struct Person lives until free
•	name string lives until explicitly freed


	3.	stack_example

Key steps:
1.	recursive calls create multiple stack frames
2.	each call has its own local variables
3.	addresses decrease with deeper recursion
4.	frames are destroyed in reverse order

Observed pattern:
•	depth 0: &local_int = 0x16d193078
•	depth 1: &local_int = 0x16d193038
•	depth 2: &local_int = 0x16d192ff8
•	depth 3: &local_int = 0x16d192fb8

Memory map:

Each frame contains:
•	local_int
•	local_buf
•	p_local (points to local_int)
•	marker

Example (depth 2):
•	local_int = 102
•	p_local = address of local_int
•	local_buf = separate stack array

Behavior:
•	each recursion allocates new frame
•	previous frames remain intact
•	on return, frames are removed

Conclusion:
•	stack variables are isolated per call
•	lifetime ends at function return


AI ERROR AND CORRECTION

Incorrect AI statement:
“After free(a), b becomes NULL automatically.”

Why it is wrong:
•	free does not modify other pointers
•	only deallocates the memory block
•	all existing pointers still store same address

Correct explanation:
•	a and b both still contain 0xb87000920
•	memory is freed, but pointers are unchanged
•	both become dangling pointers
•	accessing them is undefined behavior

	4.	crash_example

Key steps:
1.	main sets n = 0
2.	allocate_numbers(0) returns NULL (guard condition)
3.	nums receives NULL
4.	program writes nums[0] = 42
5.	NULL pointer dereference triggers = segmentation fault

Observed output:
crash_example: deterministic NULL dereference (segmentation fault)
requesting n=0
AddressSanitizer: SEGV on address 0x000000000000
The signal is caused by a WRITE memory access
Hint: address points to the zero page

Memory map:

Stack (main):
•	nums = NULL (0x0)
•	n = 0

Heap:
•	no allocation performed
•	malloc is never reached due to condition (n <= 0)

Critical instruction:
•	nums[0] = 42
•	attempts to write at address UNDEFINED

Explanation:
•	address nums is invalid
•	writing to it causes immediate crash

Important detail:
•	malloc((size_t)n * sizeof(int) + 1) is irrelevant here
•	function exits before allocation when n <= 0

Variable lifetime:
•	nums exists on stack for entire main execution
•	it never points to valid heap memory

CONCLUSION FOR crash_example
•	Always check returned pointer before use
•	Never dereference NULL
•	Guard conditions must be followed by safe usage
•	AddressSanitizer clearly shows invalid write at address 0x0


AI ERROR AND CORRECTION

Incorrect AI statement:
“malloc(0) always returns NULL, so crash comes from malloc.”

Why it is wrong:
•	malloc(0) may return NULL or a valid pointer
•	behavior is implementation-defined
•	in this program malloc is not even called

Correct explanation:
•	crash is caused by explicit dereference of NULL pointer
•	nums is NULL because of manual check (n <= 0)
•	the bug is not malloc, but missing NULL check before use
