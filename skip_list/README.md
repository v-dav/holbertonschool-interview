# Linear Search in Skip List

![C](https://img.shields.io/badge/C-00599C?style=for-the-badge&logo=c&logoColor=white)

## 🧐 Overview
In computer science, linear search is a straightforward algorithm for finding a target value within a list. However, when dealing with large sorted singly linked lists, linear search can become inefficient as it requires traversing every element in the list. To improve search performance, we can implement a skip list, which adds an "express lane" to the list to reduce the time complexity of searches.

## 👨🏼‍🏫 Function Prototype:

The Linear Search and Skip List project aims to implement a function that searches for a specific value in a sorted skip list of integers. This function, linear_skip, takes a pointer to the head of the skip list and the value to search for as input and returns a pointer to the first node where the value is located.

```c
skiplist_t *linear_skip(skiplist_t *list, int value);
```

- `list`: A pointer to the head of the skip list to search in.
- `value`: The value to search for in the skip list.

## Implementation Details:

- A skip list comprises a singly linked list with an additional "express lane" that skips over multiple elements at regular intervals.
- Nodes in the express lane are positioned at indices that are multiples of the square root of the list's size.
- The `linear_skip` function employs a combination of linear search and skip list traversal to efficiently locate the target value.
- When comparing values in the list to the target value, the function prints each value it checks for better understanding and debugging.


## 🧑🏼‍💻 Usage Example:

```c
skiplist_t *result = linear_skip(head, target_value);
```

- `result`: A pointer to the first node where the target value is located.
- `head`: The head of the skip list.
- `target_value`: The value to search for in the skip list.

### Example Output:

```
List :
Index[0] = [0]
Index[1] = [1]
Index[2] = [2]
Index[3] = [3]
Index[4] = [4]
Index[5] = [7]
Index[6] = [12]
Index[7] = [15]
Index[8] = [18]
Index[9] = [19]
Index[10] = [23]
Index[11] = [53]
Index[12] = [61]
Index[13] = [62]
Index[14] = [76]
Index[15] = [99]

Express lane :
Index[0] = [0]
Index[4] = [4]
Index[8] = [18]
Index[12] = [61]

Value checked at index [4] = [4]
Value checked at index [8] = [18]
Value checked at index [12] = [61]
Value found between indexes [8] and [12]
Value checked at index [8] = [18]
Value checked at index [9] = [19]
Value checked at index [10] = [23]
Value checked at index [11] = [53]
Found 53 at index: 11
```

## 🧑🏼‍💻 Leetcode:


##  🙇 Author

[Vladimir Davidov](https://github.com/v-dav) - Holberton School

