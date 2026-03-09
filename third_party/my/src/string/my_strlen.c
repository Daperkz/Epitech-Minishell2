/*
** EPITECH PROJECT, 2025
** my_strlen
** File description:
** counts and returns the number of characters found in the string
** passed as parameter
*/

int my_strlen(char const *str)
{
    const char *start = str;

    if (!str) {
        return -1;
    }
    while (*str) {
        str++;
    }
    return str - start;
}

int my_strlen_d(char const *str, char delim)
{
    const char *start = str;

    if (!str) {
        return -1;
    }
    while (*str != delim && *str != '\0') {
        str++;
    }
    return str - start;
}
