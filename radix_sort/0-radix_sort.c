#include "sort.h"

/**
 * getMax - A utility function to get the maximum value in an array
 * @array: The array to be examined
 * @size: Number of elements in the array
 *
 * Return: The maximum value in the array
 */
int getMax(int *array, size_t size)
{
	int max = array[0];
	size_t i;

	for (i = 1; i < size; i++)
		if (array[i] > max)
			max = array[i];
	return (max);
}

/**
 * countSort - A function to do counting sort of array according to
 * the digit represented by exp
 * @array: The array to be sorted
 * @size: Number of elements in the array
 * @exp: Exponent representing the current digit position
 */
void countSort(int *array, size_t size, int exp)
{
	int *output = malloc(size * sizeof(int));
	int count[10] = {0};
	size_t i;
	int j;

	for (i = 0; i < size; i++)
		count[(array[i] / exp) % 10]++;

	for (j = 1; j < 10; j++)
		count[j] += count[j - 1];

	/* Build the output array */
	for (i = size; i > 0; i--)
	{
		output[count[(array[i - 1] / exp) % 10] - 1] = array[i - 1];
		count[(array[i - 1] / exp) % 10]--;
	}

	for (i = 0; i < size; i++)
		array[i] = output[i];

	free(output);
}

/**
 * radix_sort - Sorts an array of integers in ascending order using the
 * Radix sort algorithm
 * @array: The array to be sorted
 * @size: Number of elements in the array
 */
void radix_sort(int *array, size_t size)
{
	int max = getMax(array, size);
	int exp;

	for (exp = 1; max / exp > 0; exp *= 10)
	{
		countSort(array, size, exp);
		print_array(array, size);
	}
}
