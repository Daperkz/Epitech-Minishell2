/*
** EPITECH PROJECT, 2026
** unsetenv.c
** File description:
** unsetenv
*/

#include <stdlib.h>

#include "my/printf.h"
#include "my/string.h"

#include "shell.h"

static int remove_env_var(shell_t *shell, char *var)
{
    int len = my_strlen(var);
    char **env = shell->env;
    int found = 0;
    int i = 0;

    for (i = 0; env && env[i]; i++) {
        if (my_strncmp(env[i], var, len) == 0 && env[i][len] == '=') {
            found = 1;
            break;
        }
    }
    if (found) {
        free(env[i]);
        while (env && env[i + 1]) {
            env[i] = env[i + 1];
            i++;
        }
    }
    env[i] = NULL;
    return (EXIT_SUCCESS);
}

int unsetenv_builtin(shell_t *shell)
{
    int retv = (EXIT_ACTION_DONE);

    if (shell->input_array_len < 2) {
        my_fprintf(STDERR, "unsetenv: Too few arguments.\n");
        shell->last_errno = 1;
        return (EXIT_ACTION_DONE);
    }
    shell->last_errno = 0;
    for (int i = 1; shell->input_array[i]; i++) {
        if (remove_env_var(shell, shell->input_array[i]) == EXIT_FAILURE)
            return (EXIT_FAILURE);
        if (my_strcmp(shell->input_array[i], "PATH") == 0)
            retv = refresh_path(shell);
        if (retv == EXIT_FAILURE)
            return (EXIT_FAILURE);
    }
    return (EXIT_ACTION_DONE);
}
