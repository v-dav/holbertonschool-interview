# AVL Tree Validation

![C](https://img.shields.io/badge/C-00599C?style=for-the-badge&logo=c&logoColor=white)

## Description

This project implements a function to check if a given binary tree is a valid AVL Tree. An AVL Tree (Adelson-Velsky and Landis Tree) is a self-balancing binary search tree (BST) where the difference between the heights of the left and right subtrees cannot be more than one for all nodes.

## Data Structures

The project uses the following data structures for binary trees:

### Basic Binary Tree

```c
/**
 * struct binary_tree_s - Binary tree node
 *
 * @n: Integer stored in the node
 * @parent: Pointer to the parent node
 * @left: Pointer to the left child node
 * @right: Pointer to the right child node
 */
struct binary_tree_s
{
    int n;
    struct binary_tree_s *parent;
    struct binary_tree_s *left;
    struct binary_tree_s *right;
};

typedef struct binary_tree_s binary_tree_t;
```

### AVL Tree

```c
typedef struct binary_tree_s avl_t;
```

## Function Prototype

```c
int binary_tree_is_avl(const binary_tree_t *tree);
```

- **Parameters:**
  - `tree` (const binary_tree_t*): Pointer to the root node of the tree to check.

- **Returns:**
  - `1` if the tree is a valid AVL Tree.
  - `0` otherwise.

## Properties of an AVL Tree

1. An AVL Tree is a Binary Search Tree (BST).
2. The difference between heights of left and right subtrees cannot be more than one.
3. The left and right subtrees each must also be a binary search tree.

## Author

Vladimir Davidov
