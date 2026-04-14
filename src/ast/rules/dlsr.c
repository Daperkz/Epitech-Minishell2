/*
** EPITECH PROJECT, 2026
** d_lsr.c
** File description:
** d_lsr
*/

#include "shell.h"

int astexec_dlsr(shell_t *shell, bnode_t *node)
{
    return (EXIT_SUCCESS);
}

int astcheck_dlsr(bnode_t *left, bnode_t *right)
{
    ast_data_t *data;

    if (!right) {
        my_fprintf(STDERR_FD, REDIR_MSSING_NAME_ERR);
        return (1);
    }
    if (!left) {
        my_fprintf(STDERR_FD, INVALID_COMMAND);
        return (1);
    }
    data = left->data;
    if (data->type == AST_LSR || data->type == AST_DLSR) {
        my_fprintf(STDERR_FD, REDIR_AMBIGUOUS_OUT_ERR);
        return (1);
    }
    return (0);
}
