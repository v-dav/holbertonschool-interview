# Linked List Palindrome

![C](https://img.shields.io/badge/C-00599C?style=for-the-badge&logo=c&logoColor=white)

![Skärmavbild 2024-02-08 kl  12 48 35](https://github.com/v-dav/holbertonschool-interview/assets/115344057/4f099ae1-3a1c-447e-97af-0cb1e5f0a15f)


## 🧐 Project Overview

Welcome to the "Linked List is a Palindrome" algorithm project! In this project, we explore an algorithmic problem related to linked lists. The goal is to determine whether a given linked list is a palindrome or not. This involves checking if the sequence of elements in the linked list reads the same backward as forward.

## 🧐 Problem description
Given a linked list, implement a function is_palindrome that returns True if the linked list is a palindrome, and False otherwise. An empty list is considered a palindrome.

## 🎓 Prototype and example

```c
int is_palindrome(listint_t **head);
```


## 👨🏼‍🏫 Whiteboard

![Untitled-2024-02-01-1118](https://github.com/v-dav/holbertonschool-interview/assets/115344057/a69b363d-907b-4e76-a616-c8d400408891)


## 🧑🏼‍💻 Usage

You can use the function in your C program as follows:

```
carrie@ubuntu:0x03$ cat lists.h 
#ifndef LISTS_H
#define LISTS_H

/**
 * struct listint_s - singly linked list
 * @n: integer
 * @next: points to the next node
 *
 * Description: singly linked list node structure
 * for Holberton project
 */
typedef struct listint_s
{
    int n;
    struct listint_s *next;
} listint_t;

size_t print_listint(const listint_t *h);
listint_t *add_nodeint_end(listint_t **head, const int n);
void free_listint(listint_t *head);

int is_palindrome(listint_t **head);

#endif /* LISTS_H */
carrie@ubuntu:0x03$
```

```
carrie@ubuntu:0x03$ cat linked_lists.c 
#include <stdio.h>
#include <stdlib.h>
#include "lists.h"

/**
 * print_listint - prints all elements of a listint_t list
 * @h: pointer to head of list
 * Return: number of nodes
 */
size_t print_listint(const listint_t *h)
{
    const listint_t *current;
    unsigned int n; /* number of nodes */

    current = h;
    n = 0;
    while (current != NULL)
    {
        printf("%i\n", current->n);
        current = current->next;
        n++;
    }

    return (n);
}

/**
 * add_nodeint_end - adds a new node at the end of a listint_t list
 * @head: pointer to pointer of first node of listint_t list
 * @n: integer to be included in new node
 * Return: address of the new element or NULL if it fails
 */
listint_t *add_nodeint_end(listint_t **head, const int n)
{
    listint_t *new;
    listint_t *current;

    current = *head;

    new = malloc(sizeof(listint_t));
    if (new == NULL)
        return (NULL);

    new->n = n;
    new->next = NULL;

    if (*head == NULL)
        *head = new;
    else
    {
        while (current->next != NULL)
            current = current->next;
        current->next = new;
    }

    return (new);
}

/**
 * free_listint - frees a listint_t list
 * @head: pointer to list to be freed
 * Return: void
 */
void free_listint(listint_t *head)
{
    listint_t *current;

    while (head != NULL)
    {
        current = head;
        head = head->next;
        free(current);
    }
}
carrie@ubuntu:0x03$
```
```
carrie@ubuntu:0x03$ cat 0-main.c
#include <stdio.h>
#include <stdlib.h>
#include "lists.h"

/**
 * main - check the code for Holberton School students.
 *
 * Return: Always 0.
 */
int main(void)
{
    listint_t *head;

    head = NULL;
    add_nodeint_end(&head, 1);
    add_nodeint_end(&head, 17);
    add_nodeint_end(&head, 972);
    add_nodeint_end(&head, 50);
    add_nodeint_end(&head, 98);
    add_nodeint_end(&head, 98);
    add_nodeint_end(&head, 50);
    add_nodeint_end(&head, 972);
    add_nodeint_end(&head, 17);
    add_nodeint_end(&head, 1);
    print_listint(head);

    if (is_palindrome(&head) == 1)
        printf("Linked list is a palindrome\n");
    else
        printf("Linked list is not a palindrome\n");

    free_listint(head);

    return (0);
}
carrie@ubuntu:0x03$
carrie@ubuntu:0x03$ gcc -Wall -Werror -Wextra -pedantic 0-main.c linked_lists.c 0-is_palindrome.c -o palindrome
carrie@ubuntu:0x03$ ./palindrome
1
17
972
50
98
98
50
972
17
1
Linked list is a palindrome
carrie@ubuntu:0x03$
```

## 🧑🏼‍💻 Leetcode

![Skärmavbild 2024-02-08 kl  16 03 59](https://github.com/v-dav/holbertonschool-interview/assets/115344057/6ed30d2d-5692-4c17-866d-d7f54426c535)


##  🙇 Author

[Vladimir Davidov](https://github.com/v-dav) - Holberton School
