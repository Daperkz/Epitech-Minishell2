/*
** EPITECH PROJECT, 2026
** join_path.c
** File description:
** join_path
*/

#include "shell.h"

char *join_path(char *path, char *command)
{
    int len;
    char *full_path;

    if (!path || !command)
        return NULL;
    len = my_strlen(path) + 1 + my_strlen(command);
    full_path = malloc(sizeof(char) * (len + 1));
    if (!full_path)
        return NULL;
    my_strcpy(full_path, path);
    my_strcat(full_path, "/");
    my_strcat(full_path, command);
    return full_path;
}
