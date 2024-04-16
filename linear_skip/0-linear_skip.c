#include "search.h"

/**
 * linear_skip - searches for a value in a sorted skip list of integers
 *
 * @list: Pointer to the head node of the list
 * @value: the value to search for
 *
 * Return: a pointer to the node with the value
 */
skiplist_t *linear_skip(skiplist_t *list, int value)
{
	skiplist_t *search_pointer;

	if (!list)
		return (NULL);

	search_pointer = list->express;

	printf("Value checked at index [%lu] = [%d]\n",
	       search_pointer->index, search_pointer->n);

	while (search_pointer && search_pointer->n < value)
	{
		list = search_pointer;
		search_pointer = search_pointer->express;

		if (!search_pointer)
			break;

		printf("Value checked at index [%lu] = [%d]\n",
		       search_pointer->index, search_pointer->n);
	}

	if (!search_pointer)
	{
		search_pointer = list;
		while (search_pointer->next)
			search_pointer = search_pointer->next;
	}
	printf("Value found between indexes [%lu] and [%lu]\n",
	       list->index, search_pointer->index);

	while (list && list->n <= search_pointer->n)
	{
		printf("Value checked at index [%lu] = [%d]\n", list->index,
		       list->n);
		if (list->n == value)
			return (list);
		list = list->next;
	}
	return (NULL);
}
