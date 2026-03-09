/*
** EPITECH PROJECT, 2025
** my_printf
** File description:
** printf
*/

#include <unistd.h>
#include "switch_parameters.h"
#include "flag_to_func.h"
#include "my_printf_utils.h"
#include "count_error.h"

#include "my/io.h"
#include "my/string.h"

static int internal_printf(int fd, const char *format, va_list args)
{
    cot_err_t coterr = {0, 0};
    int written;

    while (*format != '\0') {
        if (*format == '%') {
            format++;
            format_gestion(fd, args, format, &coterr);
            format++;
            continue;
        }
        written = my_putchar_fd(fd, (*format));
        if (written == -1)
            coterr.error = 1;
        else
            coterr.count += written;
        format++;
    }
    return coterr.error ? -1 : coterr.count;
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

static int internal_sprintf(char **str_ptr, char *format, va_list args)
{
    cot_err_t coterr = {0, 0};
    char one_char[2];

    one_char[1] = '\0';
    while ((*format)) {
        if (*format == '%') {
            format++;
            sformat_gestion(str_ptr, args, format, &coterr);
            format++;
            continue;
        }
        one_char[0] = (*format);
        my_strappend(str_ptr, one_char);
        (coterr.count)++;
        format++;
    }
    return coterr.error ? -1 : coterr.count;
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
