/*
** EPITECH PROJECT, 2026
** my_atoi.c
** File description:
** my_atoi
*/

#include "my/math.h"

static int is_num(char c)
{
    return ('0' <= c && c <= '9');
}

static int find_num(char *str)
{
    int i = 0;

    while (str[i] == '-' && !is_num(str[i]) && str[i])
        i++;
    return i;
}

int my_atoi(char *str)
{
    int i;
    int start = find_num(str);
    int result = 0;

    for (i = start; is_num(str[i]); i++) {
        result = ((result * 10) + (str[i] - '0'));
    }
    if (start - 1 < 0)
        return result;
    return (str[start - 1] == '-') ? -result : result;
}

int my_getnbrspe(char *str, int *error_ptr)
{
    int i = 0;
    int start = find_num(str);
    int result = 0;

    for (i = start; is_num(str[i]); i++) {
        result = ((result * 10) + (str[i] - '0'));
    }
    if ((!is_num(str[start]) && str[start] != '-') ||
        (!is_num(str[i]) && str[i])) {
        (*error_ptr) = 1;
    }
    if (str[start - 1] == '-')
        return -result;
    return result;
}
