/*
** EPITECH PROJECT, 2026
** single_command.c
** File description:
** single_command
*/

#include <stdlib.h>

#include <my/printf.h>
#include <my/string.h>

#include "shell.h"

static int not_a_builtin(shell_t *shell, int is_piped)
{
    int retv = (EXIT_SUCCESS);
    char *program_path = find_command(shell);

    if (program_path == MALLOC_FAIL) {
        return (EXIT_FAILURE);
    } else if (!program_path)
        return (EXIT_SUCCESS);
    if (is_piped) {
        retv = execute_child(shell, program_path);
        free(program_path);
        return (EXIT_FAILURE);
    }
    retv = execute_command(shell, program_path);
    free(program_path);
    return (retv);
}

static int create_input_array(shell_t *shell, char *command)
{
    shell->input_array = my_str_to_word_array(command, BASIC_SEPERATOR);
    if (!shell->input_array)
        return (EXIT_FAILURE);
    shell->input_array_len = my_word_array_len(shell->input_array);
    if (shell->input_array_len < 1)
        return (EXIT_ACTION_DONE);
    return (EXIT_SUCCESS);
}

static void clean_input_array(shell_t *shell)
{
    my_free_word_array(shell->input_array);
    shell->input_array = NULL;
    shell->input_array_len = 0;
}

static void restore_fds(int stdout, int stdin)
{
    dup2(stdout, STDOUT_FILENO);
    dup2(stdin, STDIN_FILENO);
    close(stdout);
    close(stdin);
}

static int command_flow(shell_t *shell, char *command, int is_piped)
{
    int retv = (EXIT_SUCCESS);

    retv = create_input_array(shell, command);
    if (retv == EXIT_FAILURE || retv == EXIT_ACTION_DONE)
        return (retv);
    retv = handle_redirections(shell);
    if (retv == EXIT_FAILURE || retv == EXIT_ACTION_DONE)
        return (retv);
    retv = builtins(shell);
    if (retv == EXIT_FAILURE || retv == EXIT_SHUTDOWN ||
        retv == EXIT_ACTION_DONE)
        return retv;
    return not_a_builtin(shell, is_piped);
}

int single_command(shell_t *shell, char *command, int is_piped)
{
    int retv = (EXIT_SUCCESS);
    int save_stdout = dup(STDOUT);
    int save_stdin = dup(STDIN);

    retv = command_flow(shell, command, is_piped);
    clean_input_array(shell);
    restore_fds(save_stdout, save_stdin);
    return (retv == EXIT_ACTION_DONE ? EXIT_SUCCESS : retv);
}
