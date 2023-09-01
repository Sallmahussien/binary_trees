#include "binary_trees.h"

/**
 * binary_tree_is_heap - Check if a binary tree is a valid Max Binary Heap
 * @tree: A pointer to the root node of the tree
 *
 * Return: 1 if the tree is a valid Max Binary Heap, 0 otherwise
 */
int binary_tree_is_heap(const binary_tree_t *tree)
{
	if (!tree || !binary_tree_is_complete(tree))
		return (0);

	return (is_max_heap(tree));
}

/**
 * is_max_heap - Check if a binary tree is a valid Max Binary Heap
 * @tree: A pointer to the root node of the tree
 *
 * Return: 1 if the tree is a valid Max Binary Heap, 0 otherwise
 */
int is_max_heap(const binary_tree_t *tree)
{
	if (!tree)
		return (1);

	if ((tree->left && tree->n < tree->left->n) ||
	    (tree->right && tree->n < tree->right->n))
		return (0);

	return (is_max_heap(tree->left) && is_max_heap(tree->right));
}


/**
 * binary_tree_is_complete - Checks if a binary tree is complete.
 * @tree: Pointer to the root node of the tree to check.
 * Return: 1 if the tree is complete, 0 otherwise.
 */
int binary_tree_is_complete(const binary_tree_t *tree)
{
	size_t tree_size, index;

	if (!tree)
		return (0);

	tree_size = binary_tree_size(tree);
	index = 0;

	return (is_complete(tree, index, tree_size));
}

/**
 * is_complete - Helper function to check completeness recursively.
 * @tree: Pointer to the current node.
 * @index: Index of the current node.
 * @tree_size: Size of the tree.
 * Return: 1 if the tree is complete, 0 otherwise.
 */
int is_complete(const binary_tree_t *tree, size_t index, size_t tree_size)
{
	if (!tree)
		return (1);

	if (index >= tree_size)
		return (0);

	return (is_complete(tree->left, 2 * index + 1, tree_size) &&
			is_complete(tree->right, 2 * index + 2, tree_size));
}

/**
 * binary_tree_size - Measures the size of a binary tree
 * @tree: Pointer to the root node of the tree to measure
 * Return: Size of the binary tree, or 0 if tree is NULL
 */
size_t binary_tree_size(const binary_tree_t *tree)
{
	size_t left_size, right_size;

	if (!tree)
		return (0);

	left_size = binary_tree_size(tree->left);
	right_size = binary_tree_size(tree->right);

	return (left_size + right_size + 1);
}
