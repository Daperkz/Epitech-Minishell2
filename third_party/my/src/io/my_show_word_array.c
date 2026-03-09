/*
** EPITECH PROJECT, 2025
** my_show_word_array
** File description:
** displays the content of an array of words.
** There is one word per line, and each word ends with '\n',
** including the last one.
*/

#include <stdlib.h>

#include "my/string.h"
#include "my/utils.h"

int my_show_word_array(char **tab)
{
    int count = 0;
    char *str = NULL;

    if (!tab)
        return (EXIT_FAILURE);
    while (tab[count] != 0) {
        count++;
    }
    if (count == 0 && tab[count] == 0) {
        return (EXIT_SUCCESS);
    }
    str = concat_params(count, tab);
    my_strcat(str, "\n");
    my_putstr(str);
    free(str);
    return (EXIT_SUCCESS);
}
