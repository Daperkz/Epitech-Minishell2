/*
** EPITECH PROJECT, 2026
** sharp.c
** File description:
** sharp
*/

#include <stdlib.h>

#include "my/string.h"

#include "internal.h"

static char *zeropadding_o(char *str)
{
    char *new = malloc(sizeof(char) * (my_strlen(str) + 2));

    if (!new)
        return (NULL);
    my_strcpy(new, "0");
    my_strcat(new, str);
    free(str);
    return (new);
}

static char *zeropadding_x(char *str, char specifier)
{
    char *new = malloc(sizeof(char) * (my_strlen(str) + 3));

    if (!new)
        return (NULL);
    new[0] = '0';
    new[1] = specifier;
    my_strcpy(new + 2, str);
    free(str);
    return (new);
}

char *apply_sharp_flag(char *str, char specifier)
{
    int is_zero = (my_strcmp(str, "0") == 0);

    if (specifier == 'o' && str[0] != '0')
        return zeropadding_o(str);
    if ((specifier == 'x' || specifier == 'X') && !is_zero)
        return zeropadding_x(str, specifier);
    return (str);
}
