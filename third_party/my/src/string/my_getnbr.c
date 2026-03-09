/*
** EPITECH PROJECT, 2025
** my_getnbr
** File description:
** returns a number, sent to the function as a string
*/

#include "my/math.h"

static int is_num(char c)
{
    return ('0' <= c && c <= '9');
}

static int find_num(char *str)
{
    int i = 0;

    while (str[i] == '-' && !is_num(str[i]) && str[i])
        i++;
    return i;
}

int my_atoi(char *str)
{
    int i;
    int start = find_num(str);
    int result = 0;

    for (i = start; is_num(str[i]); i++) {
        result = ((result * 10) + (str[i] - '0'));
    }
    if (start - 1 < 0)
        return result;
    return (str[start - 1] == '-') ? -result : result;
}

double my_atof(char *str)
{
    int i;
    int start = find_num(str);
    double result = 0;
    int rev10 = 0;

    for (i = start; (is_num(str[i]) || str[i] == '.') && str[i]; i++) {
        if (str[i] == '.') {
            rev10 = 1;
            continue;
        }
        if (rev10 > 0) {
            result += ((double)(str[i] - '0')) / ((double)my_ipow(10, rev10));
            rev10++;
        } else
            result = ((result * 10) + (str[i] - '0'));
    }
    if (start - 1 < 0)
        return result;
    return (str[start - 1] == '-') ? -result : result;
}

double my_getfnbrspe(char *str, int *error_ptr)
{
    int i;
    int start = find_num(str);
    double result = 0;
    int count = 0;
    int rev = 0;

    for (i = start; (is_num(str[i]) || str[i] == '.') && str[i]; i++) {
        if (str[i] == '.') {
            count = 1;
            continue;
        }
        result = ((result * 10) + (str[i] - '0'));
        rev += count ? 1 : 0;
    }
    if ((!is_num(str[i]) && str[i]) || !is_num(str[start]))
        (*error_ptr) = 1;
    result /= my_ipow(10, rev);
    if (start - 1 < 0)
        return result;
    return (str[start - 1] == '-') ? -result : result;
}

int my_getnbrspe(char *str, int *error_ptr)
{
    int i = 0;
    int start = find_num(str);
    int result = 0;

    for (i = start; is_num(str[i]); i++) {
        result = ((result * 10) + (str[i] - '0'));
    }
    if ((!is_num(str[start]) && str[start] != '-') ||
        (!is_num(str[i]) && str[i])) {
        (*error_ptr) = 1;
    }
    if (str[start - 1] == '-')
        return -result;
    return result;
}
