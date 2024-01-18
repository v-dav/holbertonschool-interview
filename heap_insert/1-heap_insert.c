#include "binary_trees.h"

//function to insert the new node into the heap to the first available space
void node_insert(heap_t **root, heap_t *node_to_insert)
{
	if (*root == NULL)
		*root = node_to_insert;

	if ((*root)->left == NULL)
	{
		(*root)->left = node_to_insert;
		node_to_insert->parent = *root;
	}
	else if ((*root)->right == NULL)
	{
		(*root)->right = node_to_insert;
		node_to_insert->parent = *root;
	}
	else
		node_insert(&(*root)->left, node_to_insert);
}

/**
 * heap_insert - a function that inserts a value into a Max Binary Heap
 *
 * @root: a double pointer to the root node of the Heap
 * @value: is the value to store in the node to be inserted
 *
 * Return: a pointer to the inserted node, or NULL on failure
 */
heap_t *heap_insert(heap_t **root, int value)
{
	//Create a new pointer to the new node
	heap_t *new_node = NULL;

	//Create a new isolated node with the given value
	new_node = binary_tree_node(NULL, value);

	//If the root is pointing nowhere so
	if (*root == NULL)
	{
		*root = new_node;
		return (new_node);
	}
	
	//If the root exists, insert the new node to the first available space, beggining from left
	node_insert(&(*root), new_node);

	return (new_node);
}


