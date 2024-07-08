# Coin Change Problem

![Python](https://img.shields.io/badge/Python-3.8-blue?style=for-the-badge&logo=python&logoColor=white)

## Project Description

This project involves solving the classic Coin Change problem. Given a set of coins of different values, the goal is to determine the fewest number of coins needed to meet a given total amount. This problem is often encountered in algorithm and data structure challenges and is a great exercise for understanding dynamic programming concepts.

## Problem Statement

Given a pile of coins of different values, determine the fewest number of coins needed to meet a given amount total.

### Prototype

```python
def makeChange(coins, total):
```

### Parameters

- `coins`: A list of integers representing the coin denominations available.
- `total`: An integer representing the total amount of change needed.

### Returns

- The fewest number of coins needed to meet the total. If the total is 0 or less, return 0.
- If the total cannot be met by any number of coins, return -1.

### Constraints

- The value of a coin will always be an integer greater than 0.
- You can assume you have an infinite number of each denomination of coin in the list.
- The solution’s runtime will be evaluated in this task.

## Usage

### Example

```python
carrie@ubuntu:~/making_change$ cat 0-main.py
#!/usr/bin/python3
"""
Main file for testing
"""

makeChange = __import__('0-making_change').makeChange

print(makeChange([1, 2, 25], 37))  # Expected output: 7
print(makeChange([1256, 54, 48, 16, 102], 1453))  # Expected output: -1

carrie@ubuntu:~/making_change$
carrie@ubuntu:~/making_change$ ./0-main.py
7
-1
carrie@ubuntu:~/making_change$
```


### How it Works

1. **Initial Check**: If the `total` is 0 or less, return 0 immediately as no coins are needed.
2. **Dynamic Programming Array**: Create an array `dp` where `dp[i]` represents the minimum number of coins needed to make the amount `i`. Initialize this array with infinity (`float('inf')`) to signify that initially, we consider that amount as unreachable.
3. **Base Case**: Set `dp[0]` to 0 because no coins are needed to make the amount 0.
4. **Update the DP Array**: For each coin in the list of coins, update the `dp` array by checking if using the current coin reduces the number of coins needed to make the amount `i`.
5. **Result**: If `dp[total]` is still infinity, it means the total cannot be made with the given coins, and we return -1. Otherwise, we return `dp[total]`.

## Author

- Vladimir Davidov

