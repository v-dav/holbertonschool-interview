# Infinite Multiplication

![C Programming](https://img.shields.io/badge/C-00599C?style=for-the-badge&logo=c&logoColor=white)

## Project Description

This project, "Infinite Multiplication," involves developing a C program that can multiply two arbitrarily large positive numbers passed as command-line arguments. The challenge is to handle very large numbers that typically exceed the capacity of standard data types. This project tests your understanding of memory management, command-line argument parsing, and integer manipulation without relying on the standard library functions for multiplication.

## Constraints

- Only `malloc`, `free`, and `exit` are allowed from the C standard library.
- The program must handle errors, such as incorrect argument count or non-digit characters in arguments, by printing "Error" and exiting with a status of 98.
- Memory management is crucial; ensure there are no memory leaks or undefined behaviors.
- The program should use a custom implementation to display results since standard output functions are not allowed.

## Usage

### Compilation

```bash
gcc -Wall -pedantic -Werror -Wextra 0-mul.c _putchar.c -o mul
```

### Execution

```bash
./mul [num1] [num2]
```

- `num1` and `num2` should be strings of digits representing positive integers.
- The program will output the product of `num1` and `num2`.

### Examples

**1. Simple Multiplication**

```bash
./mul 10 98
```
**Output:**
```
980
```

**2. Large Numbers**

```bash
./mul 9999999999999999999999999999 9999999999999999999999999999
```
**Output:**
```
99999999999999999999999999980000000000000000000000000000000001
```

**3. Error Handling**

```bash
./mul 123 abc
```
**Output:**
```
Error
```

## Author

- [Vladimir Davidov](https://github.com/v-dav)
