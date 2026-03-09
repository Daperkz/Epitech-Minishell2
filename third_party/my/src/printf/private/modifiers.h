/*
** EPITECH PROJECT, 2025
** modifiers.h
** File description:
** all modifiers
*/

#ifndef MY_PRINTF_MODIFIER_H
    #define MY_PRINTF_MODIFIER_H

    #include "internal.h"

char *apply_width(char *str, pf_info_t *info);
char *apply_precision(char *str, pf_info_t *info, char specifier);
char *apply_sign_flags(char *str, pf_info_t *info, char specifier);
char *apply_sharp_flag(char *str, char specifier);

#endif /* !MY_PRINTF_MODIFIER_H */
