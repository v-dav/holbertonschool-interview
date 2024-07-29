# Island Perimeter Calculation

![Python Badge](https://img.shields.io/badge/Python-Programming-green)

![image](https://github.com/user-attachments/assets/10f56445-997c-4cf2-8af7-fd406915aabf)


## Project Description

This project involves writing a function `island_perimeter(grid)` that calculates the perimeter of an island represented in a grid. The grid is a list of lists of integers where `0` represents water and `1` represents land. The function computes the perimeter by analyzing the grid and counting the edges of the land cells that contribute to the perimeter.

## Features and Concepts Implemented

- **Grid Representation**: The island and water are represented using a 2D grid where `1` represents land and `0` represents water.
- **Grid Analysis**: The function traverses the grid to calculate the perimeter of the island based on the cells' connections.
- **Boundary Conditions**: The function accounts for cells at the boundaries of the grid and cells surrounded by water.
- **Algorithm Efficiency**: The function is designed to efficiently handle grids of up to 100x100 dimensions.

## Function Prototype

```python
def island_perimeter(grid):
    """
    Calculates the perimeter of the island described in the grid.

    Args:
        grid (list of list of int): The grid representing the map where 0 is water and 1 is land.

    Returns:
        int: The perimeter of the island.
    """
```

## Example Usage

To use the function, follow these steps:

1. Create a Python file (e.g., `0-main.py`).
2. Import the `island_perimeter` function.
3. Define the grid and call the function to get the perimeter.

Example code:

```python
#!/usr/bin/python3
"""
0-main
"""
island_perimeter = __import__('0-island_perimeter').island_perimeter

if __name__ == "__main__":
    grid = [
        [0, 0, 0, 0, 0, 0],
        [0, 1, 0, 0, 0, 0],
        [0, 1, 0, 0, 0, 0],
        [0, 1, 1, 1, 0, 0],
        [0, 0, 0, 0, 0, 0]
    ]
    print(island_perimeter(grid))
```

Running the above code will output:

```
12
```

This indicates that the perimeter of the island described in the grid is 12 units.

## Implementation

The function iterates through each cell in the grid. For each land cell (`1`), it adds 4 to the perimeter (assuming all four sides are open). It then checks the adjacent cells (top and left). If an adjacent cell is also land (`1`), it subtracts 2 from the perimeter (since the side shared with the adjacent cell is not an external perimeter).

## Author

Vladimir Davidov
