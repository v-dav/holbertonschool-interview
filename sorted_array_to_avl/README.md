# AVL Tree Construction from Sorted Array

![C](https://img.shields.io/badge/C-00599C?style=for-the-badge&logo=c&logoColor=white)

<p align="center">
    <img src='https://github.com/v-dav/holbertonschool-interview/assets/115344057/d0f418f4-7d32-4005-8d56-c6d152d61066'>
</p>

## 🧐 Overview
This project involves writing a function in C that constructs an AVL (Adelson-Velsky and Landis) tree from a sorted array. AVL trees are self-balancing binary search trees where the heights of the two child subtrees of any node differ by at most one.

## 👨🏼‍🏫 Function Prototype:
```c
avl_t *sorted_array_to_avl(int *array, size_t size);
```

- `array`: A pointer to the first element of the sorted array to be converted into an AVL tree.
- `size`: The number of elements in the array.

## ⚙️ Functionality:
- The function constructs an AVL tree from a sorted array.
- It returns a pointer to the root node of the created AVL tree, or NULL on failure.
- Duplicate values are not allowed in the array.
- Rotation operations are not permitted.

## ❗️Constraints:
- The implementation should consist of only three functions.
- Rotations are not allowed, implying a simpler approach to AVL tree construction.

## 🧑🏼‍💻 Usage Example:
```c
#include "binary_trees.h"

int main(void)
{
    int array[] = {1, 2, 3, 4, 5, 6, 7};
    size_t size = sizeof(array) / sizeof(array[0]);
    avl_t *root = sorted_array_to_avl(array, size);
    return (0);
}
```

## 🎓 Resources:
- [AVL Tree](https://en.wikipedia.org/wiki/AVL_tree)
- [Binary Trees](https://en.wikipedia.org/wiki/Binary_tree)

## 🧑🏼‍💻 Leetcode:
![Skärmavbild 2024-04-09 kl  14 53 18](https://github.com/v-dav/holbertonschool-interview/assets/115344057/7f35c645-73cc-4273-b9a0-84d06f86e9f1)


##  🙇 Author

[Vladimir Davidov](https://github.com/v-dav) - Holberton School



