/*
** EPITECH PROJECT, 2025
** read_file.c
** File description:
** read_file
*/

#include <unistd.h>
#include <stdio.h>

#include "my/file.h"

// opens said file returns it's content inside of a buffer
char *read_file(const char *filename)
{
    int fd = open_file(filename);
    int size = get_file_size(filename);
    char *buffer = NULL;

    if (size < 0 || fd == -1) {
        return NULL;
    }
    buffer = get_file_content(fd, size);
    if (!buffer)
        return NULL;
    close(fd);
    return buffer;
}

// opens said file returns it's content inside of a buffer (no stat)
char *read_file_dyn(const char *filename)
{
    int fd = open_file(filename);
    int size = get_file_size(filename);
    char *buffer = NULL;

    if (size < 0 || fd == -1) {
        return NULL;
    }
    buffer = get_file_content(fd, size);
    if (!buffer)
        return NULL;
    close(fd);
    return buffer;
}
