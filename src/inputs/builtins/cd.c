/*
** EPITECH PROJECT, 2026
** cd.c
** File description:
** cd
*/

#include <stdlib.h>
#include <errno.h>
#include <string.h>

#include "my/printf.h"
#include "my/string.h"

#include "shell.h"

static int update_wd(shell_t *shell)
{
    free(shell->owd);
    shell->owd = shell->cwd;
    shell->cwd = getcwd(NULL, 0);
    if (!shell->cwd)
        return (EXIT_FAILURE);
    return (EXIT_SUCCESS);
}

static int perform_cd(shell_t *shell, char *dest)
{
    if (chdir(dest) != 0) {
        my_fprintf(STDERR, "%s: %s.\n", dest, strerror(errno));
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
        my_fprintf(STDERR, "%s\n", "HOME not set");
        return (EXIT_ACTION_DONE);
    }
    return perform_cd(shell, shell->hwd);
}

static int arg_case(shell_t *shell)
{
    char *dest = shell->input_array[1];

    if (my_strcmp(dest, "~") == 0)
        return no_arg_case(shell);
    if (my_strcmp(dest, "-") == 0) {
        if (!shell->owd) {
            my_fprintf(STDERR, "%s\n", "cd: OLDPWD not set\n");
            return (EXIT_ACTION_DONE);
        }
        my_printf("%s\n", shell->owd);
        return perform_cd(shell, shell->owd);
    }
    return perform_cd(shell, dest);
}

int cd_builtin(shell_t *shell)
{
    shell->last_errno = 0;
    if (shell->input_array_len == 1) {
        return no_arg_case(shell);
    } else if (shell->input_array_len >= 2)
        return arg_case(shell);
    return (EXIT_ACTION_DONE);
}
