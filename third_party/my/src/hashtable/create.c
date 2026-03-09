/*
** EPITECH PROJECT, 2026
** create.c
** File description:
** create
*/

#include <stdlib.h>

#include "my/hashtable.h"

ht_t *ht_create(int (*hash)(char *, int), int size)
{
    ht_t *hashtable = (NULL);

    if (size <= 0 || !hash)
        return (NULL);
    hashtable = malloc(sizeof(ht_t));
    if (!hashtable)
        return (NULL);
    hashtable->hash = hash;
    hashtable->size = size;
    hashtable->buckets = malloc(sizeof(ll_t *) * size);
    if (!hashtable->buckets) {
        free(hashtable);
        return (NULL);
    }
    for (int i = 0; i < size; i++)
        hashtable->buckets[i] = NULL;
    return (hashtable);
}
