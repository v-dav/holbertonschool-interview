#!/usr/bin/python3
"""A minimal operations algorithm"""


def find(number):
    """An algorithm that defines the minimum amount of ops"""
    res = 0
    i = 2
    while i <= number:
        while number % i == 0:
            res += i
            number = number // i
        i += 1
    return res
