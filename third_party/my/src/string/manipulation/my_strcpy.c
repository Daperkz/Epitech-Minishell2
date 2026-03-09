/*
** EPITECH PROJECT, 2025
** my_strcpy
** File description:
** copies a string into another. The destination string must already have enough
** memory to copy the source string.
*/

char *my_strcpy(char *dest, char const *src)
{
    char *origin = dest;

    while (*src) {
        *dest = *src;
        dest++;
        src++;
    }
    *dest = '\0';
    return origin;
}

char *my_strncpy(char *dest, char const *src, int n)
{
    for (int i = 0; i < n; i++)
        dest[i] = src[i];
    return dest;
}
