/*
** EPITECH PROJECT, 2025
** parameter_f
** File description:
** floats
*/

#include <stdarg.h>

#include "my/utils.h"

#include "my_printf_utils.h"

char *parameter_f(va_list args, cot_err_t *coterr)
{
    double nb = va_arg(args, double);
    char *str = my_ftoa(nb, 6);

    coterr->count += 0;
    if (!str)
        return NULL;
    return str;
}

char *parameter_ff(va_list args, cot_err_t *coterr)
{
    double nb = va_arg(args, double);
    char *str = my_ftoa(nb, 6);

    coterr->count += 0;
    if (!str)
        return NULL;
    return str;
}
