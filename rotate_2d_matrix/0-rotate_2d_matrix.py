#!/usr/bin/python3
"""Rotate 2D matrixw algorithm"""


def rotate_2d_matrix(matrix):
    """Algorithm that rotates matrix by 90°"""
    size = len(matrix)
    for i in range(size // 2):
        for j in range(i, size - i - 1):
            # Save the top element
            temp = matrix[i][j]

            # Move left element to top
            matrix[i][j] = matrix[size - j - 1][i]

            # Move bottom element to left
            matrix[size - j - 1][i] = matrix[size - i - 1][size - j - 1]

            # Move right element to bottom
            matrix[size - i - 1][size - j - 1] = matrix[j][size - i - 1]

            # Move top element to right
            matrix[j][size - i - 1] = temp
