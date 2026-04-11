/*
** EPITECH PROJECT, 2026
** add.c
** File description:
** add
*/

#include <stdlib.h>

#include "my/graph/binary_tree.h"

static int bnode_insert(
    bnode_t **node_ptr, void *data, int (*cmp)(void *, void *)
)
{
    if (*node_ptr == NULL) {
        *node_ptr = create_bnode(data);
        return (*node_ptr ? EXIT_SUCCESS : EXIT_FAILURE);
    }
    if (cmp(data, (*node_ptr)->data) < 0)
        return bnode_insert(&((*node_ptr)->left), data, cmp);
    return bnode_insert(&((*node_ptr)->right), data, cmp);
}

int btree_insert(btree_t *tree, void *data, int (*cmp)(void *, void *))
{
    if (!tree || !cmp)
        return (EXIT_FAILURE);
    if (bnode_insert(&(tree->root), data, cmp) == EXIT_SUCCESS) {
        tree->size++;
        return (EXIT_SUCCESS);
    }
    return (EXIT_FAILURE);
}
