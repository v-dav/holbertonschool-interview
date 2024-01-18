# Heap Insertion Algorithm

![C](https://img.shields.io/badge/C-00599C?style=for-the-badge&logo=c&logoColor=white)

![MaxHeap](https://github.com/v-dav/holbertonschool-interview/assets/115344057/25473b77-c8c9-4dd3-8932-998722b8e910)


This project focuses on implementing the Heap Insertion Algorithm for a Max Binary Heap in the C programming language.

## Project Overview

In computer science, a Max Binary Heap is a specialized tree-based data structure that satisfies the heap property. The heap insertion algorithm ensures that the heap remains a complete binary tree with the Max Heap property intact even after the insertion of a new element. This project delves into the intricacies of implementing this algorithm within the context of a Max Binary Heap.

## Learning Objectives

Through this project, you'll gain a deeper understanding of:

- **Max Binary Heap**: Learn the fundamentals of a binary tree structure known as a Max Binary Heap.
- **Heap Insertion Algorithm**: Implement the algorithm responsible for inserting elements into a Max Binary Heap while maintaining its properties.
- **C Programming**: Develop and refine your C programming skills by working on a real-world algorithmic problem.

## Functionality

The primary goal of this project is to write a function that inserts a value into a Max Binary Heap:

```c
heap_t *heap_insert(heap_t **root, int value);
```

- `root`: A double pointer to the root node of the Max Binary Heap.
- `value`: The value to store in the node to be inserted.

The function returns a pointer to the inserted node or `NULL` on failure. If the address stored in `root` is `NULL`, the created node becomes the root node. The Max Heap ordering is maintained throughout the insertion process.


##  🙇 Author

[Vladimir Davidov](https://github.com/v-dav) - Holberton School
