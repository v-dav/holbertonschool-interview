#!/usr/bin/python3
"""
This module contains the function makeChange(coins, total).
"""


def makeChange(coins, total):
    """Make change for a given total using the fewest number of coins.
    Args:
        coins: a list of integers representing coin denominations
        total: an integer representing the total amount of change to make
    Returns:
        An integer representing the fewest number of coins to make the given
        total. If the total cannot be made with the given coins, return -1.
    """
    if total <= 0:
        return 0
    dp = [float('inf')] * (total + 1)
    dp[0] = 0

    for coin in coins:
        for i in range(coin, total + 1):
            dp[i] = min(dp[i], dp[i - coin] + 1)

    return dp[total] if dp[total] != float('inf') else -1
