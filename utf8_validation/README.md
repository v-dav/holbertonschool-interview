# UTF-8 validation
![Python](https://img.shields.io/badge/Python-Algorithms-blue?style=for-the-badge&logo=python&logoColor=white)

![maxresdefault](https://github.com/v-dav/holbertonschool-interview/assets/115344057/55622d44-d823-436e-9a3e-601900629318)


## 🧐 Project Overview
This project is about writing an algorithm implementing a function that determines whether a given data set represents a valid UTF-8 encoding. UTF-8 is a character encoding capable of representing all possible characters, or code points, in Unicode. The goal is to validate whether a sequence of bytes, represented as a list of integers, adheres to the rules of UTF-8 encoding.

## Task Description



```python
def validUTF8(data)
```

- Return: True if data is a valid UTF-8 encoding, else return False
- A character in UTF-8 can be 1 to 4 bytes long
- The data set can contain multiple characters
- The data will be represented by a list of integers
- Each integer represents 1 byte of data, therefore you only need to handle the 8 least significant bits of each integer

## Example

```#!/usr/bin/python3
"""
Main file for testing
"""

validUTF8 = __import__('0-validate_utf8').validUTF8

data = [65]
print(validUTF8(data))

data = [80, 121, 116, 104, 111, 110, 32, 105, 115, 32, 99, 111, 111, 108, 33]
print(validUTF8(data))

data = [229, 65, 127, 256]
print(validUTF8(data))
```

## Result
```
True
True
False
```

## 🧑🏼‍💻 Leetcode
![Skärmavbild 2024-03-07 kl  12 17 27](https://github.com/v-dav/holbertonschool-interview/assets/115344057/037f071f-3942-4018-9634-50c1e9aeda60)


##  🙇 Author

[Vladimir Davidov](https://github.com/v-dav) - Holberton School
