/*
** EPITECH PROJECT, 2026
** dump.c
** File description:
** dump
*/

#include "my/macro.h"
#include "my/printf.h"
#include "my/hashtable.h"

static void bucket_dump_wrapper(void *ptr, void (*dump_data)(void *))
{
    ht_buckets_t *bucket = (ht_buckets_t *)ptr;

    if (!bucket)
        return;
    my_printf("> %s: ", bucket->key);
    if (dump_data && bucket->data)
        dump_data(bucket->data);
    else
        my_printf("%p", bucket->data);
    my_printf("\n");
}

void ht_dump(ht_t *ht, void (*dump_data)(void *))
{
    node_t *current = NULL;

    if (!ht)
        return;
    for (int i = 0; i < ht->size; i++) {
        my_printf("[%d]:\n", i);
        if (!ht->buckets[i])
            continue;
        current = ht->buckets[i]->head;
        while (current) {
            bucket_dump_wrapper(current->data, dump_data);
            current = current->next;
        }
    }
    return;
}
