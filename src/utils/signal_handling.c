/*
** EPITECH PROJECT, 2026
** signal_handling.c
** File description:
** signal_handling
*/

#include "shell.h"

void handle_sigint(int sig)
{
    (void)sig;
    write(STDOUT_FILENO, "\n", 1);
    write(STDOUT_FILENO, THE_PROMPT, THE_PROMPT_SIZE);
}

void handle_child_status(shell_t *shell, int status)
{
    int sig = 0;

    if (WIFEXITED(status)) {
        shell->last_errno = WEXITSTATUS(status);
        return;
    }
    if (WIFSIGNALED(status)) {
        sig = WTERMSIG(status);
        if (sig == SIGSEGV)
            my_fprintf(STDERR_FD, "Segmentation fault");
        if (sig == SIGFPE)
            my_fprintf(STDERR_FD, "Floating exception");
        if (WCOREDUMP(status))
            my_fprintf(STDERR_FD, " (core dumped)");
        my_fprintf(STDERR_FD, "\n");
        shell->last_errno = 128 + sig;
    }
}
