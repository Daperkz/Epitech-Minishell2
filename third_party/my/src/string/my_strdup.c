/*
** EPITECH PROJECT, 2025
** my_strdup
** File description:
** allocates memory and copies the string given as argument in it.
*/

#include <stdlib.h>

#include "my/string.h"

char *my_strdup(char const *src)
{
    char *ptr = malloc(my_strlen(src) + 1);
    char *origin = ptr;

    if (ptr == NULL) {
        return NULL;
    }
    while (*src) {
        *ptr = *src;
        src++;
        ptr++;
    }
    *ptr = '\0';
    return origin;
}

char *my_strndup(char const *src, int n)
{
    char *str = malloc(sizeof(char) * n + 1);
    int i = 0;

    if (!str)
        return NULL;
    while (src[i] != '\0' && i < n) {
        str[i] = src[i];
        i++;
    }
    str[i] = '\0';
    return str;
}
