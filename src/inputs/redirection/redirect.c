/*
** EPITECH PROJECT, 2026
** redirect.c
** File description:
** redirect
*/

#include <fcntl.h>

#include "my/string.h"
#include "my/printf.h"

#include "shell.h"

int redirect(shell_t *shell, int i)
{
    char *type = shell->input_array[i];
    char *file = shell->input_array[i + 1];
    int fd = -1;

    if (my_strcmp(type, GRT) == 0)
        fd = open(file, O_WRONLY | O_CREAT | O_TRUNC, 0644);
    else if (my_strcmp(type, DGRT) == 0)
        fd = open(file, O_WRONLY | O_CREAT | O_APPEND, 0644);
    else
        fd = open(file, O_RDONLY);
    if (fd == -1)
        return file_error(shell, file);
    dup2(fd, (type[0] == '<') ? STDIN_FD : STDOUT_FD);
    close(fd);
    shift_array(shell, i);
    return (EXIT_SUCCESS);
}
