/*
** EPITECH PROJECT, 2025
** my_strstr
** File description:
** searches for a str in a str
*/

#include "my/string.h"

int my_strstr(char *str, char const *to_find)
{
    int i = 0;
    int pat_size = my_strlen(to_find);
    int limit = my_strlen(str) - pat_size;

    while (i <= limit) {
        if (my_strncmp(&str[i], to_find, pat_size) == 0) {
            return i;
        }
        i++;
    }
    return -1;
}
