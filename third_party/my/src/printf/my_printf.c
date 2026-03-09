/*
** EPITECH PROJECT, 2025
** my_printf
** File description:
** printf
*/

#include <unistd.h>

#include "my/io.h"
#include "my/string.h"

#include "internal.h"
#include "parser.h"

static int internal_printf(int fd, const char *format, va_list args)
{
    pf_ctx_t ctx = {fd, 0, 0};
    int offset;

    while (*format) {
        if (*format != '%') {
            ctx.error = (my_putchar_fd(fd, *format) == -1) ? 1 : ctx.error;
            ctx.count++;
            format++;
            continue;
        }
        offset = handle_conversion(&ctx, format + 1, args, NULL);
        if (offset > 0) {
            format += (offset + 1);
            continue;
        }
    }
    return ctx.error ? -1 : ctx.count;
}

int my_printf(const char *format, ...)
{
    va_list args;
    int ret;

    va_start(args, format);
    ret = internal_printf(1, format, args);
    va_end(args);
    return ret;
}

int my_fprintf(int fd, const char *format, ...)
{
    va_list args;
    int ret;

    va_start(args, format);
    ret = internal_printf(fd, format, args);
    va_end(args);
    return ret;
}

static int isnotspecifier(char **str_ptr, pf_ctx_t *ctx, char **format)
{
    char tmp[2] = {*(*format), 0};

    if (*(*format) != '%') {
        if (!my_strappend(str_ptr, tmp))
            return (-1);
        (ctx->count)++;
        (*format)++;
        return (EXIT_SUCCESS);
    }
    return (EXIT_FAILURE);
}

static int internal_sprintf(char **str_ptr, char *format, va_list args)
{
    pf_ctx_t ctx = {-1, 0, 0};
    int offset;
    int retv;

    while (*format) {
        retv = isnotspecifier(str_ptr, &ctx, &format);
        if (retv == -1)
            return (retv);
        if (retv == EXIT_SUCCESS)
            continue;
        offset = handle_conversion(&ctx, format + 1, args, str_ptr);
        if (offset > 0) {
            format += (offset + 1);
            continue;
        }
        if (offset == -1)
            return (-1);
    }
    return (ctx.error ? (-1) : (ctx.count));
}

int my_sprintf(char **str_ptr, char *format, ...)
{
    va_list args;
    int ret;

    va_start(args, format);
    ret = internal_sprintf(str_ptr, format, args);
    va_end(args);
    return ret;
}
