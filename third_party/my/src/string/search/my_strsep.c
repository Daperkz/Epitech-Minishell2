/*
** EPITECH PROJECT, 2026
** my_strsep.c
** File description:
** my_strsep
*/

#include <unistd.h>

static int issep(char c, const char *sep)
{
    while (*sep) {
        if (c == *sep)
            return 1;
        sep++;
    }
    return 0;
}

char *my_strsep(char **str_ptr, const char *sep)
{
    char *str = NULL;
    char *start = NULL;

    if (!str_ptr || !(*str_ptr))
        return (NULL);
    str = (*str_ptr);
    start = str;
    while (*str) {
        if (issep(*str, sep)) {
            *str = '\0';
            (*str_ptr) = str + 1;
            return (start);
        }
        str++;
    }
    *str_ptr = NULL;
    return start;
}
