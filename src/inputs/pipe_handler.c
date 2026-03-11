/*
** EPITECH PROJECT, 2026
** pipe_handler.c
** File description:
** pipe_handler
*/

#include <stdlib.h>

#include "my/string.h"

#include "shell.h"

static void pipe_child(shell_t *shell, char **pipe_segments, int i, int prev_fd)
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
}

static int execute_pipe(shell_t *shell, char **pipe_segments)
{
    int prev_fd = STDIN_FILENO;
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

int pipe_handler(shell_t *shell, char *command)
{
    char **pipe_segments = my_str_to_word_array(command, PIPE_SEPERATOR);
    int retv = EXIT_SUCCESS;

    if (!pipe_segments)
        return (EXIT_FAILURE);
    if (!pipe_segments[1]) {
        retv = single_command(shell, command, 0);
    } else {
        retv = execute_pipe(shell, pipe_segments);
    }
    my_free_word_array(pipe_segments);
    return (retv);
}
