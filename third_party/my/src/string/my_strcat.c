/*
** EPITECH PROJECT, 2025
** my_strcat
** File description:
** concatenates two strings into dest must have enough space allocated.
*/

char *my_strcat(char *dest, char const *src)
{
    char *origin = dest;

    while (*dest) {
        dest++;
    }
    while (*src) {
        *dest = *src;
        dest++;
        src++;
    }
    *dest = '\0';
    return origin;
}
