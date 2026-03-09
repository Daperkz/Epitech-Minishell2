/*
** EPITECH PROJECT, 2025
** my_put_float.c
** File description:
** my_put_float
*/

#include <stdlib.h>

#include "my/io.h"
#include "my/string.h"
#include "my/math.h"

void special_case(double nb)
{
    if (nb == 1.0 / 0.0) {
        my_putstr("inf");
    } else if (nb == -1.0 / 0.0) {
        my_putstr("-inf");
    } else {
        my_putstr("nan");
    }
    return;
}

void my_put_float(double nb, int precision)
{
    int decimal;
    int precision_p10 = my_ipow(10, precision);

    if (nb != nb || nb == 1.0 / 0.0 || nb == -1.0 / 0.0)
        return special_case(nb);
    if (nb < 0 && nb != -0.0) {
        my_putstr("-");
        nb *= -1;
    }
    decimal = (int) ((nb - (int) nb) * precision_p10 + 0.5);
    if (decimal == precision_p10) {
        nb += 1.0;
        decimal = 0;
    }
    my_put_nbr((int) nb);
    my_putstr(".");
    if (decimal < 10)
        my_putstr("0");
    my_put_nbr(decimal);
}
