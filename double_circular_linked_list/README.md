# Double Circular Linked List

![C](https://img.shields.io/badge/C-00599C?style=for-the-badge&logo=c&logoColor=white)

## Project Description

This project involves implementing a double circular linked list in C. A double circular linked list is a linked list where each node points to both its previous and next node, and the list forms a circular structure, meaning the last node points back to the first node and vice versa. This project specifically includes functions to add nodes either at the beginning or at the end of the list.

## Features

- Add a new node to the end of a double circular linked list.
- Add a new node to the beginning of a double circular linked list.
- Print the contents of the list to verify the additions.

## Project Structure

- `0-add_node.c`: Contains the implementation of the functions to add nodes to the list.
- `0-main.c`: Contains the main function to test the functionalities of adding nodes to the list.
- `list.h`: Header file containing the definition of the list structure and the function prototypes.

## Function Prototypes

### `List *add_node_end(List **list, char *str)`

Adds a new node to the end of a double circular linked list.

- **Parameters:**
  - `list`: A pointer to the list to be modified.
  - `str`: The string to copy into the new node.
- **Returns:** The address of the new node, or `NULL` on failure.

### `List *add_node_begin(List **list, char *str)`

Adds a new node to the beginning of a double circular linked list.

- **Parameters:**
  - `list`: A pointer to the list to be modified.
  - `str`: The string to copy into the new node.
- **Returns:** The address of the new node, or `NULL` on failure.

## Example Output

```plaintext
Added to the end:
Holberton
        ->prev: Engineer
        ->next: School
School
        ->prev: Holberton
        ->next: Full
Full
        ->prev: School
        ->next: Stack
Stack
        ->prev: Full
        ->next: Engineer
Engineer
        ->prev: Stack
        ->next: Holberton
Added to the beginning:
Engineer
        ->prev: Holberton
        ->next: Stack
Stack
        ->prev: Engineer
        ->next: Full
Full
        ->prev: Stack
        ->next: School
School
        ->prev: Full
        ->next: Holberton
Holberton
        ->prev: School
        ->next: Engineer
```

## Author

- Vladimir Davidov
