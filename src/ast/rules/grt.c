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

static bool is_output_redir(ast_type_t type)
{
    return (type == AST_GRT || type == AST_DGRT);
}

int astcheck_grt(bnode_t *left, bnode_t *right)
{
    if (!right) {
        my_fprintf(STDERR_FD, REDIR_MSSING_NAME_ERR);
        return (1);
    }
    if (!left) {
        my_fprintf(STDERR_FD, INVALID_COMMAND);
        return (1);
    }
    if (is_output_redir(((ast_data_t *)(left->data))->type)) {
        my_fprintf(STDERR_FD, REDIR_AMBIGUOUS_OUT_ERR);
        return (1);
    }
    return (0);
}
