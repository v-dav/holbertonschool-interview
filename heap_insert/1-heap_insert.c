#include "binary_trees.h"

/*==========================================================================*/

/**
 * insert_at_first_open_position - inserts a new node at the first available
 * position in a binary heap.
 *
 * @current: A pointer to the current node in the heap where the new
 * node will be inserted.
 * @new_node: A pointer to the new node that needs to be inserted into
 * the heap.
 * @level: The level parameter represents the level at which a node can
 * be inserted in the heap.
 * It is used to determine the position of the new node in the heap.
 * @done: The "done" parameter is a pointer to an integer variable that is
 * used to indicate
 * whether the insertion operation has been completed or not.
 * It is initially set to 0 and will be set
 * to 1 once the new node has been inserted into the heap.
 * This allows the function to stop the
 * recursive
 *
 * Return: nothing (void).
 */
static void insert_at_first_open_position(heap_t *current, heap_t *new_node,
					  int level, int *done)
{
	if (current == NULL || *done)
		return;

	/* Si nous sommes au niveau où un nœud peut être inséré. */
	if (level == 1)
	{
		/* Vérifier si l'enfant gauche est disponible. */
		if (!current->left)
		{
			current->left = new_node;
			new_node->parent = current;
			*done = 1;
		}
		/* Sinon, vérifier si l'enfant droit est disponible. */
		else if (!current->right)
		{
			current->right = new_node;
			new_node->parent = current;
			*done = 1;
		}
		else
			/* Les deux enfants existent déjà */
			/* La fonction retourne pour chercher une position dans un autre nœud.*/
			return;
	}

	else if (level > 1)
	{
		/* On descend dans les branches de l'arbre */
		insert_at_first_open_position(current->left, new_node, level - 1, done);
		insert_at_first_open_position(current->right, new_node, level - 1, done);
	}
}

/**
 * tree_height - calculates the height of a binary tree.
 *
 * @root: The root parameter is a pointer to the root node of a binary tree.
 *
 * Return: the height of the tree.
 */
static int tree_height(heap_t *root)
{
	if (root == NULL)
	{
		return (0);
	}

	int left_height = tree_height(root->left);
	int right_height = tree_height(root->right);

	if (left_height > right_height)
	{
		return (left_height + 1);
	}
	else
	{
		return (right_height + 1);
	}
}

/*==========================================================================*/

/**
 * swap - Swap the values of two integers.
 *
 * @a: Pointer to the first integer.
 * @b: Pointer to the second integer.
 */
void swap(int *a, int *b)
{
	int temp = *a;
	*a = *b;
	*b = temp;
}

/*==========================================================================*/

/**
 * heapify_up - Move the newly inserted node up to maintain max heap property.
 *
 * @node: A pointer to the newly inserted node.
 *
 * Return: adress of new node
 */
heap_t *heapify_up(heap_t *node)
{
	while (node->parent && node->n > node->parent->n)
	{
		swap(&(node->n), &(node->parent->n));
		node = node->parent;
	}
	return (node);
}

/*==========================================================================*/

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
	/*Create a new pointer to the new node*/
	heap_t *new_node = NULL;

	/*Create a new isolated node with the given value*/
	new_node = binary_tree_node(NULL, value);

	/*If the root is pointing nowhere so*/
	if (*root == NULL)
	{
		*root = new_node;
		return (new_node);
	}

	/* Sinon, trouver la position pour le nouvel élément*/
	else
	{
		int done = 0;
		/* On calcul la hauteur de l'arbre */
		int height = tree_height(*root);

		for (int level = 1; level <= height; ++level)
		{
			insert_at_first_open_position(*root, new_node, level, &done);
			if (done)
				break;
		}
		if (!done)
			insert_at_first_open_position(*root, new_node, height + 1, &done);
	}

	/*Place the node in the right position to satisfy max_heap condition*/
	new_node = heapify_up(new_node);

	return (new_node);
}
