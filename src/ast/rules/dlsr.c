/*
** EPITECH PROJECT, 2026
** d_lsr.c
** File description:
** d_lsr
*/

#include "shell.h"

int astexec_dlsr(shell_t *shell, bnode_t *node)
{
    return (exec_dlsr(shell, node));
}

static bool is_input_redirect(ast_type_t type)
{
    return (type == AST_LSR || type == AST_DLSR);
}

int astcheck_dlsr(shell_t *shell, bnode_t *left, bnode_t *right)
{
    ast_data_t *ldata;
    ast_data_t *rdata;

    if (!right)
        return (validity_error(shell));
    if (!left) {
        shell->last_errno = 1;
        my_fprintf(STDERR_FD, INVALID_COMMAND);
        return (1);
    }
    ldata = left->data;
    rdata = right->data;
    if (is_input_redirect(ldata->type) || is_input_redirect(rdata->type))
        return (ambiguous_error(shell, REDIR_AMBIGUOUS_IN_ERR));
    return (0);
}
