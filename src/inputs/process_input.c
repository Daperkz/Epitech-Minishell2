/*
** EPITECH PROJECT, 2026
** process_input.c
** File description:
** process_input
*/

#include <stdlib.h>
#include <errno.h>

#include "my/printf.h"
#include "my/string.h"

#include "shell.h"

int exit_mysh(ssize_t nread)
{
    if (nread == -1) {
        if (isatty(STDIN))
            write(STDOUT, "exit\n", 5);
        return (EXIT_SHUTDOWN);
    }
    return (EXIT_SUCCESS);
}

static int single_command(shell_t *shell)
{
    char *program_path = NULL;
    int retv = (EXIT_SUCCESS);

    retv = builtins(shell);
    if (retv == EXIT_FAILURE || retv == EXIT_SHUTDOWN) {
        return (retv);
    } else if (retv == EXIT_ACTION_DONE)
        return (EXIT_SUCCESS);
    program_path = find_command(shell);
    if (program_path == MALLOC_FAIL) {
        return (EXIT_FAILURE);
    } else if (!program_path)
        return (EXIT_SUCCESS);
    retv = execute_command(shell, program_path);
    free(program_path);
    return (EXIT_SUCCESS);
}

static int multiple_commands(shell_t *shell)
{
    int retv = EXIT_SUCCESS;
    int willexit = 0;

    for (int i = 0; shell->commands[i]; i++) {
        shell->input_array = my_str_to_word_array(shell->commands[i],
            BASIC_SEPERATOR);
        if (!shell->input_array)
            return (EXIT_FAILURE);
        retv = single_command(shell);
        my_free_word_array(shell->input_array);
        shell->input_array = NULL;
        shell->input_array_len = 0;
        if (retv == EXIT_SHUTDOWN)
            willexit = 1;
    }
    return (willexit ? EXIT_SHUTDOWN : retv);
}

int process_input(shell_t *shell)
{
    int retv = EXIT_FAILURE;

    if (parse_input(shell) == EXIT_FAILURE)
        return (EXIT_FAILURE);
    if (shell->input_array) {
        retv = single_command(shell);
        my_free_word_array(shell->input_array);
        shell->input_array = NULL;
        shell->input_array_len = 0;
    } else if (!shell->input_array && shell->commands) {
        retv = multiple_commands(shell);
        my_free_word_array(shell->commands);
        shell->commands = NULL;
        shell->nbr_commands = 0;
    }
    return (retv);
}
