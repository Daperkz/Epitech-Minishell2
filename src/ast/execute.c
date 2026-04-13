/*
** EPITECH PROJECT, 2026
** execute.c
** File description:
** execute
*/

#include "shell.h"

int execute_ast(shell_t *shell, bnode_t *node)
{
    ast_data_t *data;

    if (!node || !node->data)
        return (EXIT_ERROR);
    data = (ast_data_t *)node->data;
    if (data->type == AST_NONE)
        return (EXIT_SUCCESS);
    if (data->type == AST_COMMAND)
        return (astexec_command(shell, node));
    for (int i = 0; AST_RULES[i].token != NULL; i++) {
        if (AST_RULES[i].type == data->type && AST_RULES[i].execute_func) {
            return AST_RULES[i].execute_func(shell, node);
        }
    }
    return (EXIT_ERROR);
}
