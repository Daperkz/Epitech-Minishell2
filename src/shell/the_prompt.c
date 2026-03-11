/*
** EPITECH PROJECT, 2026
** the_prompt.c
** File description:
** the_prompt
*/

#include "my/printf.h"

#include "shell.h"

void print_the_prompt(shell_t *shell)
{
    if (!isatty(STDIN))
        return;
    if (shell->last_errno == 0) {
        my_fprintf(
            STDOUT_FILENO,
            "%s",
            THE_PROMPT
        );
    } else {
        my_fprintf(
            STDOUT_FILENO,
            "%s[%d]%s %s",
            ZSH_RED, shell->last_errno, COLOR_RESET, THE_PROMPT
        );
    }
}
