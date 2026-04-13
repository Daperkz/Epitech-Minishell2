/*
** EPITECH PROJECT, 2026
** get_env_var.c
** File description:
** get_env_var
*/

#include "shell.h"

char *get_env_var(char **env, char *var, int size)
{
    char *path_var = NULL;

    while (env && *env) {
        if (my_strncmp(*env, var, size) == 0) {
            path_var = my_strdup(&(*env)[size]);
            break;
        }
        env++;
    }
    return (path_var);
}
