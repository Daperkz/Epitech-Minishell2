/*
** EPITECH PROJECT, 2025
** minilib
** File description:
** includes small my_lib features
*/

#ifndef MINILIB_H
    #define MINILIB_H

    #include <stdlib.h>

char *my_put_float_hex(double nb, char *base);
char *my_put_scientific(double nb, char *base, int cap);
char *my_put_adress(void *a);

#endif
