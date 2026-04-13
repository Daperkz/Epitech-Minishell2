/*
** EPITECH PROJECT, 2026
** my_str_is_alphanumeric.c
** File description:
** my_str_is_alphanumeric
*/

#include "shell.h"

int my_isletter(char c)
{
    return ((c >= 'a' && c <= 'z') || (c >= 'A' && c <= 'Z'));
}

static int isnum(char c)
{
    return (c >= '0' && c <= '9');
}

int my_str_is_alphanumeric(char *str)
{
    while (*str) {
        if (!my_isletter(*str) && !isnum(*str))
            return 0;
        str++;
    }
    return 1;
}
