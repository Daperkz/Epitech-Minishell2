/*
** EPITECH PROJECT, 2025
** printf
** File description:
** printf
*/

#include <stdlib.h>

#include "my/string.h"
#include "my/utils.h"

static char *put_exponent(char **str_ptr, int exponent, char *base, int cap)
{
    char *exponent_str = NULL;

    if (!my_strappend(str_ptr, cap ? "E" : "e"))
        return NULL;
    if (exponent >= 0) {
        if (!my_strappend(str_ptr, "+"))
            return NULL;
    } else {
        if (!my_strappend(str_ptr, "-"))
            return NULL;
        exponent = -exponent;
    }
    if (exponent < 10)
        if (!my_strappend(str_ptr, "0"))
            return NULL;
    exponent_str = my_itoab(exponent, base);
    my_strappend(str_ptr, exponent_str);
    free(exponent_str);
    return (*str_ptr);
}

static char *put_decimal(char **str_ptr, int decimal, char *base)
{
    int limit = 10000;
    char *decimal_str;

    while (limit > 0 && decimal < limit) {
        my_strappend(str_ptr, "0");
        if (!(*str_ptr))
            return NULL;
        limit /= 10;
    }
    decimal_str = my_itoab(decimal, base);
    if (!decimal_str)
        return NULL;
    my_strappend(str_ptr, decimal_str);
    if (!(*str_ptr))
        return NULL;
    free(decimal_str);
    return *str_ptr;
}

static void calculate_scientific(
    double nb, int *exponent_ptr, int *entier_ptr, int *decimal_ptr
)
{
    *exponent_ptr = 0;
    while (nb >= 10.0) {
        nb /= 10.0;
        (*exponent_ptr)++;
    }
    while (nb < 1.0) {
        nb *= 10.0;
        (*exponent_ptr)--;
    }
    *entier_ptr = (int)nb;
    *decimal_ptr = (int)((nb - *entier_ptr) * 1000000 + 0.00005);
}

static char *special_case(double nb)
{
    char *str;

    if (nb == 1.0 / 0.0) {
        str = malloc(sizeof(char) * 4);
        return (!str) ? NULL : my_strcpy(str, "inf");
    } else if (nb == -1.0 / 0.0) {
        str = malloc(sizeof(char) * 5);
        return (!str) ? NULL : my_strcpy(str, "-inf");
    } else {
        str = malloc(sizeof(char) * 4);
        return (!str) ? NULL : my_strcpy(str, "nan");
    }
    return str;
}

static char *int_and_decimal_part(
    char **str_ptr, int entier, int decimal, char *base)
{
    char *entier_str = my_itoab(entier, base);

    if (!entier_str)
        return NULL;
    my_strappend(str_ptr, entier_str);
    free(entier_str);
    if (!(*str_ptr))
        return NULL;
    if (!my_strappend(str_ptr, "."))
        return NULL;
    if (!put_decimal(str_ptr, decimal, base))
        return NULL;
    return (*str_ptr);
}

static char *sign_part(char **str_ptr, double *nb_ptr)
{
    if ((*nb_ptr) < 0) {
        if (!my_strappend(str_ptr, "-"))
            return NULL;
        (*nb_ptr) = -(*nb_ptr);
    }
    return *(str_ptr);
}

char *my_put_scientific(double nb, char *base, int cap)
{
    int exponent = 0;
    int entier = 0;
    int decimal = 0;
    char *str;

    if (nb != nb || nb == 1.0 / 0.0 || nb == -1.0 / 0.0)
        return special_case(nb);
    str = malloc(sizeof(char) * 1);
    str[0] = '\0';
    if (nb == 0.0)
        return my_strappend(&str, cap ? "0.000000E+00" : "0.000000e+00");
    if (!sign_part(&str, &nb))
        return NULL;
    calculate_scientific(nb, &exponent, &entier, &decimal);
    if (!int_and_decimal_part(&str, entier, decimal, base))
        return NULL;
    if (!put_exponent(&str, exponent, base, cap))
        return NULL;
    return str;
}
