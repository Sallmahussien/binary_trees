#include "binary_trees.h"


heap_t *array_to_heap(int *array, size_t size)
{
	heap_t *root;
	size_t i;

	if (!array)
		return (NULL);

	root = NULL;
	for (i = 0; i < size; i++)
		heap_insert(&root, array[i]);

	return (root);
}