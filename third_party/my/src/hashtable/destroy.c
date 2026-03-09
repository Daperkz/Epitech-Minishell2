/*
** EPITECH PROJECT, 2026
** destroy.c
** File description:
** destroy
*/

#include <stdlib.h>

#include "my/hashtable.h"

static void bucket_free_wrapper(void *ptr, void (*free_data)(void *))
{
    ht_buckets_t *bucket = (ht_buckets_t *)ptr;

    if (!bucket)
        return;
    if (bucket->key)
        free(bucket->key);
    if (free_data && bucket->data)
        free_data(bucket->data);
    free(bucket);
}

void ht_destroy(ht_t *ht, void (*free_data)(void *))
{
    void *data = NULL;

    if (!ht)
        return;
    if (!ht->buckets) {
        free(ht);
        return;
    }
    for (int i = 0; i < ht->size; i++) {
        if (!ht->buckets[i])
            continue;
        while (ht->buckets[i]->len > 0) {
            data = ll_pop_head(ht->buckets[i]);
            bucket_free_wrapper(data, free_data);
        }
        ll_destroy(ht->buckets[i], NULL);
    }
    free(ht->buckets);
    free(ht);
}
