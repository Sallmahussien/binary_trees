#include "binary_trees.h"

/**
 * bst_remove - Removes a node from a Binary Search Tree.
 * @root: Pointer to the root node of the tree where you will remove a node.
 * @value: Value to remove in the tree.
 * Return: Pointer to the new root node of the tree after removing the desired
 */
bst_t *bst_remove(bst_t *root, int value)
{
	bst_t *min_node, *temp;

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
		}
		else if (!root->left)
		{
			temp = root->right;
			if (temp)
				temp->parent = root->parent;
			free(root);
			return (temp);
		}
		else if (!root->right)
		{
			temp = root->left;
			if (temp)
				temp->parent = root->parent;
			free(root);
			return (temp);
		}
		else
		{
			min_node = get_min_node(root->right);
			root->n = min_node->n;
			root->right = bst_remove(root->right, root->n);
		}
	}

	return (root);
}

/**
 * copy_child_and_delete - Copies the child node and deletes the parent node.
 * @parent: Pointer to the parent node.
 * @child: Pointer to the child node.
 */
void copy_child_and_delete(bst_t *parent, bst_t *child)
{
	parent->n = child->n;
	parent->left = child->left;
	parent->right = child->right;
	free(child);
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
