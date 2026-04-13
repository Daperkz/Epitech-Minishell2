/*
** EPITECH PROJECT, 2026
** my_strstr_unquoted.c
** File description:
** my_strstr_unquoted
*/

#include "shell.h"

char *my_strstr_unquoted(char *str, char *pat)
{
    int m = my_strlen(pat);
    int in_quote = 0;
    char q = 0;

    for (int i = 0; str[i]; i++) {
        if ((str[i] == '\'' || str[i] == '\"') && !in_quote) {
            in_quote = 1;
            q = str[i];
            continue;
        }
        if (in_quote && str[i] == q) {
            in_quote = 0;
            continue;
        }
        if (!in_quote && my_strncmp(&str[i], pat, m) == 0)
            return (&str[i]);
    }
    return (NULL);
}

char *my_strrstr_unquoted(char *str, char *pat)
{
    int m = my_strlen(pat);
    char q = 0;
    int in_quote = 0;
    char *last_match = NULL;

    for (int i = 0; str[i]; i++) {
        if ((str[i] == '\'' || str[i] == '\"') && !in_quote) {
            in_quote = 1;
            q = str[i];
            continue;
        }
        if (in_quote && str[i] == q) {
            in_quote = 0;
            continue;
        }
        if (!in_quote && my_strncmp(&str[i], pat, m) == 0)
            (last_match) = &str[i];
    }
    return (last_match);
}
