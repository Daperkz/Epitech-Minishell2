/*
** EPITECH PROJECT, 2026
** sharp.c
** File description:
** sharp
*/

#include <stdlib.h>

#include "my/string.h"

#include "internal.h"

char *apply_sharp_flag(char *str, char specifier)
{
    char *new;
    int is_zero = (my_strcmp(str, "0") == 0);

    if (specifier == 'o' && str[0] != '0') {
        new = malloc(my_strlen(str) + 2);
        my_strcpy(new, "0");
        my_strcat(new, str);
        free(str);
        return (new);
    }
    if ((specifier == 'x' || specifier == 'X') && !is_zero) {
        new = malloc(my_strlen(str) + 3);
        new[0] = '0';
        new[1] = specifier;
        my_strcpy(new + 2, str);
        free(str);
        return (new);
    }
    return (str);
}
