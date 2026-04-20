/*
** EPITECH PROJECT, 2026
** is_myshtty
** File description:
** is_myshtty
*/

#include "shell.h"

int is_myshtty(ssize_t nread)
{
    if (nread == -1) {
        if (isatty(STDIN_FD))
            write(STDOUT_FD, "exit\n", 5);
        return (EXIT_SHUTDOWN);
    }
    return (EXIT_SUCCESS);
}
