/*
** EPITECH PROJECT, 2025
** my_put_float_hex
** File description:
** prints out a float in hex
*/

#include <stdio.h>
#include <stdlib.h>

#include "my/string.h"
#include "my/utils.h"

#include "floating_point.h"

static char *my_put_mantissa(long x, char *base)
{
    char *str = malloc(sizeof(char) * 14);
    int mantissa_hex_max = 13;

    for (int i = mantissa_hex_max - 1; i >= 0; i--) {
        str[i] = base[x % 16];
        x /= 16;
    }
    str[mantissa_hex_max] = '\0';
    mantissa_hex_max--;
    while (mantissa_hex_max >= 0 && str[mantissa_hex_max] == '0') {
        str[mantissa_hex_max] = '\0';
        mantissa_hex_max--;
    }
    return str;
}

static long extract_mantissa_inbin(double nb, int *power2)
{
    double_t deconstructed_float = {.f = nb};
    unsigned long long bits = deconstructed_float.bits;
    unsigned int exponent = ((bits >> 52) & 0x7FF);
    long mantissa = bits & 0xFFFFFFFFFFFFF;
    int bias = 1023;

    *power2 = exponent - bias;
    return mantissa;
}

static int sign_x_zero_part(double *nb_ptr, char **str_ptr, char last_b_digit)
{
    if ((*nb_ptr) < 0 || 1.0 / (*nb_ptr) < 0.0) {
        if (!my_strappend(str_ptr, "-"))
            *str_ptr = NULL;
        *nb_ptr = -(*nb_ptr);
    }
    if ((*nb_ptr) == 0.0) {
        if (!my_strappend(str_ptr, last_b_digit == 'f' ? "0x0p+0" : "0X0P+0"))
            *str_ptr = NULL;
        return 1;
    }
    if (!my_strappend(str_ptr, last_b_digit == 'f' ? "0x1." : "0X1."))
        *str_ptr = NULL;
    return 0;
}

static char *mantissa_part(
    double *nb_ptr, char **str_ptr, int *power2_ptr, char *base)
{
    long mantissa = extract_mantissa_inbin(*nb_ptr, power2_ptr);
    char *mantissa_str = my_put_mantissa(mantissa, base);

    my_strappend(str_ptr, mantissa_str);
    free(mantissa_str);
    if (!*str_ptr)
        (*str_ptr) = NULL;
    if (!my_strappend(str_ptr, base[15] == 'f' ? "p" : "P"))
        return NULL;
    if (*power2_ptr >= 0) {
        if (!my_strappend(str_ptr, "+"))
            return NULL;
    }
    return (*str_ptr);
}

char *my_put_float_hex(double nb, char *base)
{
    int power2 = 0;
    char *power2_str = NULL;
    char *str = malloc(sizeof(char) * 1);

    str[0] = '\0';
    if (sign_x_zero_part(&nb, &str, base[15]) == 1)
        return str;
    if (!str)
        return NULL;
    mantissa_part(&nb, &str, &power2, base);
    if (!str)
        return NULL;
    power2_str = my_itoab(power2, "0123456789");
    my_strappend(&str, power2_str);
    if (!str)
        return NULL;
    free(power2_str);
    return str;
}
