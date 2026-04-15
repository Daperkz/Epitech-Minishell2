/*
** EPITECH PROJECT, 2026
** command.c
** File description:
** command
*/

#include "shell.h"

int execute_command(shell_t *shell, char **cmd_args, char *program_path)
{
    shell->child = fork();
    if (shell->child == -1) {
        perror("fork");
        return (EXIT_FAILURE);
    }
    if (shell->child == 0) {
        execute_child(shell, cmd_args, program_path);
    } else {
        waitpid(shell->child, &shell->child_status, WUNTRACED);
        handle_child_status(shell, shell->child_status);
    }
    return (EXIT_SUCCESS);
}

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

int exec_command(shell_t *shell, char **cmd_args)
{
    int retv = builtins(shell, cmd_args);

    if (retv == EXIT_FAILURE || retv == EXIT_SHUTDOWN ||
        retv == EXIT_ACTION_DONE)
        return (retv);
    return (not_a_builtin(shell, cmd_args));
}
