/*
** EPITECH PROJECT, 2026
** child.c
** File description:
** child
*/

#include <stdlib.h>

#include "shell.h"

void pipe_child(shell_t *shell, char **pipe_segments, int i, int prev_fd)
{
    int retv = (EXIT_SUCCESS);

    shell->child = fork();
    if (shell->child == 0) {
        if (prev_fd != 0) {
            dup2(prev_fd, 0);
            close(prev_fd);
        }
        if (pipe_segments[i + 1]) {
            close(shell->pipe_fds[0]);
            dup2(shell->pipe_fds[1], 1);
            close(shell->pipe_fds[1]);
        }
        retv = single_command(shell, pipe_segments[i], 1);
        exit(retv);
    }
    if (prev_fd != 0)
        close(prev_fd);
}
