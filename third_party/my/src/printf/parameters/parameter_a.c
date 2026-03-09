/*
** EPITECH PROJECT, 2025
** a_parameter
** File description:
** float hex/HEX
*/

#include <stdarg.h>

#include "my/utils.h"

#include "my_printf_utils.h"
#include "flag_to_func.h"

char *parameter_a(va_list args, cot_err_t *coterr)
{
    double x = va_arg(args, double);
    char *str = my_put_float_hex(x, "0123456789abcdef");

    coterr->count += 0;
    if (!str)
        return NULL;
    return str;
}

char *parameter_aa(va_list args, cot_err_t *coterr)
{
    double x = va_arg(args, double);
    char *str = my_put_float_hex(x, "0123456789ABCDEF");

    coterr->count += 0;
    if (!str)
        return NULL;
    return str;
}
