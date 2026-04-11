/*
** EPITECH PROJECT, 2026
** create.c
** File description:
** create
*/

#include <stdlib.h>

#include "my/graph/binary_tree.h"

btree_t *btree_create(void)
{
    btree_t *btree = malloc(sizeof(btree_t));

    if (!btree)
        return (NULL);
    btree->root = NULL;
    btree->depth = 0;
    btree->size = 0;
    return (btree);
}
