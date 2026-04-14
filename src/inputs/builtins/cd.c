/*
** EPITECH PROJECT, 2026
** cd.c
** File description:
** cd
*/

#include "shell.h"

static int update_wd(shell_t *shell)
{
    char *new_cwd = getcwd(NULL, 0);

    if (!new_cwd)
        return (EXIT_FAILURE);
    free(shell->owd);
    shell->owd = shell->cwd;
    shell->cwd = new_cwd;
    return (EXIT_SUCCESS);
}

static int perform_cd(shell_t *shell, char *dest)
{
    if (chdir(dest) != 0) {
        my_fprintf(STDERR_FD, "%s: %s.\n", dest, strerror(errno));
        shell->last_errno = errno;
        return (EXIT_ACTION_DONE);
    }
    if (update_wd(shell) == EXIT_FAILURE)
        return (EXIT_FAILURE);
    return (EXIT_ACTION_DONE);
}

static int no_arg_case(shell_t *shell)
{
    if (!shell->hwd) {
        my_fprintf(STDERR_FD, "%s\n", "HOME not set");
        return (EXIT_ACTION_DONE);
    }
    return (perform_cd(shell, shell->hwd));
}

static int arg_case(shell_t *shell, char **cmd_args)
{
    char *dest = cmd_args[1];

    if (my_strcmp(dest, "~") == 0)
        return no_arg_case(shell);
    if (my_strcmp(dest, "-") == 0) {
        if (!shell->owd) {
            my_fprintf(STDERR_FD, "%s\n", "cd: OLDPWD not set\n");
            return (EXIT_ACTION_DONE);
        }
        return (perform_cd(shell, shell->owd));
    }
    return (perform_cd(shell, dest));
}

int cd_builtin(shell_t *shell, char **cmd_args)
{
    shell->last_errno = 0;
    if (my_len_str_arr(cmd_args) == 1) {
        return no_arg_case(shell);
    } else if (my_len_str_arr(cmd_args) >= 2)
        return arg_case(shell, cmd_args);
    return (EXIT_ACTION_DONE);
}
