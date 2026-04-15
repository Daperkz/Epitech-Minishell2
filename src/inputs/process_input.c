/*
** EPITECH PROJECT, 2026
** process_input.c
** File description:
** process_input
*/

#include "shell.h"

int exit_mysh(ssize_t nread)
{
    if (nread == -1) {
        if (isatty(STDIN_FD))
            write(STDOUT_FD, "exit\n", 5);
        return (EXIT_SHUTDOWN);
    }
    return (EXIT_SUCCESS);
}

int process_input(shell_t *shell)
{
    int retv = EXIT_FAILURE;

    if (create_ast(shell, shell->input) == EXIT_ERROR)
        return (EXIT_ERROR);
    if (!shell->ast)
        return (EXIT_SUCCESS);
    retv = execute_ast(shell, shell->ast->root);
    DESTROY_AST(shell->ast);
    shell->ast = NULL;
    return (retv);
}
