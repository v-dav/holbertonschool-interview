# Palindrome Integer

![C](https://img.shields.io/badge/C-00599C?style=for-the-badge&logo=c&logoColor=white)

<p align="center">
  <img src="https://github.com/v-dav/holbertonschool-interview/assets/115344057/ee26bd4b-fe04-4c2a-bf2f-9496c50a6811" alt="cycle">
</p>

## 🧐 Project Description

In this project, we will implement a function in C to check whether or not a given unsigned integer is a palindrome.

## 🧑🏼‍💻 Function Signature

```c
int is_palindrome(unsigned long n);
```

## Input
n is the unsigned integer to be checked

## Output
Returns 1 if n is a palindrome and 0 otherwise.

## ⚙️ Requirements

We are not allowed to allocate memory dynamically (malloc, calloc, …) for this exercice.

## 🧑🏼‍💻 Leetcode solution with another approach
![Skärmavbild 2024-02-29 kl  15 33 52](https://github.com/v-dav/holbertonschool-interview/assets/115344057/248b5e0b-7ddf-4ac0-837c-43e7792681a2)
```c
int is_palindrome(unsigned long n)
{
	int divisor = 1;
	int leading = 0;
	int trailing = 0;

	/* Find divisor to extract leading digit */
	while (n / divisor >= 10)
		divisor *= 10;

	while (n != 0)
	{
		/* find first and last digit */
		leading = n / divisor;
		trailing = n % 10;

		/* check if palindrome */
		if (leading != trailing)
			return (0);

		/* remove first and last number */
		n = (n % divisor) / 10;

		/* reduce divisor by 2 as 2 digits are removed */
		divisor /= 100;
	}
	return (1);
}
```


##  🙇 Author

[Vladimir Davidov](https://github.com/v-dav) - Holberton School
