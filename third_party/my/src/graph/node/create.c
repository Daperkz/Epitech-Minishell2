/*
** EPITECH PROJECT, 2026
** create.c
** File description:
** create
*/

#include <stdlib.h>

#include "my/graph/node.h"

node_t *create_node(void *data)
{
    node_t *node = malloc(sizeof(node_t));

    if (!node)
        return (NULL);
    node->data = data;
    node->next = NULL;
    return (node);
}

dnode_t *create_dnode(void *data)
{
    dnode_t *node = malloc(sizeof(dnode_t));

    if (!node)
        return (NULL);
    node->data = data;
    node->next = NULL;
    node->prev = NULL;
    return (node);
}

bnode_t *create_bnode(void *data)
{
    bnode_t *node = malloc(sizeof(bnode_t));

    if (!node)
        return (NULL);
    node->data = data;
    node->left = NULL;
    node->right = NULL;
    return (node);
}
