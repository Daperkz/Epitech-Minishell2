/*
** EPITECH PROJECT, 2026
** my_put_str_arr.c
** File description:
** my_put_str_arr
*/

#include "my/io.h"
#include "my/string.h"

void my_put_str_arr(char **str_arr, char sep)
{
    while (*str_arr) {
        my_putstr(*str_arr);
        my_putchar(sep);
        str_arr++;
    }
}
