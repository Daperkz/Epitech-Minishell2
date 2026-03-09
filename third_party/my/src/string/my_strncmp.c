/*
** EPITECH PROJECT, 2025
** my_strncmp
** File description:
** compares the first n bytes of the two strings
*/

int my_strncmp(char const *s1, char const *s2, int n)
{
    int i = 0;

    while (i < n) {
        if (s1[i] != s2[i])
            return (int)s1[i] - (int)s2[i];
        if (!s1[i])
            return 0;
        i++;
    }
    return 0;
}
