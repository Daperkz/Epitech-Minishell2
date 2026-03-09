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
    char *dest = NULL;
    char *origin = NULL;

    if (!src)
        return (NULL);
    dest = malloc(my_strlen(src) + 1);
    if (dest == NULL)
        return (NULL);
    origin = dest;
    while (*src) {
        *dest = *src;
        src++;
        dest++;
    }
    *dest = '\0';
    return (origin);
}

char *my_strndup(char const *src, int n)
{
    char *dest = malloc(sizeof(char) * n + 1);
    int i = 0;

    if (!dest)
        return NULL;
    while (src[i] != '\0' && i < n) {
        dest[i] = src[i];
        i++;
    }
    dest[i] = '\0';
    return dest;
}
