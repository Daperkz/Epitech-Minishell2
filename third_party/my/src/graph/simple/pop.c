/*
** EPITECH PROJECT, 2026
** pop.c
** File description:
** pop
*/

#include <stdlib.h>

#include "my/graph/simple_linked_list.h"

void *ll_pop_head(ll_t *list)
{
    node_t *head = NULL;
    void *data = NULL;

    if (!list || list->len == 0)
        return (NULL);
    head = list->head;
    list->head = list->head->next;
    data = head->data;
    free(head);
    list->len--;
    return (data);
}

static void enclose_nodes(node_t **head_ptr, node_t *curr, node_t *prev)
{
    if (!prev)
        (*head_ptr) = curr->next;
    else
        prev->next = curr->next;
}

void *ll_pop(ll_t *list, void *ref, int (*cmp)(void *, void *))
{
    node_t *curr = NULL;
    node_t *prev = NULL;
    void *data = NULL;

    if (!list || !list->head || !cmp)
        return (NULL);
    curr = list->head;
    for (int i = 0; i < list->len; i++) {
        if (cmp(curr->data, ref) == 0) {
            data = curr->data;
            enclose_nodes(&list->head, curr, prev);
            free(curr);
            list->len--;
            return (data);
        }
        prev = curr;
        curr = curr->next;
    }
    return (NULL);
}
