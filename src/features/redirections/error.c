/*
** EPITECH PROJECT, 2026
** error.c
** File description:
** error
*/

#include "shell.h"

int validity_error(shell_t *shell)
{
    shell->last_errno = 1;
    my_fprintf(STDERR_FD, REDIR_MSSING_NAME_ERR);
    return (EXIT_FAILURE);
}

int ambiguous_error(shell_t *shell, char *message)
{
    shell->last_errno = 1;
    my_fprintf(STDERR_FD, message);
    return (EXIT_FAILURE);
}

int file_error(shell_t *shell, char *file)
{
    shell->last_errno = errno;
    my_fprintf(STDERR_FD, "%s: %s.\n", file, strerror(shell->last_errno));
    return (EXIT_FAILURE);
}
