/*
** EPITECH PROJECT, 2026
** builtin.c
** File description:
** builtin
*/

#include "shell.h"

int pipe_builtin(shell_t *shell, char **pipe_segments, int i, int prev_fd)
{
    int saved_in = dup(STDIN_FD);
    int saved_out = dup(STDOUT_FD);
    int retv = (EXIT_SUCCESS);

    if (prev_fd != STDIN_FD) {
        dup2(prev_fd, STDIN_FD);
        close(prev_fd);
    }
    if (pipe_segments[i + 1])
        dup2(shell->pipe_fds[1], STDOUT_FD);
    retv = single_command(shell, pipe_segments[i], 0);
    dup2(saved_in, STDIN_FD);
    dup2(saved_out, STDOUT_FD);
    close(saved_in);
    close(saved_out);
    return (retv);
}
