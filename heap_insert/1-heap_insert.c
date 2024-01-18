#include "binary_trees.h"

//==========================================================================

/**
 * node_insert - a function that inserts a node to the binary tree
 * to satisfy complete binary tree condition
 *
 * @root: a double pointer to the root node of the tree
 * @node_to_insert: is the node to insert 
 *
 * Return: void
 */
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

//==========================================================================

void heapify_up(heap_t *node, heap_t **root)
{
    while (node->parent && node->n > node->parent->n)
    {
	//if node attached to left branch of its parent on first iteration
	if (node->parent->left == node)
	{
		//on the first iteration
		if (node->left == NULL)
		{
			node->parent->left = node->left;
			node->left = node->parent;
			node->parent = node->left->parent;
			node->left->parent = node;
		}
		// on the next iterations
		else
		{

		}
	}
	//if the node attached to right branch on first iteration
	else
	{

	}
    }

    //the node becomes root
    if (!node->parent)
        *root = node;
}

//==========================================================================


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

	//Place the node in the right position to satisfy max_heap condition
	heapify_up(new_node, root);

	return (new_node);
}
