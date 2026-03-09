/*
** EPITECH PROJECT, 2026
** process_input.c
** File description:
** process_input
*/

#include <stdlib.h>
#include <errno.h>

#include "my/printf.h"

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

int process_input(shell_t *shell)
{
    char *program_path = NULL;
    int retv = (EXIT_SUCCESS);

    if (parse_input(shell) == EXIT_FAILURE) {
        return (EXIT_FAILURE);
    } else if (shell->input_array_len < 1)
        return (EXIT_SUCCESS);
    retv = builtins(shell);
    if (retv == EXIT_FAILURE || retv == EXIT_SHUTDOWN) {
        return (retv);
    } else if (retv == EXIT_ACTION_DONE)
        return (EXIT_SUCCESS);
    program_path = find_command(shell);
    if (program_path == MALLOC_FAIL) {
        return (EXIT_FAILURE);
    } else if (!program_path)
        return (EXIT_SUCCESS);
    retv = execute_command(shell, program_path);
    free(program_path);
    return (retv);
}
