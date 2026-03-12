/*
** EPITECH PROJECT, 2025
** my_free_str_arr
** File description:
** frees the word array
*/

#include <stdlib.h>

void my_free_str_arr(char **str_arr)
{
    if (!str_arr)
        return;
    for (int i = 0; str_arr[i]; i++) {
        free(str_arr[i]);
    }
    free(str_arr);
}
