/*
** EPITECH PROJECT, 2025
** all_parameters
** File description:
** all_parameters
*/

#ifndef ALL_PARAMETERS_H_
    #define ALL_PARAMETERS_H_

    #include <stdarg.h>
    #include <unistd.h>

    #include "flag_to_func.h"
    #include "count_error.h"

char *parameter_d(va_list args, cot_err_t *coterr);
char *parameter_u(va_list args, cot_err_t *coterr);
char *parameter_o(va_list args, cot_err_t *coterr);
char *parameter_x(va_list args, cot_err_t *coterr);
char *parameter_xx(va_list args, cot_err_t *coterr);
char *parameter_f(va_list args, cot_err_t *coterr);
char *parameter_ff(va_list args, cot_err_t *coterr);
char *parameter_e(va_list args, cot_err_t *coterr);
char *parameter_ee(va_list args, cot_err_t *coterr);
char *parameter_g(va_list args, cot_err_t *coterr);
char *parameter_gg(va_list args, cot_err_t *coterr);
char *parameter_a(va_list args, cot_err_t *coterr);
char *parameter_aa(va_list args, cot_err_t *coterr);
char *parameter_c(va_list args, cot_err_t *coterr);
char *parameter_s(va_list args, cot_err_t *coterr);
char *parameter_p(va_list args, cot_err_t *coterr);
char *parameter_n(va_list args, cot_err_t *coterr);
char *parameter_percent(va_list args, cot_err_t *coterr);
char *error_output(char error_char, cot_err_t *coterr);

const flag_to_func_t ALL_FORMAT[22][2] = {
    {{'d', &parameter_d}}, {{'i', &parameter_d}}, {{'u', &parameter_u}},
    {{'o', &parameter_o}}, {{'x', &parameter_x}}, {{'X', &parameter_xx}},
    {{'f', &parameter_f}}, {{'F', &parameter_ff}}, {{'e', &parameter_e}},
    {{'E', &parameter_ee}}, {{'g', &parameter_g}}, {{'G', &parameter_gg}},
    {{'a', &parameter_a}}, {{'A', &parameter_aa}}, {{'c', &parameter_c}},
    {{'s', &parameter_s}}, {{'p', &parameter_p}}, {{'n', &parameter_n}},
    {{'%', &parameter_percent}}, {{0, NULL}}
};

#endif
