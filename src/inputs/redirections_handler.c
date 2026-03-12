/*
** EPITECH PROJECT, 2026
** REDIRions_handler.c
** File description:
** REDIRions_handler
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
    return !(
        my_strcmp(str, ROT) == 0 || my_strcmp(str, ROAT) == 0 ||
        my_strcmp(str, RIT) == 0 || my_strcmp(str, RHT) == 0
    );
}

static int validity_error(shell_t *shell)
{
    shell->last_errno = 1;
    my_fprintf(STDERR_FD, REDIR_MSSING_NAME_ERR);
    return (EXIT_ACTION_DONE);
}

static int ambiguous_error(shell_t *shell, char *message)
{
    shell->last_errno = 1;
    my_fprintf(STDERR_FD, message);
    return (EXIT_ACTION_DONE);
}

static int file_error(shell_t *shell, char *file)
{
    shell->last_errno = errno;
    my_fprintf(STDERR_FD, "%s: %s.\n", file, strerror(shell->last_errno));
    return (EXIT_ACTION_DONE);
}

static int redirect(shell_t *shell, int i)
{
    char *type = shell->input_array[i];
    char *file = shell->input_array[i + 1];
    int fd = -1;

    if (my_strcmp(type, ROT) == 0)
        fd = open(file, O_WRONLY | O_CREAT | O_TRUNC, 0644);
    else if (my_strcmp(type, ROAT) == 0)
        fd = open(file, O_WRONLY | O_CREAT | O_APPEND, 0644);
    else
        fd = open(file, O_RDONLY);
    if (fd == -1)
        return file_error(shell, file);
    dup2(fd, (type[0] == '<') ? STDIN_FD : STDOUT_FD);
    close(fd);
    shift_array(shell, i);
    return (EXIT_SUCCESS);
}

static int heredoc(shell_t *shell, int i)
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

static int io_check(shell_t *shell, int i, int has_io, char *err)
{
    if (!is_valid(shell->input_array[i + 1]))
        return validity_error(shell);
    if (has_io >= 2) {
        return ambiguous_error(shell, err);
    }
    return (EXIT_SUCCESS);
}

static int check_redirection_errors(shell_t *shell)
{
    char *type = NULL;
    int retv = EXIT_SUCCESS;
    int has_out = 0;
    int has_in = 0;

    for (int i = 0; shell->input_array[i]; i++) {
        type = shell->input_array[i];
        if (my_strcmp(type, ROT) == 0 || my_strcmp(type, ROAT) == 0) {
            has_out++;
            retv = io_check(shell, i, has_out, REDIR_AMBIGUOUS_OUT_ERR);
        }
        if (my_strcmp(type, RIT) == 0 || my_strcmp(type, RHT) == 0) {
            has_in++;
            retv = io_check(shell, i, has_in, REDIR_AMBIGUOUS_IN_ERR);
        }
        if (retv == EXIT_ACTION_DONE)
            return (EXIT_FAILURE);
    }
    return (EXIT_SUCCESS);
}

int handle_redirections(shell_t *shell)
{
    int retv = EXIT_SUCCESS;

    if (check_redirection_errors(shell) == EXIT_FAILURE)
        return (EXIT_ACTION_DONE);
    for (int i = 0; shell->input_array[i]; i++) {
        if (my_strcmp(shell->input_array[i], RHT) == 0) {
            retv = heredoc(shell, i);
            i--;
        }
        if ((my_strcmp(shell->input_array[i], ROT) == 0 ||
                my_strcmp(shell->input_array[i], ROAT) == 0 ||
                my_strcmp(shell->input_array[i], RIT) == 0)) {
            retv = redirect(shell, i);
            i--;
        }
        if (retv == EXIT_FAILURE || retv == EXIT_ACTION_DONE)
            return (retv);
    }
    return (EXIT_SUCCESS);
}
