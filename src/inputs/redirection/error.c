/*
** EPITECH PROJECT, 2026
** error.c
** File description:
** error
*/

#include <string.h>
#include <errno.h>

#include "my/string.h"
#include "my/printf.h"

#include "shell.h"

static int is_valid(char *str)
{
    if (!str)
        return 0;
    return !(
        my_strcmp(str, GRT) == 0 || my_strcmp(str, D_GRT) == 0 ||
        my_strcmp(str, LSR) == 0 || my_strcmp(str, D_LSR) == 0
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

int file_error(shell_t *shell, char *file)
{
    shell->last_errno = errno;
    my_fprintf(STDERR_FD, "%s: %s.\n", file, strerror(shell->last_errno));
    return (EXIT_ACTION_DONE);
}

static int io_check(shell_t *shell, int i, int has_io, char *err)
{
    if (i == 0)
        return (ambiguous_error(shell, REDIR_INVALID_COMMAND));
    if (!is_valid(shell->input_array[i + 1]))
        return validity_error(shell);
    if (has_io >= 2) {
        return ambiguous_error(shell, err);
    }
    return (EXIT_SUCCESS);
}

int check_redirection_errors(shell_t *shell)
{
    char *type = NULL;
    int retv = EXIT_SUCCESS;
    int has_out = 0;
    int has_in = 0;

    for (int i = 0; shell->input_array[i]; i++) {
        type = shell->input_array[i];
        if (my_strcmp(type, GRT) == 0 || my_strcmp(type, D_GRT) == 0) {
            has_out++;
            retv = io_check(shell, i, has_out, REDIR_AMBIGUOUS_OUT_ERR);
        }
        if (my_strcmp(type, LSR) == 0 || my_strcmp(type, D_LSR) == 0) {
            has_in++;
            retv = io_check(shell, i, has_in, REDIR_AMBIGUOUS_IN_ERR);
        }
        if (retv == EXIT_ACTION_DONE)
            return (EXIT_FAILURE);
    }
    return (EXIT_SUCCESS);
}
