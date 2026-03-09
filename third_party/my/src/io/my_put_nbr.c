/*
** EPITECH PROJECT, 2025
** my_put_nbr
** File description:
** displays the number given as a parameter.
** It must be able to display all the possible values of an int
*/

#include "my/io.h"
#include "my/string.h"

int my_put_nbr(int nb)
{
    long n = nb;

    if (n < 0) {
        my_putchar('-');
        n *= -1;
    }
    if (n >= 10) {
        my_put_nbr(n / 10);
        my_put_nbr(n % 10);
    } else {
        my_putchar(n + '0');
    }
    return 0;
}

int my_put_nbr_base(int nb, char *base)
{
    int base_size = my_strlen(base);
    long n = nb;

    if (base_size <= 1)
        return 0;
    if (n < 0) {
        my_putchar('-');
        n *= -1;
    }
    if (n >= base_size) {
        my_put_nbr_base((int)(n / base_size), base);
        my_put_nbr_base((int)(n % base_size), base);
    } else {
        my_putchar(base[n]);
    }
    return 0;
}
