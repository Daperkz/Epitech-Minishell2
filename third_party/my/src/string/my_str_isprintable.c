/*
** EPITECH PROJECT, 2025
** my_str_isprintable
** File description:
** returns 1 if the string passed as parameter only contains printable
** characters and 0 otherwise.
*/

int my_str_isprintable(char const *str)
{
    while (*str) {
        if (*str <= 31) {
            return 0;
        }
    }
    return 1;
}
