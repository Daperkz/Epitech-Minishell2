/*
** EPITECH PROJECT, 2026
** my_strtrim
** File description:
** my_strtrim
*/

#include <stdlib.h>

#include "my/string.h"

static char *rewrite(char *start, char *str, char *end)
{
    char *dest = start;

    while (str <= end) {
        *dest = *str;
        dest++;
        str++;
    }
    *dest = '\0';
    return (start);
}

char *my_strtrim(char *str, char *seps)
{
    char *start;
    char *end;

    if (!str || !seps)
        return (NULL);
    start = str;
    while (*str && my_strchr(seps, *str))
        str++;
    if (!(*str)) {
        *start = '\0';
        return (start);
    }
    end = str + my_strlen(str) - 1;
    while (end > str && my_strchr(seps, *end))
        end--;
    rewrite(start, str, end);
    return (start);
}
