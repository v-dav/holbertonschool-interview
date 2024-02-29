#include "palindrome.h"

/**
 * is_palindrome - checks whether or not a given
 * unsigned integer is a palindrome.
 *
 * @n: the number to be checked
 *
 * Return: 1 if n is a palindrome, and 0 otherwise
 */
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
