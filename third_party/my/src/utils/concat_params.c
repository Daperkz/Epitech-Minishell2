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

    for (i = 0; i < argc; i++) {
        total_len += my_strlen(argv[i]);
    }
    str = malloc(total_len + 1);
    my_strcat(str, "");
    i = 0;
    while (i < argc) {
        my_strcat(str, argv[i]);
        if (i != argc - 1) {
            my_strcat(str, "\n");
        }
        i++;
    }
    my_strcat(str, "\0");
    return &str[0];
}
