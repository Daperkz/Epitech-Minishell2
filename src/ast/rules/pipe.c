/*
** EPITECH PROJECT, 2026
** pipe.c
** File description:
** pipe
*/

#include "shell.h"

int astexec_pipe(shell_t *shell, bnode_t *node)
{
    return (EXIT_SUCCESS);
}

int astcheck_pipe(bnode_t *left, bnode_t *right)
{
    if (!left || right) {
        my_fprintf(STDERR_FD, INVALID_COMMAND);
        return (1);
    }
    return (0);
}
