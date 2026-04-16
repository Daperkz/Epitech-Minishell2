/*
** EPITECH PROJECT, 2026
** pipe.c
** File description:
** pipe
*/

#include "shell.h"

int astexec_pipe(shell_t *shell, bnode_t *node)
{
    return (exec_pipe(shell, node));
}

int astcheck_pipe(shell_t *shell, bnode_t *left, bnode_t *right)
{
    if (!left || !right) {
        my_fprintf(STDERR_FD, INVALID_COMMAND);
        return (1);
    }
    UNUSED(shell);
    return (0);
}
