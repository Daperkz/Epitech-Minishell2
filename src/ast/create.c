/*
** EPITECH PROJECT, 2026
** create.c
** File description:
** create
*/

#include "shell.h"

const ast_rules_t AST_RULES[] = {
    {COMMAND_SEPERATOR, AST_CMD_SEPERATOR,
        my_strrstr_unquoted, astexec_command_separator},
    {PIPE_SEPERATOR, AST_PIPE,
        my_strrstr_unquoted, astexec_pipe},
    {DLSR, AST_DLSR,
        my_strstr_unquoted, astexec_dlsr},
    {LSR, AST_LSR,
        my_strstr_unquoted, astexec_lsr},
    {DGRT, AST_DGRT,
        my_strstr_unquoted, astexec_dgrt},
    {GRT, AST_GRT,
        my_strstr_unquoted, astexec_grt},
    {NULL, AST_NONE,
        NULL, NULL}
};

bnode_t *ast_create_node(ast_type_t type, char *args)
{
    ast_data_t *data = create_ast_data(type, args);

    if (!data)
        return (MALLOC_FAIL);
    return (create_bnode(data));
}

static bnode_t *build_branch(const ast_rules_t *rule, char *lstr, char *rstr)
{
    bnode_t *node = ast_create_node(rule->type, rule->token);

    if (node == MALLOC_FAIL)
        return (MALLOC_FAIL);
    node->left = parse_recursive(lstr);
    if (node->left == MALLOC_FAIL) {
        destroy_bnode_recursive(node, &destroy_ast_data);
        return (MALLOC_FAIL);
    }
    node->right = parse_recursive(rstr);
    if (node->right == MALLOC_FAIL) {
        destroy_bnode_recursive(node, &destroy_ast_data);
        return (MALLOC_FAIL);
    }
    return (node);
}

static bnode_t *divide(char *str, char *token_pos, int i)
{
    char *lstr = NULL;
    char *rstr = NULL;
    bnode_t *res = NULL;

    lstr = my_strndup(str, token_pos - str);
    if (!lstr)
        return (MALLOC_FAIL);
    rstr = my_strdup(token_pos + my_strlen(AST_RULES[i].token));
    if (!rstr) {
        free(lstr);
        return (MALLOC_FAIL);
    }
    res = build_branch(&AST_RULES[i], lstr, rstr);
    free(lstr);
    free(rstr);
    return (res);
}

static bnode_t *search_rule(char *dup)
{
    char *token_pos = NULL;

    for (int i = 0; AST_RULES[i].token != NULL; i++) {
        token_pos = AST_RULES[i].search_func(dup, AST_RULES[i].token);
        if (!token_pos)
            continue;
        return (divide(dup, token_pos, i));
    }
    return (ast_create_node(AST_COMMAND, dup));
}

bnode_t *parse_recursive(char *str)
{
    char *dup;
    bnode_t *res = NULL;

    if (!str)
        return (NULL);
    dup = my_strdup(str);
    if (!dup)
        return (MALLOC_FAIL);
    my_strtrim(dup, WHITESPACES);
    if (my_strlen(dup) == 0) {
        free(dup);
        return (NULL);
    }
    res = search_rule(dup);
    free(dup);
    return (res);
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
