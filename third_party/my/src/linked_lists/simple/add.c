/*
** EPITECH PROJECT, 2026
** add.c
** File description:
** add
*/

#include "my/macro.h"

#include "my/linked_lists/simple_linked_list.h"

int ll_insert(ll_t *list, void *data)
{
    node_t *new_node = NULL;

    if (!list)
        return (EXIT_FAILURE);
    new_node = create_node(data);
    if (!new_node)
        return (EXIT_FAILURE);
    new_node->next = list->head;
    list->head = new_node;
    list->len++;
    return (EXIT_SUCCESS);
}

int ll_append(ll_t *list, void *data)
{
    node_t *new_node = NULL;
    node_t *tmp = NULL;

    if (!list)
        return (EXIT_FAILURE);
    new_node = create_node(data);
    if (!new_node)
        return (EXIT_FAILURE);
    if (list->len == 0) {
        list->head = new_node;
    } else {
        tmp = list->head;
        while (tmp->next)
            tmp = tmp->next;
        tmp->next = new_node;
    }
    list->len++;
    return (EXIT_SUCCESS);
}
