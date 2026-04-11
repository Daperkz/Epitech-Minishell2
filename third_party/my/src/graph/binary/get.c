/*
** EPITECH PROJECT, 2026
** get.c
** File description:
** get
*/

#include "my/macro.h"

#include "my/graph/binary_tree.h"

static void *bnode_get(bnode_t *node, void *ref, int (*cmp)(void *, void *))
{
    int retv;

    if (!node)
        return (NULL);
    retv = cmp(ref, node->data);
    if (retv == 0)
        return (node->data);
    if (retv < 0)
        return bnode_get(node->left, ref, cmp);
    return bnode_get(node->right, ref, cmp);
}

void *btree_get(btree_t *tree, void *ref, int (*cmp)(void *, void *))
{
    if (!tree || !cmp)
        return (NULL);
    return bnode_get(tree->root, ref, cmp);
}
