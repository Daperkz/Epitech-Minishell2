/*
** EPITECH PROJECT, 2026
** create.c
** File description:
** create
*/

#include "shell.h"

const ast_rules_t AST_RULES[] = {
    {COMMAND_SEPERATOR, AST_CMD_SEPERATOR, my_strrstr_unquoted,
        astcheck_command_separator, astexec_command_separator},
    {PIPE_SEPERATOR, AST_PIPE, my_strrstr_unquoted,
        astcheck_pipe, astexec_pipe},
    {DLSR, AST_DLSR, my_strstr_unquoted,
        astcheck_dlsr, astexec_dlsr},
    {LSR, AST_LSR, my_strstr_unquoted,
        astcheck_lsr, astexec_lsr},
    {DGRT, AST_DGRT, my_strstr_unquoted,
        astcheck_dgrt, astexec_dgrt},
    {GRT, AST_GRT, my_strstr_unquoted,
        astcheck_grt, astexec_grt},
    {NULL, AST_NONE, NULL,
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
    node->right = parse_recursive(rstr);
    if (node->left == MALLOC_FAIL || node->right == MALLOC_FAIL) {
        destroy_bnode_recursive(node, &destroy_ast_data);
        return (MALLOC_FAIL);
    }
    if (node->left == SYNTAX_ERROR || node->right == SYNTAX_ERROR) {
        destroy_bnode_recursive(node, &destroy_ast_data);
        return (SYNTAX_ERROR);
    }
    if (rule->validator && rule->validator(node->left, node->right) == 1) {
        destroy_bnode_recursive(node, &destroy_ast_data);
        return (SYNTAX_ERROR);
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

int create_ast(shell_t *shell, char *str)
{
    shell->ast = btree_create();
    if (!shell->ast)
        return (EXIT_ERROR);
    shell->ast->root = parse_recursive(str);
    if (shell->ast->root == SYNTAX_ERROR) {
        shell->last_errno = 1;
        DESTROY_AST(shell->ast);
        shell->ast = NULL;
        return (EXIT_SUCCESS);
    }
    if (shell->ast->root == MALLOC_FAIL) {
        DESTROY_AST(shell->ast);
        return (EXIT_ERROR);
    }
    return (EXIT_SUCCESS);
}
