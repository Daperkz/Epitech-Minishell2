/*
** EPITECH PROJECT, 2026
** command.c
** File description:
** command
*/

#include "shell.h"

static int not_a_builtin(shell_t *shell, char **cmd_args)
{
    int retv = (EXIT_SUCCESS);
    char *program_path = find_command(shell, cmd_args);

    if (program_path == MALLOC_FAIL) {
        return (EXIT_FAILURE);
    } else if (!program_path)
        return (EXIT_SUCCESS);
    if (shell->is_piped) {
        execute_child(shell, cmd_args, program_path);
        free(program_path);
        return (EXIT_FAILURE);
    }
    retv = execute_command(shell, cmd_args, program_path);
    free(program_path);
    return (retv);
}

int astexec_command(shell_t *shell, bnode_t *node)
{
    ast_data_t *data;
    int retv;

    if (!node || !node->data)
        return (EXIT_SUCCESS);
    data = (ast_data_t *)node->data;
    if (!data->cmd_args || !data->cmd_args[0])
        return (EXIT_SUCCESS);
    retv = builtins(shell, data->cmd_args);
    if (retv == EXIT_FAILURE || retv == EXIT_SHUTDOWN ||
        retv == EXIT_ACTION_DONE)
        return (retv);
    return (not_a_builtin(shell, data->cmd_args));
}
