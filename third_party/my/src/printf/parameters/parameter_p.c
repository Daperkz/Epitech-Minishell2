/*
** EPITECH PROJECT, 2025
** parameter_p
** File description:
** pointer
*/

#include <stdarg.h>

#include "my/utils.h"

#include "my_printf_utils.h"

char *parameter_p(va_list args, cot_err_t *coterr)
{
    void *p = va_arg(args, void *);
    char *str = my_put_adress(p);

    coterr->count += 0;
    if (!str)
        return NULL;
    return str;
}
