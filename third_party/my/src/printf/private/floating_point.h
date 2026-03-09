/*
** EPITECH PROJECT, 2025
** floating_point
** File description:
** union containing a float which is splitted into 3 parts from the bits the
** 1bit sign - or +, exponent the integer value of the float number + the 52bits
** of the mantissa which corresponds to the float
*/

#ifndef DECONSTRUCT_FLOAT_H
    #define DECONSTRUCT_FLOAT_H

typedef union {
    double f;
    unsigned long long bits;
} double_t;

#endif
