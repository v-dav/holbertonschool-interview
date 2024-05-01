# Rain Algorithm

![Python](https://img.shields.io/badge/Python-3.9-blue)

This project implements an algorithm to calculate the amount of rainwater retained between walls represented by a list of non-negative integers.

## Project Description

Given a list of non-negative integers representing the heights of walls with a unit width of 1, the task is to calculate how many square units of water will be retained after it rains.

The algorithm takes a list of wall heights as input and returns an integer indicating the total amount of rainwater retained.

## Prototype

```python
def rain(walls):
    """
    Calculates the amount of rainwater retained between walls.
    
    Args:
        walls (list): A list of non-negative integers representing wall heights.
    
    Returns:
        int: Total amount of rainwater retained.
    """
    # Implementation of the rainwater trapping algorithm
    pass
```

### Specifications

- `walls`: List of non-negative integers representing wall heights.
- The ends of the list (before index 0 and after index `walls[-1]`) are not considered walls.
- If the list is empty, the function returns `0`.

## Usage

To test the rainwater trapping algorithm, use the provided script `0_main.py`:

```python
#!/usr/bin/python3
"""
0_main
"""
from 0-rain import rain

if __name__ == "__main__":
    walls = [0, 1, 0, 2, 0, 3, 0, 4]
    print(rain(walls))  # Output: 6

    walls = [2, 0, 0, 4, 0, 0, 1, 0]
    print(rain(walls))  # Output: 6
```

Feel free to integrate this algorithm into your project and explore rainwater trapping in action! 🌧️
