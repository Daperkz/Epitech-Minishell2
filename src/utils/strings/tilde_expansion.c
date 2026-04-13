/*
** EPITECH PROJECT, 2026
** tilde_expansion.c
** File description:
** tilde_expansion
*/

#include "shell.h"

static void fill(char *old, char *new, char *hwd)
{
    int i = 0;
    int j = 0;

    while (old[i] && old[i] != '~') {
        new[j] = old[i];
        i++;
        j++;
    }
    if (old[i] == '~') {
        my_strcpy(&new[j], hwd);
        j += my_strlen(hwd);
        i++;
    }
    my_strcpy(&new[j], &old[i]);
}

int tilde_expansion(char **str_p, char *hwd)
{
    int new_len;
    char *new_input = NULL;

    if (!str_p || !*str_p || !hwd || !my_strchr(*str_p, '~'))
        return (EXIT_SUCCESS);
    new_len = my_strlen(*str_p) + my_strlen(hwd) - 1;
    new_input = malloc(sizeof(char) * (new_len + 1));
    if (!new_input)
        return (EXIT_FAILURE);
    fill(*str_p, new_input, hwd);
    free(*str_p);
    *str_p = new_input;
    return (EXIT_SUCCESS);
}
