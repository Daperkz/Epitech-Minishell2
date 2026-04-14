/*
** EPITECH PROJECT, 2026
** exit.c
** File description:
** exit
*/

#include "shell.h"

// when the input is exit returns 0 or the number passed in arg
int exit_builtin(shell_t *shell, char **cmd_args)
{
    shell->last_errno = 0;
    if (my_len_str_arr(cmd_args) == 1)
        return (EXIT_SHUTDOWN);
    if (my_len_str_arr(cmd_args) == 2) {
        if (my_str_isnum(cmd_args[1])) {
            shell->last_errno = my_atoi(cmd_args[1]);
        } else {
            shell->last_errno = EINVAL;
            my_fprintf(STDERR_FD, "%s: Expression Syntax.\n", EXIT_INPUT);
            return (EXIT_ACTION_DONE);
        }
    }
    return (EXIT_SHUTDOWN);
}
