#!/usr/bin/python3
"""Nqueens Algorithm"""

import sys

# Constraints
if len(sys.argv) != 2:
    print("Usage: nqueens N")
    exit(1)

try:
    N = int(sys.argv[1])
except ValueError:
    print("N must be a number")
    exit(1)

if N < 4:
    print("N must be at least 4")
    exit(1)

# Set-up
board = [["."] * N for _ in range(N)]
result = []

# Algorithm
column = set()  # Follows columns with a queen
positive_diagonal = set()  # (row + col) constant
negative_diagonal = set()  # (row - col) constant


def backtrack(row):
    if row == N:
        result.append([[i, board[i].index("Q")] for i in range(N)])
        return

    for col in range(N):
        diff = row - col
        _sum = row + col
        if not (col in column or
                diff in positive_diagonal or
                _sum in negative_diagonal):

            column.add(col)
            positive_diagonal.add(diff)
            negative_diagonal.add(_sum)
            board[row][col] = "Q"

            backtrack(row + 1)

            # Reset the path
            column.remove(col)
            positive_diagonal.remove(diff)
            negative_diagonal.remove(_sum)
            board[row][col] = "."


backtrack(0)

# Print results
for res in result:
    print(res)
