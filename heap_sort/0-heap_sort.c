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
 * @arr: array to heapify
 * @i: index of the root node
 * @N: size of the array/heap
 *
 * Return: void
 */
void heapify(int arr[], int N, int i)
{
	/* Initialize largest as root*/
	int largest = i;
	int l = 2 * i + 1;
	int r = 2 * i + 2;

	/*If left child is larger than root*/
	if (l < N && arr[l] > arr[largest])
		largest = l;

	/*If right child is larger than largest so far*/
	if (r < N && arr[r] > arr[largest])
		largest = r;

	/* If largest is not root*/
	if (largest != i)
	{
		swap(&arr[i], &arr[largest]);

		/*Recursively heapify the affected sub-tree*/
		heapify(arr, N, largest);
	}
}

/**
 * buildHeap - Function to build a Max-Heap from the given array
 *
 * @arr: array to make max-heap from
 * @N: size of the array/heap
 *
 * Return: void
 */
void buildHeap(int arr[], int N)
{
	/*Index of last non-leaf node*/
	int startIdx = (N / 2) - 1;

	/*Perform reverse level order traversal*/
	/*from last non-leaf node and heapify*/
	/*each node*/
	for (int i = startIdx; i >= 0; i--)
	{
		heapify(arr, N, i);
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

	if (size < 2)
		return;

	buildHeap(array, size);
	for (i = size - 1; i >= 0; i--)
	{
		swap(&array[0], &array[i]);
		heapify(array, i, 0);
	}
}
