/*
** EPITECH PROJECT, 2026
** pipeline.c
** File description:
** pipeline
*/

#include "shell.h"

int ast_pipeline(shell_t *shell)
{
    int retv = EXIT_FAILURE;

    if (create_ast(shell, shell->input) == EXIT_ERROR)
        return (EXIT_ERROR);
    if (!shell->ast)
        return (EXIT_SUCCESS);
    if (!shell->ast->root) {
        DESTROY_AST(shell->ast);
        return (EXIT_SUCCESS);
    }
    retv = execute_ast(shell, shell->ast->root);
    DESTROY_AST(shell->ast);
    shell->ast = NULL;
    return (retv);
}
