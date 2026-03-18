/*
** EPITECH PROJECT, 2026
** builtins_handler.c
** File description:
** builtins_handler
*/

#include "my/string.h"

#include "shell.h"

int is_builtin(char *cmd)
{
    char **tmp = NULL;
    int retv = 0;

    if (!cmd)
        return 0;
    tmp = my_str_to_str_arr(cmd, BASIC_SEPERATOR);
    if (!tmp || !tmp[0]) {
        my_free_str_arr(tmp);
        return 0;
    }
    retv = (my_strcmp(cmd, CD_INPUT) == 0 ||
        my_strcmp(cmd, SETENV_INPUT) == 0 ||
        my_strcmp(cmd, UNSETENV_INPUT) == 0 ||
        my_strcmp(cmd, ENV_INPUT) == 0 ||
        my_strcmp(cmd, EXIT_INPUT) == 0
    );
    my_free_str_arr(tmp);
    return (retv);
}

int builtins(shell_t *shell)
{
    static const builtin_t builtin_arr[] = {
        {EXIT_INPUT, &exit_builtin}, {CD_INPUT, &cd_builtin},
        {ENV_INPUT, &env_builtin}, {SETENV_INPUT, &setenv_builtin},
        {UNSETENV_INPUT, &unsetenv_builtin},
        {NULL, NULL}
    };

    if (!shell->input_array)
        return (EXIT_ACTION_DONE);
    for (int i = 0; builtin_arr[i].name; i++) {
        if (my_strcmp(shell->input_array[0], builtin_arr[i].name) == 0)
            return (builtin_arr[i].func(shell));
    }
    return (EXIT_SUCCESS);
}
