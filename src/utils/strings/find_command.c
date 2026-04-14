/*
** EPITECH PROJECT, 2026
** find_command.c
** File description:
** find_command
*/

#include "shell.h"

// checks if the pathed_input : 1.exists -> 2.permission to execute.
static char *get_direct_path(shell_t *shell, char *cmd)
{
    if (access(cmd, F_OK) != 0) {
        shell->last_errno = 1;
        my_fprintf(STDERR_FD, "%s: Command not found.\n", cmd);
        return (NULL);
    }
    if (access(cmd, X_OK) == 0)
        return my_strdup(cmd);
    my_fprintf(STDERR_FD, "%s: Permission denied.\n", cmd);
    return (NULL);
}

char *find_command(shell_t *shell, char **cmd_args)
{
    char *cmd = cmd_args[0];
    char *path = NULL;

    if (my_strchr(cmd, '/'))
        return get_direct_path(shell, cmd);
    for (int i = 0; shell->path_arr && shell->path_arr[i]; i++) {
        path = join_path(shell->path_arr[i], cmd);
        if (!path)
            return (MALLOC_FAIL);
        if (access(path, X_OK) == 0)
            return path;
        free(path);
    }
    shell->last_errno = EPERM;
    my_fprintf(STDERR_FD, "%s: Command not found.\n", shell->input_array[0]);
    return (NULL);
}
