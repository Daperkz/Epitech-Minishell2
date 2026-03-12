/*
** EPITECH PROJECT, 2026
** my_copy_str_arr.c
** File description:
** my_copy_str_arr
*/

#include <stdlib.h>

#include "my/string.h"

char **my_cpy_str_arr(char **str_arr)
{
    int i = 0;
    char **new_str_arr = NULL;

    while (str_arr && str_arr[i])
        i++;
    new_str_arr = malloc(sizeof(char *) * (i + 1));
    if (!new_str_arr)
        return (NULL);
    for (int j = 0; j < i; j++) {
        new_str_arr[j] = my_strdup(str_arr[j]);
        if (!new_str_arr[j]) {
            new_str_arr[j] = NULL;
            my_free_str_arr(new_str_arr);
            return NULL;
        }
    }
    new_str_arr[i] = NULL;
    return new_str_arr;
}
