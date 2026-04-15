/*
** EPITECH PROJECT, 2026
** dlsr.c
** File description:
** dlsr
*/

/*
** EPITECH PROJECT, 2026
** heredoc.c
** File description:
** heredoc
*/

#include "shell.h"

static void heredoc_loop(char *keyword, int fd)
{
    char *line = NULL;
    size_t n = 0;

    while (1) {
        if (isatty(STDIN_FD))
            write(STDOUT_FD, REDIR_HEREDOC_MESSAGE, REDIR_HEREDOC_MESSAGE_LEN);
        if (getline(&line, &n, stdin) == -1)
            break;
        if (my_strncmp(line, keyword, my_strlen(keyword)) == 0 &&
            line[my_strlen(keyword)] == '\n')
            break;
        write(fd, line, my_strlen(line));
    }
    free(line);
}

int exec_dlsr(shell_t *shell, bnode_t *node)
{
    ast_data_t *rdata = (ast_data_t *)node->right->data;
    int retv;
    char *keyword = rdata->args;
    int pipefd[2];
    int saved_stdin;

    if (pipe(pipefd) == -1)
        return (EXIT_ERROR);
    heredoc_loop(keyword, pipefd[1]);
    close(pipefd[1]);
    saved_stdin = dup(STDIN_FILENO);
    dup2(pipefd[0], STDIN_FILENO);
    close(pipefd[0]);
    retv = execute_ast(shell, node->left);
    dup2(saved_stdin, STDIN_FILENO);
    close(saved_stdin);
    return (retv);
}
