/*
** EPITECH PROJECT, 2026
** builtins_handler.c
** File description:
** builtins_handler
*/

#include "shell.h"

const builtin_t BUILTINS[] = {
    {EXIT_INPUT, exit_builtin},
    {CD_INPUT, cd_builtin},
    {ENV_INPUT, env_builtin},
    {SETENV_INPUT, setenv_builtin},
    {UNSETENV_INPUT, unsetenv_builtin},
    {NULL, NULL}
};

int is_builtin(char *cmd)
{
    char **tmp = NULL;
    int retv = 0;

    if (!cmd)
        return 0;
    tmp = my_str_to_str_arr(cmd, WHITESPACES);
    if (!tmp || !tmp[0]) {
        my_free_str_arr(tmp);
        return 0;
    }
    retv = (my_strcmp(tmp[0], CD_INPUT) == 0 ||
        my_strcmp(tmp[0], SETENV_INPUT) == 0 ||
        my_strcmp(tmp[0], UNSETENV_INPUT) == 0 ||
        my_strcmp(tmp[0], ENV_INPUT) == 0 ||
        my_strcmp(tmp[0], EXIT_INPUT) == 0
    );
    my_free_str_arr(tmp);
    return (retv);
}

int builtins(shell_t *shell, char **cmd_args)
{
    const builtin_t *builtin_arr = BUILTINS;

    if (!cmd_args || !(*cmd_args))
        return (EXIT_ACTION_DONE);
    for (int i = 0; builtin_arr[i].name; i++) {
        if (my_strcmp(cmd_args[0], builtin_arr[i].name) == 0)
            return (builtin_arr[i].func(shell, cmd_args));
    }
    return (EXIT_SUCCESS);
}
