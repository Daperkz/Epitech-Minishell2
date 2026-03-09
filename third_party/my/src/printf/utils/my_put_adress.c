/*
** EPITECH PROJECT, 2025
** mu_put_float_hex_capitalize
** File description:
** prints out a float in hex
*/

#include <unistd.h>
#include <stdio.h>
#include <stdlib.h>

#include "my/string.h"
#include "my/utils.h"

char *my_put_adress(void *a)
{
    unsigned long addr = (unsigned long) a;
    char *str = NULL;
    char *nbr = NULL;

    if (a == NULL) {
        str = malloc(sizeof(char) * 6);
        if (str == NULL)
            return NULL;
        return my_strcpy(str, "(nil)");
    }
    nbr = my_ltoab(addr, "0123456789abcdef");
    str = malloc(sizeof(char) * (2 + my_strlen(nbr) + 1));
    if (str == NULL)
        return NULL;
    my_strcpy(str, "0x");
    my_strcat(str, nbr);
    free(nbr);
    return str;
}
