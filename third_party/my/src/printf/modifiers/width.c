/*
** EPITECH PROJECT, 2026
** width.c
** File description:
** width
*/

#include <stdlib.h>

#include "my/string.h"

#include "internal.h"

static void fill_padding(char *new, char *str, pf_info_t *info, int pad)
{
    int len = my_strlen(str);
    int is_neg = (str[0] == '-' && info->zero && !info->left);
    char c = (info->zero && !info->left) ? '0' : ' ';

    if (info->left) {
        my_strcpy(new, str);
        for (int i = len; i < info->width; i++)
            new[i] = ' ';
    } else {
        if (is_neg)
            new[0] = '-';
        for (int i = 0; i < pad; i++)
            new[i + is_neg] = c;
        my_strcpy(new + pad + is_neg, str + is_neg);
    }
}

char *apply_width(char *str, pf_info_t *info)
{
    int len = my_strlen(str);
    int pad = info->width - len;
    char *new = NULL;

    if (pad <= 0)
        return str;
    new = malloc(sizeof(char) * (info->width + 1));
    if (!new)
        return str;
    fill_padding(new, str, info, pad);
    new[info->width] = '\0';
    free(str);
    return (new);
}
