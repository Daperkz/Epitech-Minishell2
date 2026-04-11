/*
** EPITECH PROJECT, 2026
** pop.c
** File description:
** pop
*/

#include <stdlib.h>

#include "my/graph/double_linked_list.h"

void *dll_pop_head(dll_t *list)
{
    dnode_t *head = NULL;
    void *data = NULL;

    if (!list || list->len == 0)
        return (NULL);
    head = list->head;
    list->head = head->next;
    if (list->head)
        list->head->prev = NULL;
    else
        list->tail = NULL;
    data = head->data;
    free(head);
    list->len--;
    return (data);
}

void *dll_pop_tail(dll_t *list)
{
    dnode_t *tail = NULL;
    void *data = NULL;

    if (!list || list->len == 0)
        return (NULL);
    tail = list->tail;
    list->tail = list->tail->prev;
    if (list->tail)
        list->tail->next = NULL;
    else
        list->head = NULL;
    data = tail->data;
    free(tail);
    list->len--;
    return (data);
}

static void enclose_dnodes(dll_t *list, dnode_t *curr)
{
    if (curr->prev)
        curr->prev->next = curr->next;
    else
        list->head = curr->next;
    if (curr->next)
        curr->next->prev = curr->prev;
    else
        list->tail = curr->prev;
}

void *dll_pop(dll_t *list, void *ref, int (*cmp)(void *, void *))
{
    dnode_t *curr = NULL;
    void *data = NULL;

    if (!list || !list->head || !cmp)
        return (NULL);
    curr = list->head;
    for (int i = 0; i < list->len; i++) {
        if (cmp(curr->data, ref) == 0) {
            data = curr->data;
            enclose_dnodes(list, curr);
            free(curr);
            list->len--;
            return (data);
        }
        curr = curr->next;
    }
    return (NULL);
}
