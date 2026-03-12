/*
** EPITECH PROJECT, 2026
** env.c
** File description:
** env
*/

#include <errno.h>

#include "my/printf.h"
#include "my/string.h"

#include "shell.h"

int env_builtin(shell_t *shell)
{
    shell->last_errno = 0;
    if (shell->input_array_len == 1) {
        my_print_word_array(shell->env, '\n');
        return (EXIT_ACTION_DONE);
    } else {
        shell->last_errno = EINVAL;
        my_fprintf(STDERR_FD, "%s: Invalid argument.\n", ENV_INPUT);
        return (EXIT_ACTION_DONE);
    }
    return (EXIT_SUCCESS);
}
