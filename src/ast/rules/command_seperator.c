/*
** EPITECH PROJECT, 2026
** command_seperator.c
** File description:
** command_seperator
*/

#include "shell.h"

int astexec_command_separator(shell_t *shell, bnode_t *node)
{
    if (execute_ast(shell, node->left) == EXIT_ERROR)
        return (EXIT_ERROR);
    return (execute_ast(shell, node->right));
}
