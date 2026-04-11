/*
** EPITECH PROJECT, 2026
** destroy.c
** File description:
** destroy
*/

#include <stdlib.h>

#include "my/graph/double_linked_list.h"

void dll_destroy(dll_t *list, void (*free_data)(void *))
{
    dnode_t *current = NULL;
    dnode_t *next = NULL;

    if (!list)
        return;
    current = list->head;
    for (int i = 0; i < list->len; i++) {
        next = current->next;
        destroy_dnode(current, free_data);
        current = next;
    }
    free(list);
}
