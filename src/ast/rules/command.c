/*
** EPITECH PROJECT, 2026
** command.c
** File description:
** command
*/

#include "shell.h"

int astexec_command(shell_t *shell, bnode_t *node)
{
    ast_data_t *data;

    if (!node || !node->data)
        return (EXIT_SUCCESS);
    data = (ast_data_t *)node->data;
    if (!data->cmd_args || !data->cmd_args[0])
        return (EXIT_SUCCESS);
    return (exec_command(shell, data->cmd_args));
}
