# Prime Game

## Description

Prime Game is a Python implementation of a two-player mathematical game involving prime numbers. In this game, Maria and Ben take turns choosing prime numbers from a set of consecutive integers and removing that number and its multiples from the set. The player who cannot make a move loses the game.

## Features

- Simulates multiple rounds of the Prime Game
- Determines the winner of each round
- Calculates the overall winner across all rounds

## Requirements

- Python 3.x
- No external packages are required

## Installation

Clone the repository to your local machine:

```
git clone https://github.com/your-username/prime-game.git
cd prime-game
```

## Usage

The main function to use is `isWinner(x, nums)`, where:
- `x` is the number of rounds to play
- `nums` is a list of integers, each representing the maximum number for a round

Example usage:

```python
from prime_game import isWinner

result = isWinner(5, [2, 5, 1, 4, 3])
print(f"Winner: {result}")
```

## Function Prototype

```python
def isWinner(x, nums)
```

### Parameters

- `x` (int): The number of rounds to play
- `nums` (list of int): A list where each integer n denotes a set of consecutive integers from 1 to n (inclusive) for each round

### Returns

- `str`: The name of the player who won the most rounds ("Maria" or "Ben")
- `None`: If the winner cannot be determined

## Constraints

- 1 <= n <= 10000
- 1 <= x <= 10000

## Example

```python
x = 3
nums = [4, 5, 1]

# Round 1: n = 4
# Maria picks 2 and removes 2, 4, leaving 1, 3
# Ben picks 3 and removes 3, leaving 1
# Ben wins because there are no prime numbers left for Maria to choose

# Round 2: n = 5
# Maria picks 2 and removes 2, 4, leaving 1, 3, 5
# Ben picks 3 and removes 3, leaving 1, 5
# Maria picks 5 and removes 5, leaving 1
# Maria wins because there are no prime numbers left for Ben to choose

# Round 3: n = 1
# Ben wins because there are no prime numbers for Maria to choose

# Result: Ben has the most wins
```


## Author
Vladimir Davidov
