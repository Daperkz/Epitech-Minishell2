/*
** EPITECH PROJECT, 2025
** my_strcat
** File description:
** concatenates two strings into dest must have enough space allocated.
*/

char *my_strcat(char *dest, char const *src)
{
    char *origin = dest;

    while (*dest)
        dest++;
    while (*src) {
        *dest = *src;
        dest++;
        src++;
    }
    *dest = '\0';
    return origin;
}

char *my_strncat(char *dest, char const *src, int nb)
{
    int i = 0;
    int j = 0;

    while (dest[i])
        i++;
    while (src[j] && j < nb) {
        dest[i] = src[j];
        i++;
        j++;
    }
    dest[i] = '\0';
    return dest;
}
