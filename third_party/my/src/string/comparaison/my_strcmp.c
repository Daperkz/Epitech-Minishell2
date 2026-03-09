/*
** EPITECH PROJECT, 2025
** my_strcmp
** File description:
** compares to string
*/

int my_strcmp(char const *s1, char const *s2)
{
    int i = 0;
    char c1 = s1[i];
    char c2 = s2[i];

    while ((c1 || c2) && c1 == c2) {
        i++;
        c1 = s1[i];
        c2 = s2[i];
    }
    return (c1 > c2) - (c1 < c2);
}

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
