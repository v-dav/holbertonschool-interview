#!/usr/bin/python3
"""The Lockbox algorithm"""


def canUnlockAll(boxes):
    """An algorithm that checks if all the boxes can be opened.

    Args:
        boxes: Array of arrays of positive integers

    Returns;
        bool: True if all boxes can be opened. False if not.
    """

    # Initial state of the boxes with first box always open
    boxes_status = []
    for box in boxes:
        boxes_status.append(False)
    boxes_status[0] = True

    opened_boxes = [0]
    boxes_length = len(boxes)

    # The checking: looping through opened boxes NOT on original array
    for box in opened_boxes:
        for key in boxes[box]:
            if key not in range(boxes_length):
                continue
            elif key not in opened_boxes:
                opened_boxes.append(key)
                boxes_status[key] = True

    # Check if some boxes are still closed
    if False in boxes_status:
        return False
    return True

# Time complexity: O(N + M) because it loops on each box in the worst case and it checks each key in the corresponding box
# Space complexity: O(N) because we create a list proportional in size to the original array
