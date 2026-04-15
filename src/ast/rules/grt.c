/*
** EPITECH PROJECT, 2026
** grt.c
** File description:
** grt
*/

#include "shell.h"

int astexec_grt(shell_t *shell, bnode_t *node)
{
    return (exec_grt(shell, node));
}

static bool is_output_redirect(ast_type_t type)
{
    return (type == AST_GRT || type == AST_DGRT);
}

int astcheck_grt(shell_t *shell, bnode_t *left, bnode_t *right)
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
    if (is_output_redirect(ldata->type) || is_output_redirect(rdata->type))
        return (ambiguous_error(shell, REDIR_AMBIGUOUS_OUT_ERR));
    return (0);
}
