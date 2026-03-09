/*
** EPITECH PROJECT, 2025
** my_exp.c
** File description:
** my_exp
*/

#include "my/math.h"

double my_exp(double n)
{
    int k = my_round(n);
    double float_part = n - k;
    double x = 1;
    double xfloat = 1;

    for (int i = 1; i < k; i++)
        x *= E;
    return x + xfloat;
}
