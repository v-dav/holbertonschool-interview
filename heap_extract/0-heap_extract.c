#include "binary_trees.h"

/**
 * binary_tree_preorder - pre-order traversal that goes through a binary tree
 * @tree: pointer to root
 * @node: pointer to node in the tree
 * @h: height of the tree
 * @level: layer in the tree
 *
 * Return: Nothing
 **/
void binary_tree_preorder(heap_t *tree, heap_t **node, size_t h, size_t level)
{
	if (tree == NULL)
		return;
	if (h == level)
		*node = tree;
	level++;
	if (tree->left)
		binary_tree_preorder(tree->left, node, h, level);
	if (tree->right)
		binary_tree_preorder(tree->right, node, h, level);
}

/**
* binary_tree_height - measures the height of a binary tree
* @tree: node to check
* Return: height
*/
size_t binary_tree_height(const heap_t *tree)
{
	size_t lheight = 0;
	size_t rheight = 0;

	if (tree == NULL || (tree->left == NULL && tree->right == NULL))
		return (0);
	if (tree->left)
		lheight = binary_tree_height(tree->left);
	if (tree->right)
		rheight = binary_tree_height(tree->right);

	if (lheight >= rheight)
		return (1 + lheight);
	return (1 + rheight);
}

/**
* heap_extract - Function that extracts the root node of a Max Binary Heap
* @root: double pointer to the root node of the heap
* Return: return the value stored in the root node
*/
int heap_extract(heap_t **root)
{
	int deleted, n;
	size_t level = 0;
	heap_t *aux, *del;

	if (root == NULL || *root == NULL)
		return (0);
	aux = *root, deleted = aux->n;
	if (aux->left == NULL && aux->right == NULL)
	{
		*root = NULL;
		free(aux);
		return (deleted);
	}
	binary_tree_preorder(aux, &del, binary_tree_height(aux), level);
	while (aux->left || aux->right)
	{
		if (aux->right == NULL || aux->left->n > aux->right->n)
		{
			n = aux->n, aux->n = aux->left->n;
			aux->left->n = n;
			aux = aux->left;
		}
		else if (aux->left == NULL || aux->right->n > aux->left->n)
		{
			n = aux->n, aux->n = aux->right->n;
			aux->right->n = n;
			aux = aux->right;
		}
	}
	aux->n = del->n;
	if (del->parent->right)
		del->parent->right = NULL;
	else
		del->parent->left = NULL;
	free(del);
	return (deleted);
}
