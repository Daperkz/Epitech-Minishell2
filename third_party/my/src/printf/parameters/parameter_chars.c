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
#include "modifiers.h"

/*
static char *modifier_id_c(char *str, char flag, int x, int id)
{
    switch (id) {
        case 0 :
            return left(str, flag, x);
        case 2 :
            return sign_str(str, flag, x)
        default :
            return str;
    }
}

static int modifier_precision_id_c(va_list args, int x, int id)
{
    switch (id) {
        case 1 :
            return va_arg(args, int);
        default :
            return 0;
    }
}
*/

char *parameter_c(va_list args, pf_ctx_t *coterr)
{
    char c = va_arg(args, int);
    char *str = malloc(sizeof(char) * 2);

    coterr->count += 0;
    if (!str)
        return NULL;
    str[0] = c;
    str[1] = '\0';
    return str;
}

char *parameter_s(va_list args, pf_ctx_t *coterr)
{
    char *str = va_arg(args, char *);
    char *new_str = NULL;

    coterr->count += 0;
    if (str == NULL) {
        new_str = malloc(sizeof(char) * 7);
        if (!new_str)
            return NULL;
        my_strcpy(new_str, "(null)");
    } else {
        new_str = malloc(sizeof(char) * (my_strlen(str) + 1));
        if (!new_str)
            return NULL;
        my_strcpy(new_str, str);
    }
    return new_str;
}

char *parameter_percent(va_list args, pf_ctx_t *coterr)
{
    char *str = malloc(sizeof(char) * 2);

    UNUSED(args);
    coterr->count += 0;
    if (!str)
        return NULL;
    my_strcpy(str, "%");
    return str;
}
