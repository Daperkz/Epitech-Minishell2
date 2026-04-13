/*
** EPITECH PROJECT, 2026
** REDIRions_handler.c
** File description:
** REDIRions_handler
*/

#include "shell.h"

int handle_redirections(shell_t *shell)
{
    int retv = EXIT_SUCCESS;

    if (check_redirection_errors(shell) == EXIT_FAILURE)
        return (EXIT_ACTION_DONE);
    for (int i = 0; shell->input_array[i]; i++) {
        if (my_strcmp(shell->input_array[i], DLSR) == 0) {
            retv = heredoc(shell, i);
            i--;
        }
        if ((my_strcmp(shell->input_array[i], GRT) == 0 ||
                my_strcmp(shell->input_array[i], DGRT) == 0 ||
                my_strcmp(shell->input_array[i], LSR) == 0)) {
            retv = redirect(shell, i);
            i--;
        }
        if (retv == EXIT_FAILURE || retv == EXIT_ACTION_DONE)
            return (retv);
    }
    return (EXIT_SUCCESS);
}
