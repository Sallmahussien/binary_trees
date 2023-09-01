#include "binary_trees.h"

/**
 * heap_insert - Inserts a value into a Max Binary Heap.
 * @root: A double pointer to the root node of the heap.
 * @value: The value to be inserted.
 *
 * Return: A pointer to the newly created node, or NULL on failure.
 */
heap_t *heap_insert(heap_t **root, int value)
{
	heap_t *new_node, *parent;
	int size, bit;

	new_node = binary_tree_node(NULL, value);
	if (new_node == NULL)
		return (NULL);

	if (*root == NULL)
	{
		*root = new_node;
		return (new_node);
	}

	size = binary_tree_size(*root) + 1;
	for (bit = size >> 1, parent = *root; bit > 1; bit >>= 1)
		parent = (size & bit) ? parent->right : parent->left;

	if (size & 1)
		parent->right = new_node;
	else
		parent->left = new_node;

	new_node->parent = parent;
	heapify(new_node);

	return (new_node);
}

/**
 * find_insertion_parent - Finds the parent node to insert a new node.
 * @root: A pointer to the root node.
 *
 * Return: A pointer to the parent node.
 */
heap_t *find_insertion_parent(heap_t *root)
{
	while (root->left != NULL && root->right != NULL)
	{
		if (binary_tree_size(root->left) > binary_tree_size(root->right))
			root = root->left;
		else
			root = root->right;
	}
	return (root);
}

/**
 * binary_tree_size - Measures the size of a binary tree
 * @tree: Pointer to the root node of the tree to measure
 * Return: Size of the binary tree, or 0 if tree is NULL
 */
size_t binary_tree_size(const binary_tree_t *tree)
{
	if (!tree)
		return (0);

	return (1 + binary_tree_size(tree->left) + binary_tree_size(tree->right));
}

/**
 * heapify - Move a node up the heap to maintain Max Heap property
 * @node: Pointer to the node to be moved
 */
void heapify(binary_tree_t *node)
{
	int temp;

	while (node->parent != NULL && node->n > node->parent->n)
	{
		temp = node->n;
		node->n = node->parent->n;
		node->parent->n = temp;
		node = node->parent;
	}
}
