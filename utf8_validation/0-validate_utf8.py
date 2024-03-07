#!/usr/bin/python3
"""UTF validation algorithm"""


def validUTF8(data):
    """A method that determines if a given data
    set represents a valid UTF-8 encoding.

    Time complexity: O(n) as we are iterating on data set
    Space complexity: O(1) as we use a constant amount of space

    Returns: True if data is a valid UTF-8 encoding, else return False
    """

    # Counter variable
    count = 0

    for int in data:
        # If the count is 0, check how many leading 1's there are
        # in the leading byte to determine how many bytes are expected
        # for the current character.
        if count == 0:
            if (int >> 5) == 0b110:
                count = 1
            elif (int >> 4) == 0b1110:
                count = 2
            elif (int >> 3) == 0b11110:
                count = 3
            elif (int >> 7) != 0:
                return False
        # If the count is not 0, check if the current integer
        # is a valid continuation byte
        else:
            if (int >> 6) != 0b10:
                return False
            count -= 1

    # If the count is still not 0 after iterating
    # through all the integers, it is invalid
    return count == 0
