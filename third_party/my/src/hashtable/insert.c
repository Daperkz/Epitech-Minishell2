/*
** EPITECH PROJECT, 2026
** insert.c
** File description:
** insert
*/

#include <stdlib.h>

#include "my/string.h"

#include "my/hashtable.h"
#include "my/linked_lists/simple_linked_list.h"

static int compare_keys(void *data, void *ref)
{
    return my_strcmp(((ht_buckets_t *)data)->key, (char *)ref);
}

static int ll_update_node(ll_t *list, char *key, void *data)
{
    ht_buckets_t *bucket = (ht_buckets_t *)ll_get(list, key, compare_keys);

    if (!bucket)
        return (EXIT_FAILURE);
    bucket->data = data;
    return (EXIT_SUCCESS);
}

int ht_insert(ht_t *ht, char *key, void *data)
{
    int index = 0;
    ht_buckets_t *entry;

    if (!ht || !key || !data)
        return (EXIT_FAILURE);
    index = ht->hash(key, ht->size);
    if (ll_update_node(ht->buckets[index], key, data) == EXIT_SUCCESS)
        return (EXIT_SUCCESS);
    entry = bucket_create(key, data);
    if (!entry)
        return (EXIT_FAILURE);
    if (!ht->buckets[index]) {
        ht->buckets[index] = ll_create();
        if (!ht->buckets[index]) {
            free(entry->key);
            free(entry);
            return (EXIT_FAILURE);
        }
    }
    return (ll_insert(ht->buckets[index], entry));
}
