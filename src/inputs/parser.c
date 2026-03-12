/*
** EPITECH PROJECT, 2026
** parser.c
** File description:
** parser
*/

#include "my/string.h"

#include "shell.h"

static void strip_endline(char *str)
{
    int i = 0;

    if (!str)
        return;
    while (str[i])
        i++;
    if (i > 0 && str[i - 1] == '\n')
        str[i - 1] = '\0';
}

int parse_input(shell_t *shell)
{
    strip_endline(shell->input);
    if (!shell->input[0])
        return (EXIT_SUCCESS);
    if (tilde_expansion(&shell->input, shell->hwd) == EXIT_FAILURE)
        return (EXIT_FAILURE);
    if (my_strchr(shell->input, *COMMAND_SEPERATOR)) {
        shell->commands = my_str_to_str_arr(shell->input, COMMAND_SEPERATOR);
        return (!shell->commands) ? (EXIT_FAILURE) : (EXIT_SUCCESS);
    }
    return (EXIT_SUCCESS);
}
