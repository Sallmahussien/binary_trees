#include "binary_trees.h"

/**
 * binary_tree_levelorder - Traverses a binary tree using level-order traversal
 * @tree: Pointer to the root node of the tree to traverse
 * @func: Pointer to a function to call for each node.
 */
void binary_tree_levelorder(const binary_tree_t *tree, void (*func)(int))
{
	size_t level, height;

	if (!tree || !func)
		return;

	height = compute_tree_height(tree);

	for (level = 1; level <= height + 1; level++)
		print_current_level(tree, level, func);
}

/**
 * print_current_level - Prints the current level of a binary tree
 * @tree: Pointer to the root node of the tree to traverse
 * @level: Level of the tree to traverse
 * @func: Pointer to a function to call for each node.
 */
void print_current_level(const binary_tree_t *tree,
						 size_t level, void (*func)(int))
{
	if (!tree)
		return;

	if (level == 1)
		func(tree->n);
	else if (level > 1)
	{
		print_current_level(tree->left, level - 1, func);
		print_current_level(tree->right, level - 1, func);
	}
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
