# The Lockboxes Problem

![Skärmavbild 2024-01-04 kl  13 44 27](https://github.com/v-dav/holbertonschool-interview/assets/115344057/249258c2-ecb2-480b-bde1-72e3a0d37d73)


You have n number of locked boxes in front of you. Each box is numbered sequentially from 0 to n - 1 and each box may contain keys to the other boxes.

Write a method that determines if all the boxes can be opened.

- **Prototype:** def canUnlockAll(boxes)
- boxes is a list of lists
- A key with the same number as a box opens that box
- You can assume all keys will be positive integers
- There can be keys that do not have boxes
- The first box boxes[0] is unlocked
- Return True if all boxes can be opened, else return False
