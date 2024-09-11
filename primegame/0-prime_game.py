#!/usr/bin/python3
'''
Defines function that returns a list of integers
representing the pascal's triangle of n
'''


def isWinner(x, nums):
    '''
    Generates Pascal's Triangle up to the nth row.

    Args:
        n (int): The number of rows in Pascal's triangle to generate.

    Returns:
        List[List[int]]: list of lists of ints representing Pascal's triangle.
                         Each inner list represents a row of the triangle.

    Example:
        >>> pascal_triangle(5)
        [[1], [1, 1], [1, 2, 1], [1, 3, 3, 1], [1, 4, 6, 4, 1]]
    '''
    
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
    '''
    Removes multiples of a prime number
    '''
    
    for i in range(2, len(ls)):
        try:
            ls[i * x] = 0
        except (ValueError, IndexError):
            break
