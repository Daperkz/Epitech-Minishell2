/*
** EPITECH PROJECT, 2025
** my_printf.h
** File description:
** my_printfs
*/

#ifndef MY_PRINTF_H
    #define MY_PRINTF_H

    #define STDIN 0
    #define STDOUT 1
    #define STDERR 2

int my_printf(const char *format, ...);

int my_fprintf(int fd, const char *format, ...);

int my_sprintf(char **str_ptr, const char *format, ...);

#endif
