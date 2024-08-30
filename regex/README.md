# Simple Regex Matcher

This project implements a simple regular expression matcher in C. It provides a function to check whether a given pattern matches a given string.

## Features

- Supports basic regex patterns:
  - `.` matches any single character
  - `*` matches zero or more occurrences of the previous character
- Implemented using recursive matching algorithm

## Files

- `regex.c`: Contains the implementation of the regex matching function
- `regex.h`: Header file with the function prototype

## Usage

Include the `regex.h` header in your C file and call the `regex_match` function:

```c
#include "regex.h"

int main() {
    const char *str = "hello";
    const char *pattern = "h.l*o";
    
    if (regex_match(str, pattern)) {
        printf("Match found!\n");
    } else {
        printf("No match.\n");
    }
    
    return 0;
}
```

## Function Documentation

```c
int regex_match(char const *str, char const *pattern)
```

Checks whether a given pattern matches a given string.

### Parameters

- `str`: The string to check
- `pattern`: The regex pattern to match against

### Return Value

- `1` if the pattern matches the string
- `0` if it doesn't match or if either input is NULL

## Limitations

- This is a basic implementation and does not support all regex features
- The recursive approach may not be efficient for very long strings or complex patterns

## Building

Compile `regex.c` with your C compiler. For example:

```
gcc -c regex.c -o regex.o
```

Then link it with your main program.

## Author
Vladimir Davidov
