/*
** EPITECH PROJECT, 2026
** minishell.c
** File description:
** minishell
*/

#include "shell.h"

int minishell(shell_t *shell)
{
    size_t size = 0;
    int retv = EXIT_SUCCESS;

    while (1) {
        print_the_prompt(shell);
        shell->input_len = getline(&shell->input, &size, stdin);
        if (exit_mysh(shell->input_len) == EXIT_SHUTDOWN)
            return (shell->last_errno);
        if (create_ast(shell, shell->input) == EXIT_ERROR)
            return (EXIT_ERROR);
        retv = execute_ast(shell, shell->ast->root);
        DESTROY_AST(shell->ast);
        shell->input_array = NULL;
        if (retv == EXIT_FAILURE)
            return (EXIT_ERROR);
        if (retv == EXIT_SHUTDOWN)
            return (shell->last_errno);
    }
    return (EXIT_SUCCESS);
}

int main(int argc, char **argv, char **env)
{
    shell_t shell = {0};
    int retv = EXIT_SUCCESS;

    if (argc != 1)
        return (EXIT_ERROR);
    UNUSED(argv);
    if (init_shell(&shell, env) == EXIT_FAILURE)
        return (EXIT_ERROR);
    retv = minishell(&shell);
    destroy_shell(&shell);
    return (retv);
}
