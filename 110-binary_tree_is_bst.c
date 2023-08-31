#include "binary_trees.h"

/**
 * binary_tree_is_bst - Checks if a binary tree is a valid Binary Search Tree
 * @tree: Pointer to the root node of the tree to check
 * Return: 1 if the tree is a valid BST, and 0 otherwise
 */
int binary_tree_is_bst(const binary_tree_t *tree)
{
	if (!tree)
		return (0);

	return (bst_helper(tree, INT_MIN, INT_MAX));
}

/**
 * bst_helper - Checks if a binary tree is a valid Binary Search Tree
 * @node: Pointer to the root node of the tree to check
 * @min: minimum value
 * @max: maximum value
 * Return: 1 if the tree is a valid BST, and 0 otherwise
 */
int bst_helper(const binary_tree_t *node, int min, int max)
{
	if (!node)
		return (1);

	if (node->n < min || node->n > max)
		return (0);

	return (bst_helper(node->left, min, node->n - 1) &&
			bst_helper(node->right, node->n + 1, max));
}
