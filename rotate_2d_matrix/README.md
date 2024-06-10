# Rotate 2D Matrix

![Python](https://img.shields.io/badge/Python-blue?style=for-the-badge&logo=python&logoColor=white)

<p align="center">
  <img src="https://github.com/v-dav/holbertonschool-interview/assets/115344057/719c8086-76e3-401a-bd5d-a3fbbe7d7db7" alt="cycle">
</p>

## Project Overview

This project provides a Python function to rotate an n x n 2D matrix 90 degrees clockwise. The operation modifies the matrix in-place, showcasing efficient manipulation of array elements and understanding of matrix transformations. This example serves not only as a practical demonstration of handling two-dimensional arrays in Python but also offers insights into more complex matrix operations commonly used in image processing and scientific computing.

## Functionality

The function `rotate_2d_matrix(matrix)` takes a square matrix (list of lists) as an input and rotates it 90 degrees clockwise. The transformation is performed in-place, meaning that the original matrix is directly modified and no additional matrix is created.

<p align="center">
  <img src="https://github.com/v-dav/holbertonschool-interview/assets/115344057/1c8d80bb-76ae-48ff-ae86-0c1eab589444" alt="cycle">
</p>


## How to Use

To use the rotate function, simply import and pass a matrix to it. Here's a quick example to demonstrate:

```python
rotate_2d_matrix = __import__('0-rotate_2d_matrix').rotate_2d_matrix

matrix = [
    [1, 2, 3],
    [4, 5, 6],
    [7, 8, 9]
]

rotate_2d_matrix(matrix)
print(matrix)
```

After execution, the output will be:
```
[[7, 4, 1],
 [8, 5, 2],
 [9, 6, 3]]
```

## Author

- [Vladimir Davidov](https://github.com/v-dav)
