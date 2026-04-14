/*
** EPITECH PROJECT, 2026
** grt.c
** File description:
** grt
*/

#include "shell.h"

int astexec_grt(shell_t *shell, bnode_t *node)
{
    return (EXIT_SUCCESS);
}

int astcheck_grt(bnode_t *left, bnode_t *right)
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
    if (data->type == AST_GRT || data->type == AST_DGRT) {
        my_fprintf(STDERR_FD, REDIR_AMBIGUOUS_OUT_ERR);
        return (1);
    }
    return (0);
}
