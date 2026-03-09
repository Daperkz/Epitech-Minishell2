/*
** EPITECH PROJECT, 2026
** get.c
** File description:
** get
*/

#include "my/macro.h"

#include "my/linked_lists/double_linked_list.h"

void *dll_get(dll_t *list, void *ref, int (*cmp)(void *, void *))
{
    dnode_t *tmp = NULL;

    if (!list || !cmp)
        return (NULL);
    tmp = list->head;
    for (int i = 0; i < list->len; i++) {
        if (cmp(tmp->data, ref) == 0)
            return (tmp->data);
        tmp = tmp->next;
    }
    return (NULL);
}
