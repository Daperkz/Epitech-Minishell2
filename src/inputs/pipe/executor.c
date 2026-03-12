/*
** EPITECH PROJECT, 2026
** executor.c
** File description:
** executor
*/

#include "my/printf.h"

#include "shell.h"

int execute_pipe(shell_t *shell, char **pipe_segments)
{
    int prev_fd = STDIN_FD;
    pid_t last_pid;

    for (int i = 0; pipe_segments[i]; i++) {
        if (pipe_segments[i + 1])
            pipe(shell->pipe_fds);
        pipe_child(shell, pipe_segments, i, prev_fd);
        if (prev_fd != 0)
            close(prev_fd);
        if (pipe_segments[i + 1]) {
            close(shell->pipe_fds[1]);
            prev_fd = shell->pipe_fds[0];
        }
        last_pid = shell->child;
    }
    waitpid(last_pid, &shell->child_status, 0);
    handle_child_status(shell, shell->child_status);
    while (wait(NULL) > 0);
    return (EXIT_SUCCESS);
}
