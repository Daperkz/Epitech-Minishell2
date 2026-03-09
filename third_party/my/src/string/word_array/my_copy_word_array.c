/*
** EPITECH PROJECT, 2026
** my_copy_word_array.c
** File description:
** my_copy_word_array
*/

#include <stdlib.h>

#include "my/string.h"

char **my_copy_word_array(char **word_array)
{
    int i = 0;
    char **new_word_array = NULL;

    while (word_array && word_array[i])
        i++;
    new_word_array = malloc(sizeof(char *) * (i + 1));
    if (!new_word_array)
        return (NULL);
    for (int j = 0; j < i; j++) {
        new_word_array[j] = my_strdup(word_array[j]);
        if (!new_word_array[j]) {
            new_word_array[j] = NULL;
            my_free_word_array(new_word_array);
            return NULL;
        }
    }
    new_word_array[i] = NULL;
    return new_word_array;
}
