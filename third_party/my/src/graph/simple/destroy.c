/*
** EPITECH PROJECT, 2026
** destroy.c
** File description:
** destroy
*/

#include <stdlib.h>

#include "my/graph/simple_linked_list.h"

void ll_destroy(ll_t *list, void (*free_data)(void *))
{
    node_t *current = NULL;
    node_t *next = NULL;

    if (!list)
        return;
    current = list->head;
    while (current) {
        next = current->next;
        destroy_node(current, free_data);
        current = next;
    }
    free(list);
}
