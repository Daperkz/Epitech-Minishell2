/*
** EPITECH PROJECT, 2026
** lsr.c
** File description:
** lsr
*/

#include "shell.h"

int exec_lsr(shell_t *shell, bnode_t *node)
{
    ast_data_t *rdata = (ast_data_t *)node->right->data;
    int fd;
    int saved_stdin;
    int retv;

    fd = open(rdata->args, O_RDONLY);
    if (fd == -1)
        return file_error(shell, rdata->args);
    saved_stdin = dup(STDIN_FILENO);
    if (dup2(fd, STDIN_FILENO) == -1) {
        close(fd);
        close(saved_stdin);
        return (EXIT_ERROR);
    }
    close(fd);
    retv = execute_ast(shell, node->left);
    dup2(saved_stdin, STDIN_FILENO);
    close(saved_stdin);
    return (retv);
}
