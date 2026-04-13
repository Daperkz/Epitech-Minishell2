/*
** EPITECH PROJECT, 2026
** the_prompt.c
** File description:
** the_prompt
*/

#include "shell.h"

static void normal_prompt(shell_t *shell)
{
    char *dir = my_strrchr(shell->cwd, '/') + 1;

    if (!(*dir))
        dir--;
    my_fprintf(
        STDOUT_FD,
        "%s➜%s  %s%s%s %s",
        ZSH_NOERR_COLOR, COLOR_RESET,
        ZSH_CWD_COLOR, dir, COLOR_RESET,
        THE_PROMPT
    );
}

static void error_prompt(shell_t *shell)
{
    char *dir = my_strrchr(shell->cwd, '/') + 1;

    if (!(*dir))
        dir--;
    my_fprintf(
        STDOUT_FD,
        "%s[%d] ➜%s  %s%s%s %s",
        ZSH_ERR_COLOR, shell->last_errno, COLOR_RESET,
        ZSH_CWD_COLOR, dir, COLOR_RESET,
        THE_PROMPT
    );
}

void print_the_prompt(shell_t *shell)
{
    if (!isatty(STDIN_FD))
        return;
    if (shell->last_errno == 0) {
        normal_prompt(shell);
    } else {
        error_prompt(shell);
    }
}
