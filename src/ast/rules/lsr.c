/*
** EPITECH PROJECT, 2026
** lsr.c
** File description:
** lsr
*/

#include "shell.h"

int astexec_lsr(shell_t *shell, bnode_t *node)
{
    return (EXIT_SUCCESS);
}

static bool is_input_redir(ast_type_t type)
{
    return (type == AST_LSR || type == AST_DLSR);
}

int astcheck_lsr(bnode_t *left, bnode_t *right)
{
    if (!right) {
        my_fprintf(STDERR_FD, REDIR_MSSING_NAME_ERR);
        return (1);
    }
    if (!left) {
        my_fprintf(STDERR_FD, INVALID_COMMAND);
        return (1);
    }
     if (is_input_redir(((ast_data_t *)(left->data))->type)) {
        my_fprintf(STDERR_FD, REDIR_AMBIGUOUS_OUT_ERR);
        return (1);
    }
    return (0);
}
