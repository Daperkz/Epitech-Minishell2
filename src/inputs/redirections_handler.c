/*
** EPITECH PROJECT, 2026
** redirections_handler.c
** File description:
** redirections_handler
*/

#include <fcntl.h>
#include <unistd.h>
#include <stdlib.h>
#include <stdio.h>
#include <string.h>
#include <errno.h>

#include "my/printf.h"
#include "my/string.h"

#include "shell.h"

static void shift_array(shell_t *shell, int index)
{
    free(shell->input_array[index]);
    free(shell->input_array[index + 1]);
    for (int i = index; shell->input_array[i]; i++) {
        shell->input_array[i] = shell->input_array[i + 2];
    }
    shell->input_array_len -= 2;
}

static int is_valid(char *str)
{
    if (!str)
        return 0;
    return !(my_strcmp(str, ">") == 0 || my_strcmp(str, ">>") == 0 ||
        my_strcmp(str, "<") == 0 || my_strcmp(str, "<<") == 0);
}

static int validity_error(shell_t *shell)
{
    shell->last_errno = 1;
    my_fprintf(STDERR, "Missing name for redirect\n");
    return (EXIT_ACTION_DONE);
}

static int file_error(shell_t *shell, char *file)
{
    shell->last_errno = errno;
    my_fprintf(STDERR, "%s: %s.\n", file, strerror(shell->last_errno));
    return (EXIT_ACTION_DONE);
}

static int redirect(shell_t *shell, int i)
{
    char *type = shell->input_array[i];
    char *file = shell->input_array[i + 1];
    int fd = -1;

    if (!is_valid(file))
        return validity_error(shell);
    if (my_strcmp(type, ">") == 0)
        fd = open(file, O_WRONLY | O_CREAT | O_TRUNC, 0644);
    else if (my_strcmp(type, ">>") == 0)
        fd = open(file, O_WRONLY | O_CREAT | O_APPEND, 0644);
    else
        fd = open(file, O_RDONLY);
    if (fd == -1)
        return file_error(shell, file);
    dup2(fd, (type[0] == '<') ? STDIN : STDOUT);
    close(fd);
    shift_array(shell, i);
    return (EXIT_SUCCESS);
}

static int heredoc(shell_t *shell, int i)
{
    if (!is_valid(shell->input_array[i + 1])) {
        return validity_error(shell);
    }
    shift_array(shell, i);
    return (EXIT_SUCCESS);
}

int handle_redirections(shell_t *shell)
{
    int retv = EXIT_SUCCESS;

    for (int i = 0; shell->input_array[i]; i++) {
        if (my_strcmp(shell->input_array[i], "<<") == 0) {
            retv = heredoc(shell, i);
            i--;
        }
        if ((my_strcmp(shell->input_array[i], ">") == 0 ||
                my_strcmp(shell->input_array[i], ">>") == 0 ||
                my_strcmp(shell->input_array[i], "<") == 0)) {
            retv = redirect(shell, i);
            i--;
        }
        if (retv == EXIT_FAILURE || retv == EXIT_ACTION_DONE)
            return (retv);
    }
    return (EXIT_SUCCESS);
}
