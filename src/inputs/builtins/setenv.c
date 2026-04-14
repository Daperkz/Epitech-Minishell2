/*
** EPITECH PROJECT, 2026
** setenv.c
** File description:
** setenv
*/

#include "shell.h"

static char *create_var(char *name, char *value)
{
    int len = my_strlen(name) + my_strlen(value) + 2;
    char *new_entry = malloc(sizeof(char) * len);

    if (!new_entry)
        return (NULL);
    my_strcpy(new_entry, name);
    my_strcat(new_entry, "=");
    my_strcat(new_entry, value);
    return (new_entry);
}

static int update_existing_var(shell_t *shell, char *name, char *value, int i)
{
    char *new_entry = create_var(name, value);

    if (!new_entry)
        return (EXIT_FAILURE);
    free(shell->env[i]);
    shell->env[i] = new_entry;
    return (my_strcmp(name, "PATH") == 0) ?
        refresh_path(shell) : (EXIT_ACTION_DONE);
}

static int add_new_var(shell_t *shell, char *name, char *value)
{
    char **cur_env = shell->env;
    char **new_env = malloc(sizeof(char *) * (my_len_str_arr(cur_env) + 2));
    int i = 0;

    if (!new_env)
        return (EXIT_FAILURE);
    while (cur_env[i]) {
        new_env[i] = cur_env[i],
        i++;
    }
    free(cur_env);
    new_env[i] = create_var(name, value);
    i++;
    new_env[i] = NULL;
    shell->env = new_env;
    return (my_strcmp(name, "PATH") == 0) ?
        refresh_path(shell) : (EXIT_ACTION_DONE);
}

static int new_pathenv(shell_t *shell, char *name, char *value)
{
    int name_len = my_strlen(name);

    for (int i = 0; shell->env && shell->env[i]; i++) {
        if (my_strncmp(shell->env[i], name, name_len) == 0 &&
            shell->env[i][name_len] == '=') {
            return (update_existing_var(shell, name, value, i));
        }
    }
    return (add_new_var(shell, name, value));
}

static int error_case(char *env_name)
{
    if (!my_isletter(env_name[0])) {
        my_fprintf(STDERR_FD,
            "setenv: Variable name must begin with a letter.\n");
        return (EXIT_FAILURE);
    }
    if (!my_str_is_alphanumeric(env_name)) {
        my_fprintf(STDERR_FD,
            "setenv: Variable name must contain alphanumeric characters.\n");
        return (EXIT_FAILURE);
    }
    return (EXIT_SUCCESS);
}

int setenv_builtin(shell_t *shell, char **cmd_args)
{
    char *env_name = cmd_args[1];
    char *env_value = (my_len_str_arr(cmd_args) == 3) ?
        cmd_args[2] : "";

    shell->last_errno = 0;
    if (my_len_str_arr(cmd_args) == 1) {
        my_put_str_arr(shell->env, '\n');
        return (EXIT_ACTION_DONE);
    } else if (my_len_str_arr(cmd_args) > 3) {
        shell->last_errno = EINVAL;
        my_fprintf(STDERR_FD, "setenv: Too many arguments.\n");
        return (EXIT_ACTION_DONE);
    }
    if (error_case(env_name) == (EXIT_FAILURE)) {
        shell->last_errno = EINVAL;
        return (EXIT_ACTION_DONE);
    }
    return (new_pathenv(shell, env_name, env_value));
}
