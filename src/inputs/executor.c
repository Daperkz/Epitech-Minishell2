/*
** EPITECH PROJECT, 2026
** executor.c
** File description:
** executor
*/

#include <stdlib.h>
#include <signal.h>
#include <errno.h>
#include <string.h>
#include <stdio.h>


#include "my/printf.h"

#include "shell.h"

static void error_printing(char *cmd)
{
    switch (errno) {
        case ENOEXEC:
            my_fprintf(STDERR, "%s: %s. Binary file not executable.\n",
                cmd, strerror(errno));
            break;
        default :
            my_fprintf(STDERR, "%s: %s.\n", cmd, strerror(errno));
    }
}

int execute_child(shell_t *shell, char *program_path)
{
    signal(SIGINT, SIG_DFL);
    execve(program_path, shell->input_array, shell->env);
    error_printing(shell->input_array[0]);
    exit(EXIT_FAILURE);
}

int execute_command(shell_t *shell, char *program_path)
{
    shell->child = fork();
    if (shell->child == -1) {
        perror("fork");
        return (EXIT_FAILURE);
    }
    if (shell->child == 0) {
        execute_child(shell, program_path);
    } else {
        waitpid(shell->child, &shell->child_status, WUNTRACED);
        handle_child_status(shell, shell->child_status);
    }
    return (EXIT_SUCCESS);
}
