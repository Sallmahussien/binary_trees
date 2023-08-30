#include "binary_trees.h"

/**
 * binary_trees_ancestor - Finds the lowest common ancestor of two nodes
 * @first: Pointer to the first node
 * @second: Pointer to the second node
 * Return: Pointer to the lowest common ancestor node, or NULL if no common
 * ancestor was found
 */
binary_tree_t *binary_trees_ancestor(const binary_tree_t *first,
									 const binary_tree_t *second)
{
	size_t first_depth, second_depth, min_depth, max_depth;
	const binary_tree_t *min_node, *max_node;

	if (!first || !second)
		return (NULL);

	first_depth = binary_tree_depth(first);
	second_depth = binary_tree_depth(second);

	if (first_depth > second_depth)
	{
		min_depth = second_depth;
		max_depth = first_depth;
		min_node = second;
		max_node = first;
	}
	else
	{
		min_depth = first_depth;
		max_depth = second_depth;
		min_node = first;
		max_node = second;
	}

	while (max_depth > min_depth)
	{
		max_node = max_node->parent;
		max_depth--;
	}

	while (min_node && max_node && max_node != min_node)
	{
		max_node = max_node->parent;
		min_node = min_node->parent;
	}

	return (max_node == min_node ? (binary_tree_t *) max_node : NULL);
}

/**
 * binary_tree_depth - Measures the depth of a node in a binary tree
 * @tree: Pointer to the node to measure the depth
 * Return: Depth of the node, or 0 if tree is NULL
 */
size_t binary_tree_depth(const binary_tree_t *tree)
{
	size_t depth;

	if (!tree)
		return (0);

	depth = 0;

	while (tree->parent)
	{
		depth++;
		tree = tree->parent;
	}

	return (depth);
}
