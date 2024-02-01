# Sandpiles

![C](https://img.shields.io/badge/C-00599C?style=for-the-badge&logo=c&logoColor=white)

![image](https://github.com/v-dav/holbertonschool-interview/assets/115344057/82153c60-5f8d-4bbf-ae31-0b0277a2c754)


## 🧐 Project Overview

This project involves the computation of the sum of two sandpiles. A sandpile is considered stable when none of its cells contains more than 3 grains. The goal is to write a function that adds two given sandpiles and ensures the stability of the resulting sandpile.


## 🎓 Prototype

```c
void sandpiles_sum(int grid1[3][3], int grid2[3][3]);
```

### ❗️ Constraints

- Both `grid1` and `grid2` are individually stable.
- A sandpile is stable when none of its cells contains more than 3 grains.
- Memory allocation is not allowed.

## ⚙️ Implementation Details

When the `sandpiles_sum` function is called, it computes the sum of two sandpiles (`grid1` and `grid2`). The result is stored in `grid1`, and the function ensures the stability of the resulting sandpile.

The stability of the sandpile is maintained by toppling any cell that contains more than 3 grains. The process is repeated until the sandpile becomes stable.

## 👨🏼‍🏫 Whiteboard

![Skärmavbild 2024-02-01 kl  15 10 14](https://github.com/v-dav/holbertonschool-interview/assets/115344057/8aa961c8-a790-4c0a-a203-019e6d4160a0)


## 🧑🏼‍💻 Usage

You can use the function in your C program as follows:

```c
#include <stdio.h>

int main() {
    // Example sandpiles
    int grid1[3][3] = {
        {1, 2, 3},
        {4, 5, 6},
        {7, 8, 9}
    };
    
    int grid2[3][3] = {
        {9, 8, 7},
        {6, 5, 4},
        {3, 2, 1}
    };

    // Compute the sum of sandpiles
    sandpiles_sum(grid1, grid2);

    return 0;
}
```

## 👀 Example

```
alex@~/sandpiles$ cat 0-main.c 
#include <stdlib.h>
#include <stdio.h>

#include "sandpiles.h"

/**
 * print_grid_sum - Print 3x3 grids sum
 * @grid1: Left 3x3 grid
 * @grid2: Right 3x3 grid
 *
 */
static void print_grid_sum(int grid1[3][3], int grid2[3][3])
{
    int i, j;

    for (i = 0; i < 3; i++)
    {
        for (j = 0; j < 3; j++)
        {
            if (j)
                printf(" ");
            printf("%d", grid1[i][j]);
        }

        printf(" %c ", (i == 1 ? '+' : ' '));

        for (j = 0; j < 3; j++)
        {
            if (j)
                printf(" ");
            printf("%d", grid2[i][j]);
        }
        printf("\n");
    }
}

/**
 * print_grid - Print 3x3 grid
 * @grid: 3x3 grid
 *
 */
static void print_grid(int grid[3][3])
{
    int i, j;

    for (i = 0; i < 3; i++)
    {
        for (j = 0; j < 3; j++)
        {
            if (j)
                printf(" ");
            printf("%d", grid[i][j]);
        }
        printf("\n");
    }
}

/**
 * main - Entry point
 *
 * Return: EXIT_SUCCESS or EXIT_FAILURE
 */
int main(void)
{
    int grid1[3][3] = {
        {3, 3, 3},
        {3, 3, 3},
        {3, 3, 3}
    };
    int grid2[3][3] = {
        {1, 3, 1},
        {3, 3, 3},
        {1, 3, 1}
    };

    print_grid_sum(grid1, grid2);

    sandpiles_sum(grid1, grid2);

    printf("=\n");
    print_grid(grid1);

    return (EXIT_SUCCESS);
}
alex@~/sandpiles$ gcc -Wall -Wextra -Werror -pedantic 0-main.c 0-sandpiles.c -o 0-sandpiles
alex@~/sandpiles$ ./0-sandpiles 
3 3 3   1 3 1
3 3 3 + 3 3 3
3 3 3   1 3 1
=
4 6 4
6 6 6
4 6 4
=
2 5 2
5 6 5
2 5 2
=
4 2 4
2 6 2
4 2 4
=
0 5 0
5 2 5
0 5 0
=
2 1 2
1 6 1
2 1 2
=
2 2 2
2 2 2
2 2 2
alex@~/sandpiles$ cat 1-main.c
Same as 0-main.c except:
int grid1[3][3] = {
        {0, 0, 0},
        {0, 0, 0},
        {0, 0, 0}
    };
    int grid2[3][3] = {
        {3, 3, 3},
        {3, 3, 3},
        {3, 3, 3}
    };
alex@~/sandpiles$ gcc -Wall -Wextra -Werror -pedantic 1-main.c 0-sandpiles.c -o 0-sandpiles
alex@~/sandpiles$ ./0-sandpiles 
0 0 0   3 3 3
0 0 0 + 3 3 3
0 0 0   3 3 3
=
3 3 3
3 3 3
3 3 3
alex@~/sandpiles$
```

##  🙇 Author

[Vladimir Davidov](https://github.com/v-dav) - Holberton School
