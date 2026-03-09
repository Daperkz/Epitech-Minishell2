/*
** EPITECH PROJECT, 2025
** utils.h
** File description:
** utils
*/

#ifndef MY_UTILS_H_
    #define MY_UTILS_H_

    #define UNUSED(arg) ((void)arg)

    #define BASE2 "01"
    #define BASE7 "01234567"
    #define BASE10 "0123456789"
    #define BASE15CAP "0123456789ABCDEF"
    #define BASE15LOW "0123456789abcdef"

void my_swap(int *a, int *b);
void my_sort_int_array(int *tab, int size);
char *concat_params(int argc, char **argv);
char *convert_base(char const *nbr, char const *base_from, char const *base_to);

char *my_itoab(int nb, char *base);
char *my_uitoab(unsigned int nb, char *base);
char *my_ltoab(long nb, char *base);
char *my_ftoa(double nb, int precision);

#endif /* !UTILS_H_ */
