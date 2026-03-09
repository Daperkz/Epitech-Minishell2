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
    char *new_dest = malloc(sizeof(char) *
        (my_strlen((*dest_ptr)) + my_strlen(src) + 1));
    char *origin = new_dest;
    char *parse_dest = *dest_ptr;

    if (!new_dest)
        return NULL;
    my_strcpy(new_dest, parse_dest);
    free(*dest_ptr);
    my_strcat(new_dest, src);
    (*dest_ptr) = origin;
    return (*dest_ptr);
}
