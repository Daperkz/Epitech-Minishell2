/*
** EPITECH PROJECT, 2025
** my_find_prime_sup
** File description:
** returns the smallest prime number that is greater than, or equal to,
** the number given as a parameter.
*/

#include "my/math.h"

int my_find_prime_sup(int nb)
{
    int i = nb;

    while (!my_is_prime(i))
        i++;
    return i;
}
