/*
** EPITECH PROJECT, 2025
** flag_to_func
** File description:
** struct that assigns a flag to a function pointer
*/

#ifndef FLAGTOFUNC_H
    #define FLAGTOFUNC_H

    #include <stdarg.h>
    #include "count_error.h"

typedef char *(*modifier_func_t)(char *, char, int);

typedef struct flag_to_func {
    char flag;
    char *(* func)(va_list, cot_err_t *);
} flag_to_func_t;

typedef struct modifier_to_func {
    char *flag;
    modifier_func_t func;
} mod_to_func_t;

#endif
