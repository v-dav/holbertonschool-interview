#include "binary_trees.h"

/**
 * convert_to_bst - helper function to convert to bst
 *
 * @array: Pointer to the first element of the array to be converted
 * @beginning_index: the beginning index of the array
 * @end_index: the end index of the array
 *
 * Return: the address of the new node or NULL on failure
 */
avl_t *convert_to_bst(int *array, int beginning_index, int end_index)
{
	avl_t *new_node = NULL;

	if (end_index < beginning_index)
		return (NULL);

	new_node = malloc(sizeof(avl_t));
	if (new_node == NULL)
		return (NULL);

	int middle_index = (beginning_index + end_index) / 2;

	new_node->n = array[middle_index];
	new_node->left = convert_to_bst(array, beginning_index, middle_index - 1);
	new_node->right = convert_to_bst(array, middle_index + 1, end_index);
	return (new_node);
}

/**
 * sorted_array_to_avl - function that builds an AVL tree from an array
 *
 * @array: Pointer to the first element of the array to be converted
 * @size: the number of elements in the array
 * Description:
 * -Constraints:
 * --No rotation allowed
 * --Max 3 function per file
 *
 * Return: pointer to the root node of the created AVL tree, or NULL on failure
 */
avl_t *sorted_array_to_avl(int *array, size_t size)
{
	if (array == NULL || size == 0)
		return (NULL);

	return (convert_to_bst(array, 0, size - 1));
}
