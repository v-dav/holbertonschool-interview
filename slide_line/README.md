# 2048 Game (in single line)

![C](https://img.shields.io/badge/C-00599C?style=for-the-badge&logo=c&logoColor=white)

<p align="center">
    <img src="https://github.com/v-dav/holbertonschool-interview/assets/115344057/b513d566-ced0-41ed-a719-ad6e78b59f82">
</p>

## 🧐 Project Overview

The goal of this project is to implement a function that reproduces the mechanics of the 2048 game on a single horizontal line. Given an array of integers representing a line, the function should be able to slide and merge the elements to the left or right direction, similar to the movement in the 2048 game. Identical numbers should be merged if they are contiguous or separated by zeros.

## 🎓 Problem Description
- Given an array of integers line representing the game line.
- The function slide_line slides and merges the elements of the line to the specified direction.
- Returns 1 upon success or 0 upon failure.
- Direction can be either SLIDE_LEFT or SLIDE_RIGHT.
- Macros SLIDE_LEFT and SLIDE_RIGHT must be defined in slide_line.h.

## 🎓 Prototype

```c
int slide_line(int *line, size_t size, int direction);

```

- line: Pointer to an array of integers containing size elements to be slided and merged.
- size: Number of elements in the line array.
- direction: Integer representing the direction of slide, either SLIDE_LEFT or SLIDE_RIGHT.


## 🧑🏼‍💻 Usage

You can use the function in your C program as follows:

```
alex@~/slide_line$ cat 0-main.c 
#include <stdlib.h>
#include <stdio.h>

#include "slide_line.h"

#define LINE_SIZE   32

/**
 * print_array - Prints out an array of integer, followed by a new line
 * 
 * @array: Pointer to the array of integer to be printed
 * @size: Number of elements in @array
 */
static void print_array(int const *array, size_t size)
{
    size_t i;

    printf("Line: ");
    for (i = 0; i < size; i++)
        printf("%s%d", i > 0 ? ", " : "", array[i]);
    printf("\n");
}

/**
 * main - Entry point
 *
 * @ac: Arguments counter
 * @av: Arguments vector
 *
 * Return: EXIT_SUCCESS or EXIT_FAILURE
 */
int main(int ac, char **av)
{
    int line[LINE_SIZE];
    int direction;
    size_t i, size;

    if (ac < 3)
    {
        fprintf(stderr, "Usage: %s <R/L> <n1> [n2...]\n", av[0]);
        return (EXIT_FAILURE);
    }

    /* Command line arguments to array of int */
    size = ac - 2;
    if (size > LINE_SIZE)
        size = LINE_SIZE;
    for (i = 0; i < size; i++)
        line[i] = atoi(av[i + 2]);

    /* Print the array */
    print_array(line, size);

    /* Parse direction */
    switch (*(av[1]))
    {
    case 'L':
        direction = SLIDE_LEFT;
        printf("Slide to the left\n");
        break;
    case 'R':
        direction = SLIDE_RIGHT;
        printf("Slide to the right\n");
        break;
    default:
        fprintf(stderr, "Unknown direction '%c'. Please use 'L' or 'R'", *(av[1]));
        return (EXIT_FAILURE);
    }

    /* Slide and merge */
    if (!slide_line(line, size, direction))
    {
        fprintf(stderr, "Failed to slide and merge line\n");
        return (EXIT_FAILURE);
    }

    /* Print the array */
    print_array(line, size);

    return (EXIT_SUCCESS);
}
alex@~/slide_line$ gcc -Wall -Wextra -Werror -pedantic -o 0-slide_line 0-main.c 0-slide_line.c
alex@~/slide_line$ ./0-slide_line L 2 2 0 0
Line: 2, 2, 0, 0
Slide to the left
Line: 4, 0, 0, 0
alex@~/slide_line$ ./0-slide_line L 2 2 0 0 0 0 0 2 0 0 0 2 0 4
Line: 2, 2, 0, 0, 0, 0, 0, 2, 0, 0, 0, 2, 0, 4
Slide to the left
Line: 4, 4, 4, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0
alex@~/slide_line$ ./0-slide_line R 2 2 2 2
Line: 2, 2, 2, 2
Slide to the right
Line: 0, 0, 4, 4
alex@~/slide_line$ ./0-slide_line R 2 2 2 2 2
Line: 2, 2, 2, 2, 2
Slide to the right
Line: 0, 0, 2, 4, 4
alex@~/slide_line$ ./0-slide_line L 2 4 8 16
Line: 2, 4, 8, 16
Slide to the left
Line: 2, 4, 8, 16
alex@~/slide_line$ ./0-slide_line R 2 4 8 16
Line: 2, 4, 8, 16
Slide to the right
Line: 2, 4, 8, 16
alex@~/slide_line$ ./0-slide_line R 4 4 8 16
Line: 4, 4, 8, 16
Slide to the right
Line: 0, 8, 8, 16
alex@~/slide_line$
```

## 🧑🏼‍💻 Ressources

- [2048 Game Mechanics](https://en.wikipedia.org/wiki/2048_(video_game))
- [C Programming Language](https://en.wikipedia.org/wiki/C_(programming_language))
- [Arrays in C](https://www.geeksforgeeks.org/arrays-in-c-cpp/)
- [Pointers in C](https://www.geeksforgeeks.org/pointers-c-cpp/)
- [Conditional Statements in C](https://www.geeksforgeeks.org/decision-making-c-c-else-nested-else/)
- [C Standard Library](https://en.wikipedia.org/wiki/C_standard_library)

##  🙇 Author

[Vladimir Davidov](https://github.com/v-dav) - Holberton School
