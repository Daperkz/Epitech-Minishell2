/*
** EPITECH PROJECT, 2026
** precision.c
** File description:
** precision
*/

#include <stdlib.h>

#include "my/string.h"

#include "internal.h"

static void fill_precision(char *new, int is_neg, int pad)
{
    if (is_neg)
        new[0] = '-';
    for (int i = 0; i < pad; i++)
        new[i + is_neg] = '0';
}

char *apply_precision(char *str, pf_info_t *info, char specifier)
{
    int len = my_strlen(str);
    int is_neg = (str[0] == '-');
    int pad = info->precision - (len - is_neg);
    char *new = NULL;

    if (specifier == 's') {
        if (info->precision < len)
            str[info->precision] = '\0';
        return str;
    }
    if (pad <= 0)
        return str;
    new = malloc(sizeof(char) * (len + pad + 1));
    if (!new)
        return (str);
    fill_precision(new, is_neg, pad);
    my_strcpy(new + pad + is_neg, str + is_neg);
    free(str);
    return (new);
}
