#include "binary_trees.h"

/**
 * heap_insert - Inserts a value into a Max Binary Heap.
 * @root: Double pointer to the root node of the Heap.
 * @value: Value to store in the node to be inserted.
 * Return: Pointer to the created node, or NULL on failure.
 */
heap_t *heap_insert(heap_t **root, int value)
{
	heap_t *new_node = binary_tree_node(NULL, value);
	heap_t *parent;

	if (!new_node)
		return (NULL);

	if (!*root)
	{
		*root = new_node;
		return (new_node);
	}

	parent = find_insertion_point(*root);

	if (!parent->left)
		parent->left = new_node;
	else
		parent->right = new_node;

	new_node->parent = parent;

	heapify_up(new_node);

	return (new_node);
}

/**
 * find_insertion_point - Finds the parent node
 * for insertion using level-order traversal.
 * @root: Pointer to the root node.
 * Return: Pointer to the parent node.
 */
heap_t *find_insertion_point(heap_t *root)
{
	int front = 0, rear = 0;
	heap_t **queue = malloc(sizeof(heap_t *) * 1024);

	if (!queue)
		exit(EXIT_FAILURE);

	queue[rear++] = root;

	while (front < rear)
	{
		heap_t *current = queue[front++];

		if (!current->left || !current->right)
		{
			free(queue);
			return (current);
		}

		if (current->left)
			queue[rear++] = current->left;
		if (current->right)
			queue[rear++] = current->right;
	}

	free(queue);

	return (NULL);
}

/**
 * heapify_up - Restores the Max Heap property after insertion.
 * @node: Pointer to the newly inserted node.
 */
void heapify_up(heap_t *node)
{
	int temp;

	while (node->parent && node->n > node->parent->n)
	{
		temp = node->n;
		node->n = node->parent->n;
		node->parent->n = temp;

		node = node->parent;
	}
}
