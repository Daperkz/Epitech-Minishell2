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

static bool is_input_redirect(ast_type_t type)
{
    return (type == AST_LSR || type == AST_DLSR);
}

int astcheck_dlsr(bnode_t *left, bnode_t *right)
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
    if (is_input_redirect(ldata->type) || is_input_redirect(rdata->type)) {
        my_fprintf(STDERR_FD, REDIR_AMBIGUOUS_IN_ERR);
        return (1);
    }
    return (0);
}
