/*
** EPITECH PROJECT, 2026
** create.c
** File description:
** create
*/

#include <stdlib.h>

#include "my/string.h"

#include "shell/ast.h"

static int create_args(ast_data_t *data, char *args)
{
    if (args) {
        data->args = my_strdup(args);
        if (!data->args)
            return (EXIT_FAILURE);
    }
    if (data->type == AST_COMMAND && data->args) {
        data->cmd_args = my_str_to_str_arr(data->args, WHITESPACES);
        if (!data->cmd_args)
            return (EXIT_FAILURE);
    }
    return (EXIT_SUCCESS);
}

ast_data_t *create_ast_data(ast_type_t type, char *args)
{
    ast_data_t *data = malloc(sizeof(ast_data_t));

    if (!data)
        return (NULL);
    data->type = type;
    data->args = NULL;
    data->cmd_args = NULL;
    if (create_args(data, args) == EXIT_FAILURE) {
        destroy_ast_data(data);
        return (NULL);
    }
    return (data);
}
