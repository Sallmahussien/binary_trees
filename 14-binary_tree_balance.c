#include "binary_trees.h"

/**
 * binary_tree_balance - Measures the balance factor of a binary tree
 * @tree: Pointer to the root node of the tree to measure
 * Return: Balance factor of the binary tree, or 0 if tree is NULL
 */
int binary_tree_balance(const binary_tree_t *tree)
{
	if (!tree)
		return (0);

	return (compute_tree_height(tree->left) - compute_tree_height(tree->right));
}

/**
 * compute_tree_height - Measures the height of a binary tree
 * @tree: Pointer to the root node of the tree to measure
 * Return: Height of the binary tree, or 0 if tree is NULL
 */
int compute_tree_height(const binary_tree_t *tree)
{
	int left_height, right_height;

	if (!tree)
		return (-1);

	left_height = tree->left ? 1 + compute_tree_height(tree->left) : 0;
	right_height = tree->right ? 1 + compute_tree_height(tree->right) : 0;

	return (left_height > right_height ? left_height : right_height);
}
