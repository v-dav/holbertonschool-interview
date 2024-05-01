#!/usr/bin/python3
"""Rain algorithm module"""


def rain(walls):
    """The core algorithms of the rain computation"""

    total_area = 0
    bottom_length = 0
    left_wall = 0
    right_wall = 0

    for index in range(len(walls)):
        current_height = walls[index]

        if current_height == 0:
            if (index - 1) >= 0 and walls[index - 1] != 0:
                left_wall = walls[index - 1]

            if (index + 1) < len(walls):
                right_wall = walls[index + 1]
            if left_wall != 0:
                height_left = left_wall
                bottom_length += 1

                if right_wall != 0:
                    height_right = right_wall

                    if height_left and height_right:
                        min_height = min(height_right, height_left)
                        local_area = min_height * bottom_length
                        total_area += local_area
                        bottom_length = 0
                        left_wall = 0
                        right_wall = 0

    return total_area
