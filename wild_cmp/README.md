# Wild String Comparison

![C](https://img.shields.io/badge/C-00599C?style=for-the-badge&logo=c&logoColor=white)

## Description

This project implements a function that compares two strings to determine if they can be considered identical. The second string (`s2`) can contain the special wildcard character `*`, which can replace any string, including an empty string. This is particularly useful for pattern matching scenarios where flexibility is needed in the string comparison.

## Function Prototype

```c
int wildcmp(char *s1, char *s2);
```

- **Parameters:**
  - `s1`: Pointer to the first string.
  - `s2`: Pointer to the second string, which may contain the `*` wildcard character.

- **Returns:**
  - `1` if the strings can be considered identical.
  - `0` otherwise.

## Files in This Project

### 1. Header File (`holberton.h`)

This file contains the function prototypes and includes any necessary libraries.

### 2. Principal Source File

This file contains the implementation of the functions necessary to perform the string comparison.

### Main Concepts Used

- **Recursion:** The function uses recursion to traverse and compare the characters of the two strings. When encountering the `*` wildcard, the function branches out, exploring different possibilities for matching the strings.
  
- **String Matching with Wildcards:** The `*` wildcard allows for flexible matching, replacing any substring or empty string, enabling complex pattern matching.

### Example Usage

The main file provided in the project demonstrates the usage of the `wildcmp` function by comparing various string pairs with and without wildcards:

```c
#include "holberton.h"
#include <stdio.h>

int main(void)
{
    int r;

    r = wildcmp("main.c", "*.c");
    printf("%d\n", r);
    r = wildcmp("main.c", "m*a*i*n*.*c*");
    printf("%d\n", r);
    r = wildcmp("main.c", "main.c");
    printf("%d\n", r);
    r = wildcmp("main.c", "m*c");
    printf("%d\n", r);
    r = wildcmp("main.c", "ma********************************c");
    printf("%d\n", r);
    r = wildcmp("main.c", "*");
    printf("%d\n", r);
    r = wildcmp("main.c", "***");
    printf("%d\n", r);
    r = wildcmp("main.c", "m.*c");
    printf("%d\n", r);
    r = wildcmp("main.c", "**.*c");
    printf("%d\n", r);
    r = wildcmp("main-main.c", "ma*in.c");
    printf("%d\n", r);
    r = wildcmp("main", "main*d");
    printf("%d\n", r);
    r = wildcmp("abc", "*b");
    printf("%d\n", r);
    return (0);
}
```

### Compilation and Execution

To compile and run the program, use the following commands:

```sh
gcc -Wall -pedantic -Werror -Wextra 0-main.c 0-wildcmp.c -o 0-wildcmp
./0-wildcmp
```

### Output Example

```
1
1
1
1
1
1
1
0
1
1
0
0
```

The output indicates whether the strings are considered identical (`1`) or not (`0`), based on the rules of comparison including the wildcard character `*`.

## Author

Vladimir Davidov
