/*
** EPITECH PROJECT, 2026
** env.c
** File description:
** env
*/

#include "shell.h"

int env_builtin(shell_t *shell, char **cmd_args)
{
    shell->last_errno = 0;
    if (my_len_str_arr(cmd_args) == 1) {
        my_put_str_arr(shell->env, '\n');
        return (EXIT_ACTION_DONE);
    } else {
        shell->last_errno = EINVAL;
        my_fprintf(STDERR_FD, "%s: Invalid argument.\n", ENV_INPUT);
        return (EXIT_ACTION_DONE);
    }
    return (EXIT_SUCCESS);
}
