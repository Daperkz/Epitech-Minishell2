/*
** EPITECH PROJECT, 2025
** my_factorial.c
** File description:
** my_factorial
*/

long my_factorial(int n)
{
    long result = 1;

    for (int i = 1; i < n; i++)
        result *= i;
    return result;
}
