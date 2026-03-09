/*
** EPITECH PROJECT, 2025
** my_showstr
** File description:
** prints a string and returns 0. If this string contains non-printable
** characters, they must be printed hexadecimally (in lowercase letters)
** with a backslash before the given value.
*/

#include "my/io.h"

int my_showstr(char const *str)
{
    while (*str) {
        if (*str < 32) {
            my_putchar('\\');
            my_put_nbr_base(*str, "0123456789abcdef");
        } else {
            my_putchar(*str);
        }
        str++;
    }
    return 0;
}
