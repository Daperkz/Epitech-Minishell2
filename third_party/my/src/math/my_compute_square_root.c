/*
** EPITECH PROJECT, 2025
** my_compute_square_root
** File description:
** returns the square root (if it is a whole number) of the number given a
** argument. If the square root is not a whole number,
** the function should return 0.
*/

int my_compute_square_root(int nb)
{
    int result = 0;

    if (nb < 0)
        return 0;
    for (int i = 1; nb > 0; i += 2) {
        nb -= i;
        result++;
    }
    if (nb != 0)
        return 0;
    return result;
}
