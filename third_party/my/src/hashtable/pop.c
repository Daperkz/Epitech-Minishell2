/*
** EPITECH PROJECT, 2026
** pop.c
** File description:
** pop
*/

#include "my/macro.h"
#include "my/string.h"
#include "my/hashtable.h"

static int compare_keys(void *data, void *ref)
{
    return my_strcmp(((ht_buckets_t *)data)->key, (char *)ref);
}

void *ht_pop(ht_t *ht, char *key)
{
    int index = 0;
    ht_buckets_t *output = NULL;
    void *data = NULL;

    if (!ht || !key)
        return (NULL);
    index = ht->hash(key, ht->size);
    if (!ht->buckets[index])
        return (NULL);
    output = ll_pop(ht->buckets[index], key, compare_keys);
    data = bucket_destroy(output);
    if (ht->buckets[index]->len == 0) {
        ll_destroy(ht->buckets[index], NULL);
    }
    return (data);
}
