/*
** EPITECH PROJECT, 2025
** my_strstr
** File description:
** searches for a str in a str
*/

#include <unistd.h>

#include "my/string.h"
#include "my/math.h"


static void compute_bad_char(char const *pattern, int m, int bad_char[256])
{
    for (int i = 0; i < 256; i++)
        bad_char[i] = m;
    for (int i = 0; i < m - 1; i++)
        bad_char[(unsigned char)pattern[i]] = m - 1 - i;
}

static void build_suffix_arr(char const *pattern, int m, int *suffix)
{
    int g = m - 1;
    int f = 0;

    suffix[g] = m;
    for (int i = m - 2; i >= 0; i--) {
        if (i > g && suffix[i + m - 1 - f] < i - g) {
            suffix[i] = suffix[i + m - 1 - f];
            continue;
        }
        if (i < g)
            g = i;
        f = i;
        for (g = (i < g) ? i : g;
            g >= 0 && pattern[g] == pattern[g + m - 1 - f]; g--);
        suffix[i] = f - g;
    }
}

static void compute_good_suffix(char const *pattern, int m, int *good_suffix)
{
    int suffix[m];

    build_suffix_arr(pattern, m, suffix);
    for (int i = 0; i < m; i++)
        good_suffix[i] = m;
    for (int i = m - 1; i >= 0; i--) {
        for (int j = 0; suffix[i] == i + 1 && j < m - 1 - i; j++)
            good_suffix[j] = (good_suffix[j] == m) ? m - 1 - i : good_suffix[j];
    }
    for (int i = 0; i <= m - 2; i++)
        good_suffix[m - 1 - suffix[i]] = m - 1 - i;
}

static char *compute(char *str, int n, char const *pattern, int m)
{
    int j = 0;
    int i = 0;
    int bad_char[256];
    int good_suffix[m];

    compute_bad_char(pattern, m, bad_char);
    compute_good_suffix(pattern, m, good_suffix);
    while (i <= n - m) {
        j = m - 1;
        while (j >= 0 && pattern[j] == str[i + j])
            j--;
        if (j < 0)
            return &str[i];
        i += MAX(good_suffix[j],
            bad_char[(unsigned char)str[i + j]] - (m - 1 - j));
    }
    return NULL;
}

/**
** @brief Locates the first occurrence the pattern in the str
** Boyer-Moore algorithm
** BC : O(N/M)
** WC : O(N + M)
** @return A pointer the located pattern, NULL if pattern was not found.
*/
char *my_strstr(char *str, char const *pattern)
{
    int n = my_strlen(str);
    int m = my_strlen(pattern);

    if (m == 0)
        return str;
    if (m > n)
        return NULL;
    return compute(str, n, pattern, m);
}
