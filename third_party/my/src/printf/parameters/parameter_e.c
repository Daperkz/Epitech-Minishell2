/*
** EPITECH PROJECT, 2025
** parameter_e
** File description:
** scientific notation
*/

#include <stdarg.h>

#include "my/utils.h"

#include "my_printf_utils.h"

char *parameter_e(va_list args, cot_err_t *coterr)
{
    double nb = va_arg(args, double);
    char *str = my_put_scientific(nb, "0123456789", 0);

    coterr->count += 0;
    if (!str)
        return NULL;
    return str;
}

char *parameter_ee(va_list args, cot_err_t *coterr)
{
    double nb = va_arg(args, double);
    char *str = my_put_scientific(nb, "0123456789", 1);

    coterr->count += 0;
    if (!str)
        return NULL;
    return str;
}
