/*
** EPITECH PROJECT, 2026
** destroy.c
** File description:
** destroy
*/

#include <stdlib.h>

#include "my/graph/node.h"

void destroy_node(node_t *node, void (*free_data)(void *))
{
    if (!node)
        return;
    if (free_data && node->data)
        free_data(node->data);
    free(node);
}

void destroy_dnode(dnode_t *node, void (*free_data)(void *))
{
    if (!node)
        return;
    if (free_data && node->data)
        free_data(node->data);
    free(node);
}

void destroy_bnode(bnode_t *node, void (*free_data)(void *))
{
    if (!node)
        return;
    if (free_data && node->data)
        free_data(node->data);
    free(node);
}

void destroy_bnode_recursive(bnode_t *node, void (*free_data)(void *))
{
    if (!node)
        return;
    destroy_bnode_recursive(node->left, free_data);
    destroy_bnode_recursive(node->right, free_data);
    destroy_bnode(node, free_data);
}
