/*
** EPITECH PROJECT, 2025
** my_str_islower
** File description:
** returns 1 if the string passed as parameter only contains lowercase
** alphabetical char- acters and 0 otherwise.
*/

int my_str_islower(char const *str)
{
    while (*str) {
        if (!(*str >= 'a' && *str <= 'z')) {
            return 0;
        }
        str++;
    }
    return 1;
}
