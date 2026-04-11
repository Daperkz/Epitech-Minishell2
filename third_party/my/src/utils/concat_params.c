/*
** EPITECH PROJECT, 2025
** concat_params
** File description:
** turns the command-line given arguments into a single string.
** Arguments are separated by '\n'.
*/

#include <stdlib.h>

#include "my/string.h"

char *concat_params(int argc, char **argv)
{
    char *str;
    int total_len = 0;
    int i = 0;

    for (i = 0; i < argc; i++)
        total_len += my_strlen(argv[i]) + 1;
    str = malloc(total_len + 1);
    if (!str)
        return (NULL);
    str[0] = '\0';
    for (int i = 0; i < argc; i++) {
        my_strcat(str, argv[i]);
        if (i != argc - 1)
            my_strcat(str, "\n");
    }
    my_strcat(str, "");
    return (str);
}
