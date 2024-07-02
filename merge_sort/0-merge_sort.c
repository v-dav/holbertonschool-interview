#include "sort.h"


/**
 * mergesort_topdown_merge - Merges two partition during a mergesort.
 * @array: Array to sort
 * @result_array: Temporary array to store resultsarray
 * @start: Start of split
 * @middle: middle of split
 * @end: End of split
 */
void	mergesort_topdown_merge(int *array, int *result_array, size_t start,
								size_t middle, size_t end)
{
	size_t	i, j, k;

	i = start;
	j = middle;
	k = start;
	printf("Merging...\n");
	printf("[left]: ");
	print_array(array + start, middle - start);
	printf("[right]: ");
	print_array(array + middle, end - middle);
	while (i != middle && j != end)
	{
		if (array[i] < array[j])
			result_array[k++] = array[i++];
		else
			result_array[k++] = array[j++];
	}
	while (i < middle)
		result_array[k++] = array[i++];
	while (j < end)
		result_array[k++] = array[j++];
	for (i = start; i < end; i++)
		array[i] = result_array[i];
	printf("[Done]: ");
	print_array(array + start, end - start);
}

/**
 * mergesort_topdown_split - Performs merge sort on an array partition
 * @array: Array to sort
 * @result_array: Temporary array to store results
 * @start: Start of split
 * @end: End of split
 */
void	mergesort_topdown_split(int *array, int *result_array, size_t start,
								size_t end)
{
	size_t	middle;

	if (start >= end - 1)
		return;
	middle = (start + end) / 2;
	mergesort_topdown_split(array, result_array, start, middle);
	mergesort_topdown_split(array, result_array, middle, end);
	mergesort_topdown_merge(array, result_array, start, middle, end);
}

/**
 * merge_sort - Sorts an array using the Merge Sort method
 * @array: Array of integers
 * @size: Size of @array
 */
void	merge_sort(int *array, size_t size)
{
	int		*result_array;
	size_t	i;

	if (size < 2)
		return;
	result_array = malloc(sizeof(*result_array) * size);
	for (i = 0; i < size; i++)
		result_array[i] = 0;
	mergesort_topdown_split(array, result_array, 0, size);
	free(result_array);
}
