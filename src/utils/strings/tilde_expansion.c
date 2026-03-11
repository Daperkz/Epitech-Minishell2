/*
** EPITECH PROJECT, 2026
** tilde_expansion.c
** File description:
** tilde_expansion
*/

#include <stdlib.h>

#include "my/string.h"

#include "shell.h"

static int count_apparition(char *str, char c)
{
    int len = 0;

    while (str && *str) {
        if (*str == c)
            len++;
        str++;
    }
    return (len);
}

static void fill(shell_t *shell, char *new_input)
{
    int j = 0;
    int hwd_len = my_strlen(shell->hwd);

    for (int i = 0; shell->input[i]; i++) {
        if (shell->input[i] == '~') {
            my_strncpy(&new_input[j], shell->hwd, hwd_len);
            j += hwd_len;
        } else {
            new_input[j] = shell->input[i];
            j++;
        }
    }
    new_input[j] = '\0';
}

int tilde_expansion(shell_t *shell)
{
    int n;
    int new_len;
    char *new_input = NULL;

    if (!shell->input || !shell->hwd)
        return (EXIT_SUCCESS);
    n = count_apparition(shell->input, '~');
    if (count_apparition(shell->input, '~') == 0)
        return (EXIT_SUCCESS);
    new_len = my_strlen(shell->input) + (n * (my_strlen(shell->hwd) - 1));
    new_input = malloc(sizeof(char) * (new_len + 1));
    if (!new_input)
        return (EXIT_FAILURE);
    fill(shell, new_input);
    free(shell->input);
    shell->input = new_input;
    return (EXIT_SUCCESS);
}
