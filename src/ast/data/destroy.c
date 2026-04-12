/*
** EPITECH PROJECT, 2026
** destroy.c
** File description:
** destroy
*/

#include <stdlib.h>

#include "my/string.h"

#include "shell/ast.h"

void destroy_ast_data(void *data)
{
    ast_data_t *d = (ast_data_t *)(data);

    if (!d)
        return;
    if (d->args)
        free(d->args);
    if (d->cmd_args)
        my_free_str_arr(d->cmd_args);
    free(d);
}
