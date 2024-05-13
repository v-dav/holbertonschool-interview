# Advanced Binary Search Algorithm

![C](https://img.shields.io/badge/C-00599C?style=for-the-badge&logo=c&logoColor=white)

This project contains an implementation of an advanced binary search algorithm that returns the index of the first occurrence of a value in a sorted array of integers.

## 🧐 Project Description

The advanced_binary function searches for a given value in a sorted array of integers using recursion. It returns the index of the first occurrence of the value, or -1 if the value is not present in the array.

## 🎓 Constraints

- The input array must be sorted in ascending order.
- The function uses recursion to perform the binary search.
- It prints the array (or subarray) being searched every time it splits the array.


## 🧑🏼‍💻 Usage Example

```
wilfried@0x1D-search_algorithms$ cat 0-main.c 
#include <stdio.h>
#include <stdlib.h>
#include "search_algos.h"

/**
 * main - Entry point
 *
 * Return: Always EXIT_SUCCESS
 */
int main(void)
{
    int array[] = {
        0, 1, 2, 5, 5, 6, 6, 7, 8, 9
    };
    size_t size = sizeof(array) / sizeof(array[0]);

    printf("Found %d at index: %d\n\n", 8, advanced_binary(array, size, 8));
    printf("Found %d at index: %d\n\n", 5, advanced_binary(array, size, 5));
    printf("Found %d at index: %d\n", 999, advanced_binary(array, size, 999));
    return (EXIT_SUCCESS);
}
wilfried@0x1D-search_algorithms$ gcc -Wall -Wextra -Werror -pedantic 0-main.c 0-advanced_binary.c -o 0-advanced_binary
wilfried@0x1D-search_algorithms$ ./0-advanced_binary
Searching in array: 0, 1, 2, 5, 5, 6, 6, 7, 8, 9
Searching in array: 6, 6, 7, 8, 9
Searching in array: 8, 9
Found 8 at index: 8

Searching in array: 0, 1, 2, 5, 5, 6, 6, 7, 8, 9
Searching in array: 0, 1, 2, 5, 5
Searching in array: 5, 5
Found 5 at index: 3

Searching in array: 0, 1, 2, 5, 5, 6, 6, 7, 8, 9
Searching in array: 6, 6, 7, 8, 9
Searching in array: 8, 9
Searching in array: 9
Found 999 at index: -1
```

## 🙇 Author

[Vladimir Davidov](https://github.com/v-dav) - Holberton School
