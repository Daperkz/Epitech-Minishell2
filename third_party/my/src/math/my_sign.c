/*
** EPITECH PROJECT, 2026
** my_sign.c
** File description:
** my_sign
*/

int my_sign(int x)
{
    if (x < 0)
        return -1;
    if (x > 0)
        return 1;
    return 0;
}
