/*
** EPITECH PROJECT, 2026
** pipe_handler.c
** File description:
** pipe_handler
*/

#include <stdlib.h>

#include "my/string.h"
#include "my/printf.h"

#include "shell.h"

int pipe_handler(shell_t *shell, char *command)
{
    char **pipe_segments = my_str_to_str_arr(command, PIPE_SEPERATOR);
    int retv = EXIT_SUCCESS;

    if (!pipe_segments)
        return (EXIT_FAILURE);
    if (!pipe_segments[1]) {
        if (!pipe_segments[0] && my_strchr(command, '|')) {
            shell->last_errno = 1;
            my_fprintf(STDERR_FD, "Invalid null command.\n");
            return (EXIT_SUCCESS);
        }
        retv = single_command(shell, command, 0);
    } else {
        retv = execute_pipe(shell, pipe_segments);
    }
    my_free_str_arr(pipe_segments);
    return (retv);
}
