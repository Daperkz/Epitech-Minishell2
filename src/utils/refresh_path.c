/*
** EPITECH PROJECT, 2026
** refresh_path.c
** File description:
** refresh_path
*/

#include "my/string.h"

#include "shell.h"

int refresh_path(shell_t *shell)
{
    if (shell->path_arr) {
        my_free_str_arr(shell->path_arr);
        shell->path_arr = NULL;
    }
    shell->path_arr = get_path_array(shell->env);
    if (shell->path_arr == MALLOC_FAIL) {
        shell->path_arr = NULL;
        return (EXIT_FAILURE);
    }
    return (EXIT_ACTION_DONE);
}
