/*
** EPITECH PROJECT, 2025
** get_file_content.c
** File description:
** get_file_content
*/

#include <stdlib.h>
#include <unistd.h>
#include <stdio.h>

//returns a buffer of the entire content of a file or NULL in case of error
char *get_file_content(int fd, long size)
{
    char *buffer = malloc(sizeof(char) * (size + 1));

    if (!buffer) {
        perror("Error malloc");
        close(fd);
        return NULL;
    }
    if (read(fd, buffer, size) != size) {
        perror("Error read");
        close(fd);
        free(buffer);
        return NULL;
    }
    buffer[size] = '\0';
    return buffer;
}
