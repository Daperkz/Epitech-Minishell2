/*
** EPITECH PROJECT, 2026
** single_command.c
** File description:
** single_command
*/

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
        execute_child(shell, program_path);
        free(program_path);
        return (EXIT_FAILURE);
    }
    retv = execute_command(shell, program_path);
    free(program_path);
    return (retv);
}

static int create_input_array(shell_t *shell, char *command)
{
    shell->input_array = my_str_to_str_arr(command, WHITESPACES);
    if (!shell->input_array)
        return (EXIT_FAILURE);
    shell->input_array_len = my_len_str_arr(shell->input_array);
    if (shell->input_array_len < 1)
        return (EXIT_ACTION_DONE);
    return (EXIT_SUCCESS);
}

static void clean_input_array(shell_t *shell)
{
    my_free_str_arr(shell->input_array);
    shell->input_array = NULL;
    shell->input_array_len = 0;
}

static void restore_fds(int stdout, int stdin)
{
    dup2(stdout, STDOUT_FD);
    dup2(stdin, STDIN_FD);
    close(stdout);
    close(stdin);
}

int command_flow(shell_t *shell, char *command, int is_piped)
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
        return (retv);
    return (not_a_builtin(shell, is_piped));
}

// remove(file); (non authorized function)
static void clean_tmp_files(int size, ...)
{
    va_list list = {0};
    char *file = NULL;

    va_start(list, size);
    for (int i = 0; i < size; i++) {
        file = va_arg(list, char *);
        UNUSED(file);
    }
    va_end(list);
}

int single_command(shell_t *shell, char *command, int is_piped)
{
    int retv = (EXIT_SUCCESS);
    int save_stdout = dup(STDOUT_FD);
    int save_stdin = dup(STDIN_FD);

    retv = command_flow(shell, command, is_piped);
    retv = (retv == EXIT_ACTION_DONE) ? EXIT_SUCCESS : retv;
    clean_input_array(shell);
    restore_fds(save_stdout, save_stdin);
    clean_tmp_files(1, REDIR_HEREDOC_TMP_FILE);
    return (retv);
}
