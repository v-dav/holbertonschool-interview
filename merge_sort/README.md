# Merge Sort Algorithm

Implementing the merge sort algorithm to sort an array of integers in ascending order. Merge sort is a sorting technique that uses a divide-and-conquer strategy to efficiently sort data. The function, `merge_sort`, will take an array of integers and its size as parameters and will sort the array in-place.

## Function Prototype

```c
void merge_sort(int *array, size_t size);
```

## Usage

To compile the program, run:

```bash
gcc -Wall -Wextra -Werror -pedantic 0-main.c 0-merge_sort.c print_array.c -o merge
```

To execute the program, use:

```bash
./merge
```

This will print the process of sorting the array step by step, showing how the elements are merged.

## Files

- `0-merge_sort.c`: Contains the implementation of the merge sort algorithm.
- `sort.h`: Header file with function prototypes.
- `print_array.c`: Contains the `print_array` function used to print the array at various stages of sorting.
- main.c`: Main file for testing the merge sort function.

## Big O Notation

The time complexity for the Merge Sort algorithm is detailed in the file `0-O`:

- Best case: O(n log(n))
- Average case: O(n log(n))
- Worst case: O(n log(n))


## Acknowledgements

- The Merge Sort algorithm is a classic example used in numerous computer science courses and textbooks to teach efficient sorting techniques.

![C Programming](https://img.shields.io/badge/C%20Programming-gray?style=for-the-badge&logo=c&logoColor=white)

```
