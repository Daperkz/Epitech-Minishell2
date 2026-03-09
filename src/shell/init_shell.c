/*
** EPITECH PROJECT, 2026
** init_shell.c
** File description:
** init_shell
*/

#include <unistd.h>
#include <signal.h>

#include "my/string.h"

#include "shell.h"

static char *getowd(char **env, char *cwd)
{
    char *path_var = NULL;

    path_var = get_env_var(env, ENV_VAR_OLDPWD, ENV_VAR_OLDPWD_SIZE);
    if ((!env || !*env) || !path_var)
        path_var = my_strdup(cwd);
    return (path_var);
}

static int internal_shell(shell_t *shell, char **env)
{
    shell->last_errno = 0;
    shell->env = my_copy_word_array(env);
    if (shell->env == MALLOC_FAIL)
        return (EXIT_FAILURE);
    shell->path_arr = get_path_array(shell->env);
    if (shell->path_arr == MALLOC_FAIL)
        return (EXIT_FAILURE);
    shell->cwd = getcwd(NULL, 0);
    if (!shell->cwd)
        return (EXIT_FAILURE);
    shell->owd = getowd(shell->env, shell->cwd);
    if (!shell->owd)
        return (EXIT_FAILURE);
    shell->hwd = get_env_var(shell->env, ENV_VAR_ZDOTDIR, ENV_VAR_ZDOTDIR_SIZE);
    shell->pid = getpid();
    shell->child = 0;
    signal(SIGINT, handle_sigint);
    return (EXIT_SUCCESS);
}

static int external_shell(shell_t *shell)
{
    shell->input = NULL;
    shell->input_len = 0;
    shell->input_array = NULL;
    shell->input_array_len = 0;
    return (EXIT_SUCCESS);
}

int init_shell(shell_t *shell, char **env)
{
    if (internal_shell(shell, env) == EXIT_FAILURE)
        return (EXIT_FAILURE);
    if (external_shell(shell) == EXIT_FAILURE)
        return (EXIT_FAILURE);
    return (EXIT_SUCCESS);
}
