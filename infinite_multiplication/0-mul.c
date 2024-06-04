#include <string.h>
#include <stdlib.h>
#include <stdio.h>
#include <ctype.h>

/**
 * is_digit_string - checks if a string consists only of digits
 *
 * @str: string to check
 *
 * Return: 1 if the string is numeric, 0 otherwise
 */
int is_digit_string(char *str)
{
	int index, is_digit;

	for (index = 0; str[index] != 0; index++)
	{
		is_digit = isdigit(str[index]);
		if (is_digit == 0)
			return (0);
	}
	return (1);
}

/**
 * allocate_and_initialize - allocates memory and initializes it to
 * '0' characters
 *
 * @length: number of characters to allocate
 *
 * Return: pointer to the allocated memory
 */
char *allocate_and_initialize(unsigned int length)
{
	unsigned int i;
	char *memory;

	memory = malloc(length + 1);
	if (memory == NULL)
		return (NULL);

	for (i = 0; i < length; i++)
		memory[i] = '0';
	memory[i] = '\0';
	return (memory);
}

/**
 * main - multiplies two large numbers represented as strings
 *
 * @argc: number of command line arguments
 * @argv: array of command line arguments
 * Return: 0 on success, exits with status 98 on error
 */
int main(int argc, char **argv)
{
	int digit1_idx, digit2_idx, length1, length2, total_length, addition;
	int multiply, carry, digit_carry, temp_location, leading_zeros = 0;
	char *result;

	if (argc != 3 || is_digit_string(argv[1]) == 0 ||
	    is_digit_string(argv[2]) == 0)
		printf("Error\n"), exit(98);
	if (atoi(argv[1]) == 0 || atoi(argv[2]) == 0)
		printf("0\n"), exit(0);
	length1 = strlen(argv[1]), length2 = strlen(argv[2]);
	total_length = length1 + length2;
	result = allocate_and_initialize(total_length);
	if (result == NULL)
		printf("Error\n"), exit(98);
	for (digit2_idx = length2 - 1; digit2_idx >= 0; digit2_idx--)
	{
		carry = 0, digit_carry = 0;
		for (digit1_idx = length1 - 1; digit1_idx >= 0; digit1_idx--)
		{
			temp_location = digit2_idx + digit1_idx + 1;
			multiply = (argv[1][digit1_idx] - '0') *
				       (argv[2][digit2_idx] - '0') +
				   carry;
			carry = multiply / 10;
			addition = (result[temp_location] - '0') +
				       (multiply % 10) + digit_carry;
			digit_carry = addition / 10;
			result[temp_location] = (addition % 10) + '0';
		}
		result[temp_location - 1] = (carry + digit_carry) + '0';
	}

	if (result[0] == '0')
		leading_zeros = 1;

	for (; leading_zeros < total_length; leading_zeros++)
		printf("%c", result[leading_zeros]);
	printf("\n");
	free(result);
	return (0);
}
