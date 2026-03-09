/*
** EPITECH PROJECT, 2026
** add.c
** File description:
** add
*/

#include "my/macro.h"

#include "my/linked_lists/double_linked_list.h"

int dll_insert(dll_t *list, void *data)
{
    dnode_t *new_node = NULL;

    if (!list)
        return (EXIT_FAILURE);
    new_node = create_dnode(data);
    if (!new_node)
        return (EXIT_FAILURE);
    if (list->len == 0) {
        list->head = new_node;
        list->tail = new_node;
    } else {
        new_node->next = list->head;
        list->head->prev = new_node;
        list->head = new_node;
    }
    list->len++;
    return (EXIT_SUCCESS);
}

int dll_append(dll_t *list, void *data)
{
    dnode_t *new_node = NULL;

    if (!list)
        return (EXIT_FAILURE);
    new_node = create_dnode(data);
    if (!new_node)
        return (EXIT_FAILURE);
    if (list->len == 0) {
        list->head = new_node;
        list->tail = new_node;
    } else {
        new_node->prev = list->tail;
        list->tail->next = new_node;
        list->tail = new_node;
    }
    list->len++;
    return (EXIT_SUCCESS);
}
