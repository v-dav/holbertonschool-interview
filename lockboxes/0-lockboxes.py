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

    for box_index in checked_boxes:
        for key in boxes[box_index]:
            if key not in range(boxes_length):
                continue
            elif key not in checked_boxes:
                checked_boxes.append(key)
                boxes_status[key] = True


####################

    # for i in range(boxes_length):
    #     if i not in checked_keys:
    #         continue
    #     boxes_status[i] = True
    #     nbKeysPerBox = len(boxes[i])
    #     for j in range(nbKeysPerBox):
    #         key = boxes[i][j]
    #         if (key not in range(boxes_length)) or (key in checked_keys):
    #             continue
    #         elif not boxes[key]:
    #             boxes_status[key] = True
    #             continue
    #         else:
    #             checked_keys.append(key)
    #             i = key
    #             break

    # Check if some boxes are still closed
    if False in boxes_status:
        return False

    return True

    # print(boxes_status)
    # print(checked_boxes)

# boxes = [[1, 4], [2], [0, 4, 1], [3], [], [4, 1], [5, 6]]
# canUnlockAll(boxes)
