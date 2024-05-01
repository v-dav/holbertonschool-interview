#!/usr/bin/python3
"""Rain algorithm module"""


def rain(walls):
    n = len(walls)
    res = 0

    # For every element of the array
    for i in range(1, n - 1):

        # Find the maximum element on its left
        left = walls[i]
        for j in range(i):
            left = max(left, walls[j])

        # Find the maximum element on its right
        right = walls[i]

        for j in range(i + 1, n):
            right = max(right, walls[j])

        # Update the maximum walls
        res = res + (min(left, right) - walls[i])

    return res
