/*
** EPITECH PROJECT, 2026
** dump.c
** File description:
** dump
*/

#include "my/macro.h"

#include "my/linked_lists/simple_linked_list.h"

void ll_dump(ll_t *list, void (*dump_data)(void *))
{
    node_t *current = NULL;

    if (!list)
        return;
    current = list->head;
    while (current) {
        if (dump_data)
            dump_data(current->data);
        current = current->next;
    }
}
