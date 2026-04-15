/*
** EPITECH PROJECT, 2026
** dgrt.c
** File description:
** dgrt
*/

#include "shell.h"

int exec_dgrt(shell_t *shell, bnode_t *node)
{
    ast_data_t *rdata = (ast_data_t *)node->right->data;
    int fd;
    int saved_stdout;
    int retv;

    fd = open(rdata->args, O_WRONLY | O_CREAT | O_APPEND, 0644);
    if (fd == -1)
        return file_error(shell, rdata->args);
    saved_stdout = dup(STDOUT_FILENO);
    if (dup2(fd, STDOUT_FILENO) == -1) {
        close(fd);
        close(saved_stdout);
        return (EXIT_ERROR);
    }
    close(fd);
    retv = execute_ast(shell, node->left);
    dup2(saved_stdout, STDOUT_FILENO);
    close(saved_stdout);
    return (retv);
}
