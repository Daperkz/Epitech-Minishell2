/*
** EPITECH PROJECT, 2026
** signs.c
** File description:
** signs
*/

#include <stdlib.h>

#include "my/string.h"

#include "internal.h"

char *apply_sign_flags(char *str, pf_info_t *info, char specifier)
{
    char *new;
    char sign = (info->plus) ? '+' : ' ';

    if (!my_strchr("difeg", specifier) || str[0] == '-' ||
        (!info->plus && !info->space))
        return (str);
    new = malloc(sizeof(char) * (my_strlen(str) + 2));
    if (!new)
        return (str);
    new[0] = sign;
    my_strcpy(new + 1, str);
    free(str);
    return (new);
}
