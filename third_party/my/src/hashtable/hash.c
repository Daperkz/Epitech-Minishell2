/*
** EPITECH PROJECT, 2026
** hash.c
** File description:
** hash
*/

static int internal_sdbm(char *key)
{
    unsigned int hashed = 0;

    while (*key) {
        hashed = (unsigned int)(*key) + (hashed << 6) + (hashed << 16) - hashed;
        key++;
    }
    return hashed;
}

int sdbm(char *key, int len)
{
    unsigned int result = 0;

    if (!key || len <= 0)
        return 0;
    result = internal_sdbm(key);
    return (int)(result % (unsigned int)len);
}

static int internal_fnv_1a(char *key)
{
    unsigned int hashed = 0x811c9dc5;

    while (*key) {
        hashed ^= (unsigned int)(*key);
        hashed *= 0x01000193;
        key++;
    }
    return hashed;
}

int fnv_1a(char *key, int len)
{
    unsigned int result = 0;

    if (!key || len <= 0)
        return 0;
    result = internal_fnv_1a(key);
    return (int)(result % (unsigned int)len);
}

static int internal_djb2(char *key)
{
    unsigned int hashed = 5381;

    while (*key) {
        hashed = ((hashed << 5) + hashed) ^ (unsigned int)(*key);
        key++;
    }
    return hashed;
}

int djb2(char *key, int len)
{
    unsigned int result = 0;

    if (!key || len <= 0)
        return 0;
    result = internal_djb2(key);
    return (int)(result % (unsigned int)len);
}

int hash(char *key, int len)
{
    unsigned int result = 0;

    if (!key || len <= 0)
        return 0;
    result = internal_fnv_1a(key);
    return (int)(result % (unsigned int)len);
}
