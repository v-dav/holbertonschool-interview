# Radix Sort Implementation in C

![C](https://img.shields.io/badge/C-Programming-blue)

## Project Description

This project implements the Radix Sort algorithm to sort an array of integers in ascending order. The Radix Sort is a non-comparative sorting algorithm that sorts numbers by processing individual digits. This implementation uses the Least Significant Digit (LSD) method of Radix Sort, where sorting starts from the least significant digit to the most significant digit.

## Features and Concepts Implemented

- **Radix Sort Algorithm**: Implements the LSD radix sort algorithm.
- **Dynamic Memory Allocation**: Utilizes `malloc` and `free` for dynamic memory management.
- **Counting Sort**: Uses counting sort as a subroutine to sort digits at each significant position.
- **Utility Function**: Includes a utility function to find the maximum value in the array.
- **Digit-by-Digit Processing**: Processes each digit of the numbers starting from the least significant digit.
- **Array Printing**: Prints the array each time the significant digit is increased to show the progress of sorting.


## Usage Example

### Example Code: `0-main.c`
```c
#include <stdio.h>
#include <stdlib.h>
#include "sort.h"

/**
 * main - Entry point
 *
 * Return: Always 0
 */
int main(void)
{
    int array[] = {19, 48, 99, 71, 13, 52, 96, 73, 86, 7};
    size_t n = sizeof(array) / sizeof(array[0]);

    print_array(array, n);
    printf("\n");
    radix_sort(array, n);
    printf("\n");
    print_array(array, n);
    return (0);
}
```

### Expected Output
```
19, 48, 99, 71, 13, 52, 96, 73, 86, 7

71, 52, 13, 73, 96, 86, 7, 48, 19, 99
7, 13, 19, 48, 52, 71, 73, 86, 96, 99

7, 13, 19, 48, 52, 71, 73, 86, 96, 99
```

## Author

- [Vladimir Davidov](https://github.com/v-dav)
