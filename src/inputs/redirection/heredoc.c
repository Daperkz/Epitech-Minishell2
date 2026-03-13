/*
** EPITECH PROJECT, 2026
** heredoc.c
** File description:
** heredoc
*/

#include <stdlib.h>
#include <stdio.h>
#include <fcntl.h>

#include "my/string.h"
#include "my/printf.h"

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

int heredoc(shell_t *shell, int i)
{
    int retv = EXIT_SUCCESS;
    char *keyword = shell->input_array[i + 1];
    int tmp_fd = open(REDIR_HEREDOC_TMP_FILE, O_WRONLY | O_CREAT
        | O_TRUNC, 0600);

    if (tmp_fd == -1)
        return (EXIT_FAILURE);
    heredoc_loop(keyword, tmp_fd);
    close(tmp_fd);
    free(shell->input_array[i + 1]);
    shell->input_array[i][1] = '\0';
    shell->input_array[i + 1] = my_strdup(REDIR_HEREDOC_TMP_FILE);
    if (!shell->input_array[i + 1])
        return (EXIT_FAILURE);
    retv = redirect(shell, i);
    return (retv);
}
