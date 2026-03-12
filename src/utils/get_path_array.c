/*
** EPITECH PROJECT, 2026
** get_path_array.c
** File description:
** get_path_array
*/

#include "my/string.h"

#include "shell.h"

char **get_path_array(char **env)
{
    char **path_arr = NULL;
    char *path_var = NULL;

    while (env && *env) {
        if (my_strncmp(*env, ENV_VAR_PATH, ENV_VAR_PATH_SIZE) == 0) {
            path_var = &(*env)[ENV_VAR_PATH_SIZE];
            break;
        }
        env++;
    }
    if (!path_var)
        return (NULL);
    path_arr = my_str_to_str_arr(path_var, ":");
    if (!path_arr)
        return (char **)-1;
    return (path_arr);
}
