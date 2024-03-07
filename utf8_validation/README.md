## UTF-8 validation

![image](https://github.com/TessierV/holbertonschool-interview/assets/113889290/5a74f781-d1a1-4ba7-9ce4-100ff0aa69bd)

# Overview
This project is about writing an algorithm implementing a function that determines whether a given data set represents a valid UTF-8 encoding. UTF-8 is a character encoding capable of representing all possible characters, or code points, in Unicode. The goal is to validate whether a sequence of bytes, represented as a list of integers, adheres to the rules of UTF-8 encoding.

# Test

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

# Result
```
True
True
False
```
