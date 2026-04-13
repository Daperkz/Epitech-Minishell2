/*
** EPITECH PROJECT, 2026
** exit.c
** File description:
** exit
*/

#include "shell.h"

// when the input is exit returns 0 or the number passed in arg
int exit_builtin(shell_t *shell)
{
    shell->last_errno = 0;
    if (shell->input_array_len == 1)
        return (EXIT_SHUTDOWN);
    if (shell->input_array_len == 2) {
        if (my_str_isnum(shell->input_array[1])) {
            shell->last_errno = my_atoi(shell->input_array[1]);
        } else {
            shell->last_errno = EINVAL;
            my_fprintf(STDERR_FD, "%s: Expression Syntax.\n", EXIT_INPUT);
            return (EXIT_ACTION_DONE);
        }
    }
    return (EXIT_SHUTDOWN);
}
