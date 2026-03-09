/*
** EPITECH PROJECT, 2026
** my_printf_internal.h
** File description:
** my_printf_internal
*/

#ifndef MY_PRINTF_INTERNAL_H_
    #define MY_PRINTF_INTERNAL_H_

    #include <stdarg.h>

    #include "utils.h"

typedef struct printf_ctx_s {
    int fd;
    int count;
    int error;
} pf_ctx_t;

typedef struct printf_info_s {
    int width;
    int precision;
    int sharp;
    int left;
    int plus;
    int space;
    int zero;
    char length;
} pf_info_t;

typedef char *(*flag_func_t)(va_list, pf_info_t *, pf_ctx_t *);

typedef struct flag_map_s {
    char flag;
    flag_func_t func;
} flag_map_t;


#endif /* !MY_PRINTF_INTERNAL_H_ */
