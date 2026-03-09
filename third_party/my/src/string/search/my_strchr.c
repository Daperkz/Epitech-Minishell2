/*
** EPITECH PROJECT, 2026
** my_strchr.c
** File description:
** my_strchr
*/

#include <unistd.h>

// returns first occurence of the target char
char *my_strchr(char *str, char target)
{
    while (*str) {
        if (*str == target) {
            return str;
        }
        str++;
    }
    return NULL;
}
