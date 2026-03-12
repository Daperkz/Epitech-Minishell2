/*
** EPITECH PROJECT, 2026
** destroy_shell.c
** File description:
** destroy_shell
*/

#include <stdlib.h>

#include "my/string.h"

#include "shell.h"

void destroy_shell(shell_t *shell)
{
    my_free_str_arr(shell->env);
    free(shell->cwd);
    free(shell->owd);
    free(shell->hwd);
    my_free_str_arr(shell->path_arr);
    free(shell->input);
}
