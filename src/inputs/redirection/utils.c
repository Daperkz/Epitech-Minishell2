/*
** EPITECH PROJECT, 2026
** utils.c
** File description:
** utils
*/

#include <stdlib.h>

#include "shell.h"

void shift_array(shell_t *shell, int index)
{
    free(shell->input_array[index]);
    free(shell->input_array[index + 1]);
    for (int i = index; shell->input_array[i]; i++) {
        shell->input_array[i] = shell->input_array[i + 2];
    }
    shell->input_array_len -= 2;
}
