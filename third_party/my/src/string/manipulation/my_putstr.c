/*
** EPITECH PROJECT, 2025
** my_putstr
** File description:
** displays, one-by-one, the characters of a string
*/

#include <unistd.h>

#include "my/string.h"

int my_putstr(char const *str)
{
    return write(1, str, my_strlen(str));
}

int my_fputstr(int fd, char const *str)
{
    return write(fd, str, my_strlen(str));
}
