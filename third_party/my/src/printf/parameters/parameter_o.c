/*
** EPITECH PROJECT, 2025
** parameter_o
** File description:
** octal parameter
*/

#include <stdarg.h>

#include "my/utils.h"

#include "my_printf_utils.h"
#include "flag_to_func.h"

char *parameter_o(va_list args, cot_err_t *coterr)
{
    unsigned int nb = va_arg(args, unsigned int);
    char *str = my_uitoab(nb, "01234567");

    coterr->count += 0;
    if (!str)
        return NULL;
    return str;
}
