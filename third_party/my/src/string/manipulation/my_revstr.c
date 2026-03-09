/*
** EPITECH PROJECT, 2025
** my_revstr
** File description:
** reverses a string
*/

#include "my/string.h"

char *my_revstr(char *str)
{
    int size = my_strlen(str);
    int half = (size / 2) + (size % 2);
    int i = 0;
    char temp;

    while (i < half) {
        temp = str[i];
        str[i] = str[size - i];
        str[size - i] = temp;
        i++;
    }
    return str;
}
