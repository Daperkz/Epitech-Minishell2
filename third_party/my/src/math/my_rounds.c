/*
** EPITECH PROJECT, 2025
** my_rounds.c
** File description:
** my_rounds
*/

int my_ceil(double x)
{
    int i = (long long)x;

    if (x > 0 && x != i)
        i++;
    return i;
}

int my_floor(double x)
{
    int i = (long long)x;

    if (x < 0 && x != i)
        i--;
    return i;
}

int my_round(double x)
{
    if (x < 0)
        return my_ceil(x - 0.5);
    else
        return my_floor(x + 0.5);
}

int my_trunc(double x)
{
    return (long long)x;
}
