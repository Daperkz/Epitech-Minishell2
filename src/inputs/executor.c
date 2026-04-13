/*
** EPITECH PROJECT, 2026
** executor.c
** File description:
** executor
*/

#include "shell.h"

static void error_printing(char *cmd)
{
    switch (errno) {
        case ENOEXEC:
            my_fprintf(STDERR_FD, "%s: %s. Binary file not executable.\n",
                cmd, strerror(errno));
            break;
        default :
            my_fprintf(STDERR_FD, "%s: %s.\n", cmd, strerror(errno));
    }
}

int execute_child(shell_t *shell, char **cmd_args, char *program_path)
{
    signal(SIGINT, SIG_DFL);
    execve(program_path, cmd_args, shell->env);
    error_printing(cmd_args[0]);
    exit(EXIT_FAILURE);
}

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
