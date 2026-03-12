/*
** EPITECH PROJECT, 2026
** heredoc.c
** File description:
** heredoc
*/

#include <stdio.h>
#include <fcntl.h>

#include "shell.h"

int heredoc(shell_t *shell, int i)
{
    int tmp_fd = -1;

    tmp_fd = open(HEREDOC_TMP_FILE, O_WRONLY | O_CREAT | O_TRUNC, 0600);
    if (tmp_fd == -1)
        return (EXIT_FAILURE);
    close(tmp_fd);
    remove(HEREDOC_TMP_FILE);
    shift_array(shell, i);
    return (EXIT_SUCCESS);
}
