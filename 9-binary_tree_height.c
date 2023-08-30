#include "binary_trees.h"

/**
 * binary_tree_height - measures the height of a binary tree
 * @tree: is a pointer to the root node of the tree to measure the height.
 * Return: tree height
*/
size_t binary_tree_height(const binary_tree_t *tree)
{
	size_t height = 0;
	binary_tree_t *left = tree->left;
	binary_tree_t *right = tree->right;

	while (left || right)
	{
		height++;
		if (left)
			left = left->left;
		if (right)
			right = right->right;
	}

	return (height);
}
