/*
** EPITECH PROJECT, 2025
** get_file_size.c
** File description:
** get_file_size
*/

#include <sys/stat.h>
#include <stdio.h>
#include <unistd.h>

#include "my/file.h"

//returns the size in bytes of said file or -1 in case of error
long get_file_size(const char *filename)
{
    struct stat st;

    if (stat(filename, &st) != 0)
        return -1;
    return st.st_size;
}

//returns the size in bytes of said file or -1 in case of error (no stat)
long get_file_size_dyn(const char *filename)
{
    int fd = open_file(filename);
    char buff[512];
    long size = 0;
    long n = 1;

    if (fd == -1)
        return -1;
    while (n > 0) {
        n = read(fd, buff, 512);
        size += n;
    }
    close(fd);
    return size;
}
