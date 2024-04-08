# N Queens
![Python](https://img.shields.io/badge/Python-Algorithms-blue?style=for-the-badge&logo=python&logoColor=white)

<p align="center">
    <img src="https://github.com/v-dav/holbertonschool-interview/assets/115344057/e961df3e-e350-4a39-be4a-48d008873f09">
</p>


## 🧐 Project Overview
The n-queens puzzle is the problem of placing n queens on an n x n chessboard such that no two queens attack each other.

Given an integer n, return all distinct solutions to the n-queens puzzle. You may return the answer in any order.

Each solution contains a distinct board configuration of the n-queens' placement, where 'Q' and '.' both indicate a queen and an empty space, respectively.
## Usage

```bash
$ nqueens N
```

If the user called the program with the wrong number of arguments, it will print the following, followed by a new line, and exit with the status 1:

  ```bash
  Usage: nqueens N
  ```

N must be an integer greater or equal to 4. If N is not an integer, it will print the following, followed by a new line, and exit with the status 1:

  ```bash
  N must be a number
  ```


If N is smaller than 4, it will print the following, followed by a new line, and exit with the status 1:

  ```bash
  N must be at least 4
  ```

## Output

The program prints every possible solution to the problem, with one solution per line. Format: 

  ```
  (row, column) (row, column) (row, column) ...
  ```

  Where each `(row, column)` pair represents the position of a queen on the chessboard.

  You don’t have to print the solutions in a specific order.

## Restrictions

You are only allowed to import the sys module.

## 🧑🏼‍💻 Leetcode


##  🙇 Author

[Vladimir Davidov](https://github.com/v-dav) - Holberton School
