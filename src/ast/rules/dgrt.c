/*
** EPITECH PROJECT, 2026
** dgrt.c
** File description:
** dgrt
*/

#include "shell.h"

int astexec_dgrt(shell_t *shell, bnode_t *node)
{
    return (EXIT_SUCCESS);
}

static bool is_output_redirect(ast_type_t type)
{
    return (type == AST_GRT || type == AST_DGRT);
}

int astcheck_dgrt(bnode_t *left, bnode_t *right)
{
    ast_data_t *ldata;
    ast_data_t *rdata;

    if (!right) {
        my_fprintf(STDERR_FD, REDIR_MSSING_NAME_ERR);
        return (1);
    }
    if (!left) {
        my_fprintf(STDERR_FD, INVALID_COMMAND);
        return (1);
    }
    ldata = left->data;
    rdata = right->data;
    if (is_output_redirect(ldata->type) || is_output_redirect(rdata->type)) {
        my_fprintf(STDERR_FD, REDIR_AMBIGUOUS_OUT_ERR);
        return (1);
    }
    return (0);
}
