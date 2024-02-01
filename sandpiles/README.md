# Sandpiles

![C](https://img.shields.io/badge/C-00599C?style=for-the-badge&logo=c&logoColor=white)


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

##  🙇 Author

[Vladimir Davidov](https://github.com/v-dav) - Holberton School
