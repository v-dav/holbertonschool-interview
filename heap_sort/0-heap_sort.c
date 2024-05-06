#include "sort.h"

/**
 * swap - function that swaps two integers
 *
 * @a: first int
 * @b: second int
 *
 * Return: void
 */
void swap(int *a, int *b)
{
	int tmp = *a;
	*a = *b;
	*b = tmp;
}

/**
 * heapify - heapify a subtree
 *
 * @array: array to heapify
 * @idx: index of the root node
 * @size: size of the array/heap
 * @calcsize: size of the array/heap
 *
 * Return: void
 */
void heapify(int *array, size_t size, size_t calcsize, int idx)
{
	/* Initialize largest as root*/
	int root = idx;
	int left = 2 * idx + 1;
	int right = 2 * idx + 2;
	int n = (int)size;

	/*If left child is larger than root*/
	if (left < n && array[left] > array[root])
		root = left;

	/*If right child is larger than largest so far*/
	if (right < n && array[right] > array[root])
		root = right;

	/* If largest is not root*/
	if (root != idx)
	{
		swap(&array[idx], &array[root]);
		print_array(array, calcsize);
		heapify(array, n, calcsize, root);
	}
}

/**
 * heap_sort - function that sorts an array of integers
 * in ascending order using the Heap sort algorithm
 *
 * @array: the array to sort
 * @size: number of elements in @array
 *
 * Return: void
 */
void heap_sort(int *array, size_t size)
{
	int i;

	/*Building max-heap*/
	for (i = size / 2 - 1; i >= 0; i--)
		heapify(array, size, size, i);

	/*Sorting*/
	for (i = size - 1; i > 0; i--)
	{
		swap(&array[0], &array[i]);
		print_array(array, size);
		heapify(array, i, size, 0);
	}
}
