# Substring Search

This project implements a function that finds all possible substrings containing a list of words within a given string.

## Problem Description

Given a string `s` and an array of words `words`, the task is to find all starting indices of substrings in `s` that are a concatenation of each word in `words` exactly once without any intervening characters.

## Function Prototype

```c
int *find_substring(char const *s, char const **words, int nb_words, int *n);
```

### Parameters

- `s`: The string to scan
- `words`: An array of words all substrings must be a concatenation arrangement of
- `nb_words`: The number of elements in the array `words`
- `n`: A pointer to store the number of elements in the returned array

### Return Value

- The function returns an allocated array storing each index in `s` at which a substring was found.
- If no solution is found, the function returns NULL.

## Constraints

- All words in the array `words` are the same length.
- A valid substring of `s` is the concatenation of each word in `words` exactly once and without any intervening characters.

## Implementation

The solution is implemented in C and consists of the following files:

1. `substring.h`: Header file containing function prototypes and necessary includes.
2. `substring.c`: Source file containing the implementation of the `find_substring` function and helper functions.

## How to Use

1. Include the `substring.h` header in your C program.
2. Compile your program with `substring.c`.
3. Call the `find_substring` function with appropriate parameters.

Example usage:

```c
#include "substring.h"

int main()
{
    const char *s = "barfoothefoobarman";
    const char *words[] = {"foo", "bar"};
    int nb_words = 2;
    int n;
    int *indices = find_substring(s, words, nb_words, &n);

    // Process the results...

    free(indices);
    return 0;
}
```

## Compilation

To compile the program, use a C compiler like gcc:

```
gcc -Wall -Wextra -Werror -pedantic main.c substring.c -o substring_search
```

## Examples

1. Input:
   - s: "barfoothefoobarman"
   - words: ["foo", "bar"]
   Output: [0, 9]

2. Input:
   - s: "wordgoodgoodgoodbestword"
   - words: ["word", "good", "best", "word"]
   Output: []

3. Input:
   - s: "wordgoodgoodgoodbestword"
   - words: ["word", "good", "best", "good"]
   Output: [8]
