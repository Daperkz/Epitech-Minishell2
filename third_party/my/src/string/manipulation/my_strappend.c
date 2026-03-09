/*
** EPITECH PROJECT, 2025
** my_strappend.c
** File description:
** my_strappend
*/

#include <unistd.h>
#include <stdlib.h>

#include "my/string.h"

char *my_strappend(char **dest_ptr, char *src)
{
    char *new_dest = NULL;
    char *origin = new_dest;

    if (!dest_ptr)
        return (NULL);
    new_dest = malloc(sizeof(char) *
        (my_strlen((*dest_ptr)) + my_strlen(src) + 1));
    if (!new_dest)
        return (NULL);
    origin = new_dest;
    my_strcpy(new_dest, *dest_ptr);
    free(*dest_ptr);
    my_strcat(new_dest, src);
    (*dest_ptr) = origin;
    return (*dest_ptr);
}
