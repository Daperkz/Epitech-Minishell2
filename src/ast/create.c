/*
** EPITECH PROJECT, 2026
** create.c
** File description:
** create
*/

#include <stdlib.h>

#include "my/graph/binary_tree.h"
#include "my/string.h"

#include "shell/macro.h"
#include "shell/ast.h"

const ast_rules_t AST_RULES[] = {
    {COMMAND_SEPERATOR, AST_CMD_SEPERATOR, &my_strrstr_unquoted, NULL},
    {PIPE_SEPERATOR, AST_PIPE, &my_strrstr_unquoted, NULL},
    {D_LSR, AST_D_LSR, &my_strstr_unquoted, NULL},
    {LSR, AST_LSR, &my_strstr_unquoted, NULL},
    {D_GRT, AST_D_GRT, &my_strstr_unquoted, NULL},
    {GRT, AST_GRT, &my_strstr_unquoted, NULL},
    {NULL, AST_NONE, &my_strstr_unquoted, NULL}
};

bnode_t *ast_create_node(ast_type_t type, char *args)
{
    ast_data_t *data = create_ast_data(type, args);

    if (!data)
        return (MALLOC_FAIL);
    return (create_bnode(data));
}

static bnode_t *parse_recursive(char *str)
{
    return (NULL);
}

btree_t *create_ast(char *str)
{
    btree_t *ast = btree_create();

    if (!ast)
        return (NULL);
    ast->root = parse_recursive(str);
    if (ast->root == MALLOC_FAIL) {
        DESTROY_AST(ast);
        return (NULL);
    }
    return (ast);
}
