#include "binary_trees.h"

static bst_t *bst_remove_with_one_child(bst_t *root, bst_t *temp);

/**
 * bst_remove - Removes a node from a Binary Search Tree.
 * @root: Pointer to the root node of the tree where you will remove a node.
 * @value: Value to remove in the tree.
 * Return: Pointer to the new root node of the tree after removing the desired
 */
bst_t *bst_remove(bst_t *root, int value)
{
	bst_t *min_node;

	if (!root)
		return (NULL);

	if (value < root->n)
		root->left = bst_remove(root->left, value);
	else if (value > root->n)
		root->right = bst_remove(root->right, value);
	else if (value == root->n)
	{
		if (!root->left && !root->right)
		{
			free(root);
			root = NULL;
			return (root);
		}
		else if (!root->left)
			return (bst_remove_with_one_child(root, root->right));
		else if (!root->right)
			return (bst_remove_with_one_child(root, root->left));

		min_node = get_min_node(root->right);
		root->n = min_node->n;
		root->right = bst_remove(root->right, root->n);
	}

	return (root);
}

/**
 * bst_remove_with_one_child - Helper function to remove a node with one child.
 * @root: The node to remove.
 * @temp: The child node.
 * Return: new node
 */
static bst_t *bst_remove_with_one_child(bst_t *root, bst_t *temp)
{
	if (temp)
		temp->parent = root->parent;
	free(root);
	return (temp);
}

/**
 * get_min_node - Gets the minimum node in a tree.
 * @root: Pointer to the root node of the tree.
 * Return: Pointer to the minimum node in the tree.
 */
bst_t *get_min_node(bst_t *root)
{
	bst_t *curr = root;

	while (curr && curr->left)
		curr = curr->left;

	return (curr);
}
