#!/usr/bin/python3
"""Prime game module"""


def isWinner(x, nums):
    """
    Determines the winner of the prime game.
    
    Args:
        x (int): The number of rounds.
        nums (list): A list of n for each round.
    
    Returns:
        str: Name of the winner (Maria or Ben) or None.
    """
    if x <= 0 or nums is None:
        return None
    if x != len(nums):
        return None

    ben = 0
    maria = 0
    a = [1 for x in range(sorted(nums)[-1] + 1)]
    a[0], a[1] = 0, 0

    for i in range(2, len(a)):
        rm_multiples(a, i)

    for i in nums:
        if sum(a[0:i + 1]) % 2 == 0:
            ben += 1
        else:
            maria += 1

    if ben > maria:
        return "Ben"
    if maria > ben:
        return "Maria"
    return None


def rm_multiples(ls, x):
    """Removes multiples of a prime number"""
    for i in range(2, len(ls)):
        try:
            ls[i * x] = 0
        except (ValueError, IndexError):
            break
