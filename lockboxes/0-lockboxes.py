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

    checked_boxes = [0]
    boxes_length = len(boxes)
    
    # The checking
    for box in checked_boxes:
        for key in boxes[box]:
            if key not in range(boxes_length):
                continue
            elif key not in checked_boxes:
                checked_boxes.append(key)
                boxes_status[key] = True

    # Check if some boxes are still closed
    if False in boxes_status:
        return False
    return True
