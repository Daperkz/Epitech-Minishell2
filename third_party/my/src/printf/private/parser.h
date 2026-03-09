/*
** EPITECH PROJECT, 2026
** parser.h
** File description:
** parser
*/

#ifndef MY_PRINTF_PARSER_H_
    #define MY_PRINTF_PARSER_H_

    #include "internal.h"

int handle_conversion(
    pf_ctx_t *ctx, const char *format, va_list args, char **str_ptr
);

#endif /* !MY_PRINTF_PARSER_H_ */
