/*
** EPITECH PROJECT, 2025
** printf
** File description:
** printf
*/

#include <stdarg.h>

#include "my/string.h"
#include "my/utils.h"

#include "internal.h"

char *parameter_n(va_list args, pf_ctx_t *coterr)
{
    int *x = va_arg(args, int *);
    char *str = malloc(sizeof(char) * 1);

    *x = coterr->count;
    if (!str)
        return NULL;
    my_strcpy(str, "");
    return str;
}
