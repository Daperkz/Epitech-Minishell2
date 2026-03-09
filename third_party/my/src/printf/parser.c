/*
** EPITECH PROJECT, 2026
** parser.c
** File description:
** parser
*/

#include <stdlib.h>

#include "my/string.h"

#include "internal.h"
#include "modifiers.h"
#include "all_parameters.h"

static int my_isdigit(char c)
{
    return (c >= '0' && c <= '9');
}

int my_getnbr_and_advance(const char *str, int *i)
{
    int res = 0;

    while (my_isdigit(str[*i])) {
        res = res * 10 + (str[*i] - '0');
        (*i)++;
    }
    return (res);
}

static int parse_width_precision(
    const char *format, pf_info_t *info, va_list args
)
{
    int i = 0;

    if (format[i] == '*') {
        info->width = va_arg(args, int);
        i++;
    } else if (my_isdigit(format[i])) {
        info->width = my_getnbr_and_advance(format, &i);
    }
    if (format[i] == '.') {
        i++;
        if (format[i] == '*') {
            info->precision = va_arg(args, int);
            i++;
        } else {
            info->precision = my_getnbr_and_advance(format, &i);
        }
    }
    return (i);
}

static int parse_info(const char *format, pf_info_t *info, va_list args)
{
    int i = 0;

    *info = (pf_info_t){0, -1, 0, 0, 0, 0, 0, 0};
    while (format[i] && my_strchr("-+ #0", format[i])) {
        if (format[i] == '-')
            info->left = 1;
        if (format[i] == '+')
            info->plus = 1;
        if (format[i] == ' ')
            info->space = 1;
        if (format[i] == '#')
            info->sharp = 1;
        if (format[i] == '0')
            info->zero = 1;
        i++;
    }
    i += parse_width_precision(format + i, info, args);
    return (i);
}

static int printf_or_sprintf(pf_ctx_t *ctx, char *res, char **str_ptr)
{
    int written;

    if (ctx->fd != -1) {
        written = my_putstr_fd(ctx->fd, res);
        ctx->count += (written != -1) ? written : 0;
        ctx->error = (written == -1);
    } else {
        if (!my_strappend(str_ptr, res))
            return (EXIT_FAILURE);
        ctx->count += my_strlen(res);
    }
    return (EXIT_SUCCESS);
}

static int post_processing(pf_info_t *info, char **res_ptr, char specifier)
{
    if (!*res_ptr)
        return (EXIT_FAILURE);
    if (info->precision != -1)
        *res_ptr = apply_precision(*res_ptr, info, specifier);
    if (info->sharp)
        *res_ptr = apply_sharp_flag(*res_ptr, specifier);
    if (info->plus || info->space)
        *res_ptr = apply_sign_flags(*res_ptr, info, specifier);
    if (info->width > 0)
        *res_ptr = apply_width(*res_ptr, info);
    return (EXIT_SUCCESS);
}

int handle_conversion(
    pf_ctx_t *ctx, const char *format, va_list args, char **str_ptr)
{
    pf_info_t info;
    int offset = parse_info(format, &info, args);
    char specifier = format[offset];
    char *res = NULL;

    for (int i = 0; ALL_FORMAT[i]->flag != 0; i++) {
        if (specifier != ALL_FORMAT[i]->flag)
            continue;
        res = ALL_FORMAT[i]->func(args, &info, ctx);
        if (post_processing(&info, &res, specifier) == EXIT_FAILURE)
            return (-1);
        if (printf_or_sprintf(ctx, res, str_ptr) == EXIT_FAILURE)
            return (-1);
        free(res);
        return (offset + 1);
    }
    return (0);
}
