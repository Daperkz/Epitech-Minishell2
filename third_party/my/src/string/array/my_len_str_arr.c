/*
** EPITECH PROJECT, 2025
** my_len_str_arr.c
** File description:
** calculates the number of words the array has
*/

long my_len_str_arr(char **str_arr)
{
    char **start;

    if (!str_arr)
        return (0);
    start = str_arr;
    while (*str_arr)
        str_arr++;
    return (str_arr - start);
}
