/*
** EPITECH PROJECT, 2026
** create.c
** File description:
** create
*/

#include <stdlib.h>

#include "my/linked_lists/simple_linked_list.h"

ll_t *ll_create(void)
{
    ll_t *list = malloc(sizeof(ll_t));

    if (!list)
        return (NULL);
    list->head = NULL;
    list->len = 0;
    return (list);
}
