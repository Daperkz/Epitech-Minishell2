/*
** EPITECH PROJECT, 2026
** my_strrchr.c
** File description:
** my_strrchr
*/

#include <unistd.h>

// returns last occurence of the target char
char *my_strrchr(char *str, char target)
{
    char *last = NULL;

    do {
        if (*str == target) {
            last = str;
        }
        str++;
    } while (*str);
    return last;
}
