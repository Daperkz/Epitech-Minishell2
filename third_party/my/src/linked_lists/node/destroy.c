/*
** EPITECH PROJECT, 2026
** destroy.c
** File description:
** destroy
*/

#include <stdlib.h>

#include "my/linked_lists/node.h"

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
