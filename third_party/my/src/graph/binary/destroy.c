/*
** EPITECH PROJECT, 2026
** destroy.c
** File description:
** destroy
*/

#include <stdlib.h>

#include "my/graph/binary_tree.h"

void btree_destroy(btree_t *tree, void (*free_data)(void *))
{
    if (!tree)
        return;
    destroy_bnode_recursive(tree->root, free_data);
    free(tree);
}
