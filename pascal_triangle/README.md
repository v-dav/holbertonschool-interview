
# Pascal's Triangle

![Python](https://img.shields.io/badge/Python-3776AB?style=for-the-badge&logo=python&logoColor=white)

## Description

This project implements a function that generates Pascal's Triangle up to a given number of rows, `n`. Pascal's Triangle is a triangular array where each entry is the sum of the two directly above it.

## Function Prototype

```python
def pascal_triangle(n):
```

### Parameters:
- `n` (int): The number of rows of Pascal's Triangle to generate.

### Returns:
- A list of lists of integers representing Pascal's Triangle up to the `n`th row.
- If `n <= 0`, the function returns an empty list.

## Example Usage

### Example Code

Here's a simple usage example of the `pascal_triangle` function:

```python
#!/usr/bin/python3
"""
main
"""
pascal_triangle = __import__('0-pascal_triangle').pascal_triangle

def print_triangle(triangle):
    """
    Print the triangle
    """
    for row in triangle:
        print("[{}]".format(",".join([str(x) for x in row])))


if __name__ == "__main__":
    print_triangle(pascal_triangle(5))
```

### Example Output

When the code is executed with `n = 5`, it generates and prints the first five rows of Pascal's Triangle:

```
[1]
[1,1]
[1,2,1]
[1,3,3,1]
[1,4,6,4,1]
```

## Author

Vladimir Davidov
