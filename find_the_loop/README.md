# Find Loop in Linked List

![C Programming](https://img.shields.io/badge/C-Programming-red.svg)


This repository contains the implementation of a function to detect a loop within a singly linked list.

## Project Overview

The purpose of this project is to implement a function that can identify a loop in a linked list where the last node points back to any of the previous nodes instead of pointing to `NULL`. The function is defined as follows:

- **Prototype**: `listint_t *find_listint_loop(listint_t *head);`
- **Returns**: The address of the node where the loop starts, or `NULL` if there is no loop.

The function is constrained by not allowing the use of `malloc`, `free`, or arrays and can only declare a maximum of two variables.

## Usage

This section provides instructions on how to compile and run the program, along with an example.

### Compilation

The program must be compiled this way:

```bash
gcc -Wall -pedantic -Werror -Wextra 0-main.c 0-find_loop.c -L. -lloop -o main
```

### Execution

To run the program:

```bash
./main
```

### Example

Here is an example of the output you might see if there is a loop in the linked list:

```
[0x13700f0] 1024
[0x13700d0] 402
[0x13700b0] 98
[0x1370090] 4
[0x1370070] 3
[0x1370050] 2
[0x1370030] 1
[0x1370010] 0
[0x1370560] 1024
[0x1370540] 402
[0x1370010] 98
[0x1370030] 7
[0x1370050] 6
[0x1370070] 5
[0x1370090] 4
[0x13700b0] 3
[0x13700d0] 2
[0x13700f0] 1
[0x1370110] 0
-> [0x1370030] 7
Loop starts at [0x1370030] 7
```

## Acknowledgments

- Floyd's cycle-finding algorithm for inspiration.
- Holberton School for providing the learning platform.
