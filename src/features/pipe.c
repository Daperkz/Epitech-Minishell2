/*
** EPITECH PROJECT, 2026
** pipe.c
** File description:
** pipe
*/

#include "shell.h"

static void exec_pipe_left(shell_t *shell, bnode_t *node, int *pfd)
{
    close(pfd[0]);
    dup2(pfd[1], STDOUT_FILENO);
    close(pfd[1]);
    exit(execute_ast(shell, node->left));
}

static int exec_pipe_right(shell_t *shell, bnode_t *node, int *pfd)
{
    int retv;

    close(pfd[1]);
    dup2(pfd[0], STDIN_FILENO);
    close(pfd[0]);
    retv = execute_ast(shell, node->right);
    return (retv);
}

int exec_pipe(shell_t *shell, bnode_t *node)
{
    int pfd[2];
    pid_t lpid;
    int saved_stdin = dup(STDIN_FILENO);
    int retv;

    if (pipe(pfd) == -1)
        return (EXIT_ERROR);
    lpid = fork();
    if (lpid == -1)
        return (EXIT_ERROR);
    if (lpid == 0)
        exec_pipe_left(shell, node, pfd);
    retv = exec_pipe_right(shell, node, pfd);
    dup2(saved_stdin, STDIN_FILENO);
    close(saved_stdin);
    waitpid(lpid, NULL, 0);
    return (retv);
}
