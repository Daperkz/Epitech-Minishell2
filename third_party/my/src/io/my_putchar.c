/*
** EPITECH PROJECT, 2025
** my_putchar
** File description:
** prints out a character
*/

#include "unistd.h"

int my_putchar_fd(int fd, char c)
{
    return write(fd, &c, 1);
}

int my_putchar(char c)
{
    return my_putchar_fd(STDOUT_FILENO, c);
}
