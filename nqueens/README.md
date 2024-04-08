# N Queens
![Python](https://img.shields.io/badge/Python-Algorithms-blue?style=for-the-badge&logo=python&logoColor=white)

## 🧐 Project Overview
The N queens puzzle is the challenge of placing N non-attacking queens on an N×N chessboard. This program solves the N queens problem.

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
