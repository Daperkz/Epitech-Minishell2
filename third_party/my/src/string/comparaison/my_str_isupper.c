/*
** EPITECH PROJECT, 2025
** my_str_isupper
** File description:
** returns 1 if the string passed as parameter only contains uppercase
** alphabetical char- acters and 0 otherwise.
*/

int my_str_isupper(char const *str)
{
    while (*str) {
        if (!(*str >= 'A' && *str <= 'Z')) {
            return 0;
        }
        str++;
    }
    return 1;
}
