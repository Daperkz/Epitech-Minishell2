/*
** EPITECH PROJECT, 2026
** G-CPE-110 : Secured
** File description:
** hashtable.h
*/

#ifndef HASHTABLE_H
    #define HASHTABLE_H

    #include "graph/simple_linked_list.h"

typedef struct ht_buckets_s {
    char *key;
    void *data;
} ht_buckets_t;

ht_buckets_t *bucket_create(char *key, void *data);
void *bucket_destroy(ht_buckets_t *bucket);

typedef struct hashtable_s {
    int (*hash)(char *, int);
    int size;
    ll_t **buckets;
} ht_t;

// Hash functions

int sdbm(char *key, int len);
int fnv_1a(char *key, int len);
int djb2(char *key, int len);
int hash(char *key, int len);

// Create & destro table

ht_t *ht_create(int (*hash)(char *, int), int size);
void ht_destroy(ht_t *ht, void (*free_data)(void *));

// Handle table

int ht_insert(ht_t *ht, char *key, void *data);
void *ht_pop(ht_t *ht, char *key);
void *ht_get(ht_t *ht, char *key);
void ht_dump(ht_t *ht, void (*dump_data)(void *));

#endif /* HASHTABLE_H */
