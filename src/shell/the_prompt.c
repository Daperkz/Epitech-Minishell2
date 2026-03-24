/*
** EPITECH PROJECT, 2026
** the_prompt.c
** File description:
** the_prompt
*/

#include "my/printf.h"
#include "my/string.h"

#include "shell.h"

void print_the_prompt(shell_t *shell)
{
    if (!isatty(STDIN_FD))
        return;
    if (shell->last_errno == 0) {
        my_fprintf(
            STDOUT_FD,
            "%s➜%s  %s%s%s %s",
            ZSH_NOERR_COLOR, COLOR_RESET,
            ZSH_CWD_COLOR, my_strrchr(shell->cwd, '/') + 1, COLOR_RESET,
            THE_PROMPT
        );
    } else {
        my_fprintf(
            STDOUT_FD,
            "%s[%d] ➜%s  %s%s%s %s",
            ZSH_ERR_COLOR, shell->last_errno, COLOR_RESET,
            ZSH_CWD_COLOR, my_strrchr(shell->cwd, '/') + 1, COLOR_RESET,
            THE_PROMPT
        );
    }
}
