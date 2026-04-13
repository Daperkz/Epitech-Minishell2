/*
** EPITECH PROJECT, 2026
** executor.c
** File description:
** executor
*/

#include "shell.h"

static void sync_pipe_remnants(shell_t *shell, pid_t last_pid)
{
    if (last_pid != -1) {
        waitpid(last_pid, &shell->child_status, 0);
        handle_child_status(shell, shell->child_status);
    }
    while (wait(NULL) > 0);
}

int execute_pipe(shell_t *shell, char **pipe_segments)
{
    int prev_fd = STDIN_FD;
    pid_t last_pid;

    for (int i = 0; pipe_segments[i]; i++) {
        if (pipe_segments[i + 1])
            pipe(shell->pipe_fds);
        if (is_builtin(pipe_segments[i])) {
            shell->last_errno = pipe_builtin(shell, pipe_segments, i, prev_fd);
            last_pid = (!pipe_segments[i + 1]) ? -1 : last_pid;
        } else {
            pipe_child(shell, pipe_segments, i, prev_fd);
            last_pid = shell->child;
        }
        if (pipe_segments[i + 1]) {
            close(shell->pipe_fds[1]);
            prev_fd = shell->pipe_fds[0];
        }
    }
    sync_pipe_remnants(shell, last_pid);
    return (EXIT_SUCCESS);
}
