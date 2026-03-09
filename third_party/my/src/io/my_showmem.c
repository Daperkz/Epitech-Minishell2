/*
** EPITECH PROJECT, 2025
** my_showmem.c
** File description:
** prints a memory dump and return 0.
** Each line of the output manages 16 characters and is divided into 3 columns:
** The hexadecimal address of the line's first character,
** the content in hexadecimal,
** the content in printable characters.
** 00000000: 6865 7920 6775 7973 2073 686f 7720 6d65 hey guys show me$
** 00000010: 6d20 6973 2063 6f6f 6c20 796f 7520 6361 m is cool you ca$
** 00000020: 6e20 646f 2073 6f6d 6520 7072 6574 7479 n do some pretty$
** 00000030: 206e 6561 7420 7374 7566 6600 0f1b 7f05  neat stuff.....$
** 00000040: 2e00 0102 0304 0506 0708 090e 0f1b 7f    ...............$
*/

#include "my/string.h"
#include "my/utils.h"

int my_showmem(char const *str, int size)
{
    UNUSED(str);
    UNUSED(size);
    return 0;
}
