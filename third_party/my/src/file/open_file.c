/*
** EPITECH PROJECT, 2025
** open_file.c
** File description:
** open_file
*/

#include <fcntl.h>
#include <stdio.h>

#include "my/printf.h"

//returns the file descriptor of said file or -1 in case of error
int open_file(const char *filename)
{
    int fd = open(filename, O_RDONLY);

    if (fd == -1) {
        my_fprintf(STDERR_FD, "%s: %s\n",
            filename, "No such file or directory");
        return (-1);
    }
    return (fd);
}
