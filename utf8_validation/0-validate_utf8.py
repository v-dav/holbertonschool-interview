#!/usr/bin/python3
"""UTF validation algorithm"""


def validUTF8(data):
    """A method that determines if a given data
    set represents a valid UTF-8 encoding.

    Time complexity: O(n) as we are iterating on data set
    Space complexity: O(1) as we use a constant amount of space

    Returns: True if data is a valid UTF-8 encoding, else return False
    """
    count = 0
    for int in data:
        if count == 0:
            if (int >> 5) == 0b110:
                count = 1
            elif (int >> 4) == 0b1110:
                count = 2
            elif (int >> 3) == 0b11110:
                count = 3
            elif (int >> 7) == 1:
                return False
        else:
            if (int >> 6) != 0b10:
                return False
            count -= 1
    return count == 0
