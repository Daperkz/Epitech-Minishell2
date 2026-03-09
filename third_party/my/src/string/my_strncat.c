/*
** EPITECH PROJECT, 2025
** my_strncat
** File description:
** concatenates n characters of the src string to the end of the dest string.
*/

char *my_strncat(char *dest, char const *src, int nb)
{
    int i = 0;
    int j = 0;

    while (dest[i]) {
        i++;
    }
    while (src[j] && j < nb) {
        dest[i] = src[j];
        i++;
        j++;
    }
    dest[i] = '\0';
    return dest;
}
