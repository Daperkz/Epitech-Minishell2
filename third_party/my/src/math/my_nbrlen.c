/*
** EPITECH PROJECT, 2025
** my_nbrlen.c
** File description:
** my_nbrlen
*/

int my_nbrlen(int x)
{
    int len = 0;

    if (x == 0)
        return 1;
    if (x < 0)
        x = -x;
    while (x > 0) {
        x /= 10;
        len++;
    }
    return len;
}
