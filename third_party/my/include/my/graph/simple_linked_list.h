/*
** EPITECH PROJECT, 2026
** simple_linked_list.h
** File description:
** simple_linked_list
*/

#ifndef SIMPLE_LINKED_LIST_H_
    #define SIMPLE_LINKED_LIST_H_

    #include "node.h"

typedef struct linked_list_s {
    node_t *head;
    int len;
} ll_t;

ll_t *ll_create(void);
void ll_destroy(ll_t *list, void (*free_data)(void *));

int ll_append(ll_t *list, void *data);
int ll_insert(ll_t *list, void *data);

void *ll_get(ll_t *list, void *ref, int (*cmp)(void *, void *));

void ll_dump(ll_t *list, void (*dump_data)(void *));

void *ll_pop_head(ll_t *list);
void *ll_pop(ll_t *list, void *ref, int (*cmp)(void *, void *));

#endif /* !SIMPLE_LINKED_LIST_H_ */
