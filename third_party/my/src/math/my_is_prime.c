/*
** EPITECH PROJECT, 2025
** my_is_prime
** File description:
** returns 1 if the number is prime and 0 if not.
*/

static int my_rounded_square_root(int nb)
{
    int result = 0;

    if (nb < 0)
        return 0;
    for (int i = 1; nb > 0; i += 2) {
        nb -= i;
        if (nb > 0)
            result++;
    }
    return result;
}

int my_is_prime(int nb)
{
    int wall = my_rounded_square_root(nb);

    if (nb <= 1)
        return 0;
    for (int i = 2; i <= wall + 1; i++) {
        if (nb % i == 0)
            return 0;
    }
    return 1;
}
