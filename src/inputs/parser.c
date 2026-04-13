/*
** EPITECH PROJECT, 2026
** parser.c
** File description:
** parser
*/

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

//, char *pairs (, "\"\"''{}()[]");
static int validate_pairs(shell_t *shell, char *input)
{
    char quote_type = 0;

    for (int i = 0; input[i]; i++) {
        if (quote_type == 0) {
            quote_type = (input[i] == '"' || input[i] == '\'') ? input[i] : 0;
        } else {
            quote_type = (input[i] == quote_type) ? 0 : quote_type;
        }
    }
    if (quote_type != 0) {
        shell->last_errno = 1;
        my_fprintf(STDERR_FD, "Unmatched '%c'.\n", quote_type);
        return (EXIT_ACTION_DONE);
    }
    return (EXIT_SUCCESS);
}

int parse_input(shell_t *shell)
{
    strip_endline(shell->input);
    if (!shell->input[0])
        return (EXIT_SUCCESS);
    if (tilde_expansion(&shell->input, shell->hwd) == EXIT_FAILURE)
        return (EXIT_FAILURE);
    if (validate_pairs(shell, shell->input) == EXIT_ACTION_DONE)
        return (EXIT_ACTION_DONE);
    if (my_strchr(shell->input, *COMMAND_SEPERATOR)) {
        shell->commands = my_str_to_str_arr(shell->input, COMMAND_SEPERATOR);
        return (!shell->commands) ? (EXIT_FAILURE) : (EXIT_SUCCESS);
    }
    return (EXIT_SUCCESS);
}
