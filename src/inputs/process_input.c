/*
** EPITECH PROJECT, 2026
** process_input.c
** File description:
** process_input
*/

#include <stdlib.h>
#include <errno.h>

#include "my/printf.h"
#include "my/string.h"

#include "shell.h"

int exit_mysh(ssize_t nread)
{
    if (nread == -1) {
        if (isatty(STDIN))
            write(STDOUT, "exit\n", 5);
        return (EXIT_SHUTDOWN);
    }
    return (EXIT_SUCCESS);
}

static int multiple_commands(shell_t *shell)
{
    int retv = EXIT_SUCCESS;
    int willexit = 0;

    for (int i = 0; shell->commands[i]; i++) {
        retv = pipe_handler(shell, shell->commands[i]);
        if (retv == EXIT_SHUTDOWN)
            willexit = 1;
    }
    return (willexit ? EXIT_SHUTDOWN : retv);
}

int process_input(shell_t *shell)
{
    int retv = EXIT_FAILURE;

    if (parse_input(shell) == EXIT_FAILURE)
        return (EXIT_FAILURE);
    if (!shell->commands) {
        retv = pipe_handler(shell, shell->input);
    } else if (shell->commands) {
        retv = multiple_commands(shell);
    }
    my_free_word_array(shell->commands);
    shell->commands = NULL;
    shell->nbr_commands = 0;
    return (retv);
}
