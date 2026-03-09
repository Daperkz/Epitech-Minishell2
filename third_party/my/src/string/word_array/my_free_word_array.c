/*
** EPITECH PROJECT, 2025
** my_free_word_array
** File description:
** frees the word array
*/

#include <stdlib.h>

void my_free_word_array(char **word_array)
{
    if (!word_array)
        return;
    for (int i = 0; word_array[i]; i++) {
        free(word_array[i]);
    }
    free(word_array);
}
