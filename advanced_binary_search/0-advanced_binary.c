#include "search_algos.h"

/**
 * print - helper function to print the array
 * @array: is a pointer to the first element of the array to print
 * @start: first element of the array
 * @end: last element of the array
 *
 * Return: void
 **/
void print(int *array, size_t start, size_t end)
{
	printf("Searching in array: ");
	while (start < end)
	{
		printf("%d, ", array[start]);
		start++;
	}
	printf("%i\n", array[start]);
}

/**
 * recursive_part - helper function to search
 * @array: is a pointer to the first element of the array to search in
 * @start: index of first element of the array
 * @end: index of last element of the array
 * @value: is the value to search for
 *
 * Return: the index where value is located, otherwise return -1
 **/
int recursive_part(int *array, int start, int end, int value)
{
	int middle;

	print(array, start, end);

	middle = (end - start) / 2 + start;

	if (start == end)
		return (-1);

	if (array[middle] == value && array[middle - 1] != value)
		return (middle);

	if (array[middle] > value)
		return (recursive_part(array, start, middle, value));

	if (array[middle] < value)
		return (recursive_part(array, middle + 1, end, value));

	return (-1);
}

/**
 * advanced_binary - a function that searches for a value
 * in a sorted array of integers.
 *
 * @array: the sorted array of integers to search in
 * @size: the number of elements in the array
 * @value: the value to search for
 *
 * Return: the index where value is located, or -1 if not found
 */
int advanced_binary(int *array, size_t size, int value)
{
	if (!array)
		return (-1);

	return (recursive_part(array, 0, size - 1, value));
}
