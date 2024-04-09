#include "binary_trees.h"

/**
 * convert_to_avl - helper function to convert to avl
 *
 * @array: Pointer to the first element of the array to be converted
 * @begin_idx: the beginning index of the array
 * @end_idx: the end index of the array
 * @parent: pointer to the node's parent
 *
 * Return: the address of the new node or NULL on failure
 */
avl_t *convert_to_avl(int *array, int begin_idx, int end_idx, avl_t *parent)
{
	avl_t *new_node = NULL;
	int middle_index = 0;

	if (end_idx < begin_idx)
		return (NULL);

	new_node = malloc(sizeof(avl_t));
	if (new_node == NULL)
		return (NULL);

	middle_index = (begin_idx + end_idx) / 2;

	new_node->n = array[middle_index];
	new_node->parent = parent;
	new_node->left = convert_to_avl(array, begin_idx, middle_index - 1, new_node);
	new_node->right = convert_to_avl(array, middle_index + 1, end_idx, new_node);

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

	return (convert_to_avl(array, 0, size - 1, NULL));
}
