/*
** EPITECH PROJECT, 2025
** itoab.c
** File description:
** itoab converts an int to an array with the base of choice
*/

#include <stdlib.h>
#include <stdio.h>

#include "my/string.h"

static int intlen(int nb, int base_size)
{
    unsigned int abs_nb = (nb < 0) ?
        (unsigned int)-(nb + 1) + 1 : (unsigned int)nb;
    int len = 0;

    if (nb == 0) {
        return 1;
    } else if (nb < 0) {
        len++;
    }
    while (abs_nb > 0) {
        len++;
        abs_nb /= base_size;
    }
    return len;
}

char *my_itoab(int nb, char *base)
{
    int base_size = my_strlen(base);
    int nblen = intlen(nb, base_size);
    char *str = malloc(sizeof(char) * (nblen + 1));
    unsigned int abs_nb = (nb < 0) ?
        (unsigned int)-(nb + 1) + 1 : (unsigned int)nb;

    if (!str)
        return NULL;
    str[nblen] = '\0';
    if (nb == 0) {
        str[0] = base[0];
        return str;
    } else if (nb < 0)
        str[0] = '-';
    for (int i = nblen - 1; abs_nb > 0; i--) {
        str[i] = base[abs_nb % base_size];
        abs_nb /= base_size;
    }
    return str;
}
