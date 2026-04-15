/*
** EPITECH PROJECT, 2026
** create.c
** File description:
** create
*/

#include "shell.h"

const ast_rules_t AST_RULES[] = {
    {COMMAND_SEPERATOR, AST_CMD_SEPERATOR, my_strrstr_unquoted,
        astcheck_command_separator, 0, astexec_command_separator},
    {PIPE_SEPERATOR, AST_PIPE, my_strrstr_unquoted,
        astcheck_pipe, 0, astexec_pipe},
    {DLSR, AST_DLSR, my_strstr_unquoted,
        astcheck_dlsr, 1, astexec_dlsr},
    {LSR, AST_LSR, my_strstr_unquoted,
        astcheck_lsr, 1, astexec_lsr},
    {DGRT, AST_DGRT, my_strstr_unquoted,
        astcheck_dgrt, 1, astexec_dgrt},
    {GRT, AST_GRT, my_strstr_unquoted,
        astcheck_grt, 1, astexec_grt},
    {NULL, AST_NONE, NULL,
        NULL, 0, NULL}
};

bnode_t *ast_create_node(ast_type_t type, char *args)
{
    ast_data_t *data = create_ast_data(type, args);

    if (!data)
        return (MALLOC_FAIL);
    return (create_bnode(data));
}

static bnode_t *build_branch_validation(
    shell_t *shell, bnode_t *node, const ast_rules_t *rule
)
{
    if (node->left == MALLOC_FAIL || node->right == MALLOC_FAIL) {
        node->left = node->left == MALLOC_FAIL ? NULL : node->left;
        node->right = node->right == MALLOC_FAIL ? NULL : node->right;
        destroy_bnode_recursive(node, &destroy_ast_data);
        return (MALLOC_FAIL);
    }
    if (node->left == SYNTAX_ERROR || node->right == SYNTAX_ERROR) {
        node->left = node->left == SYNTAX_ERROR ? NULL : node->left;
        node->right = node->right == SYNTAX_ERROR ? NULL : node->right;
        destroy_bnode_recursive(node, &destroy_ast_data);
        return (SYNTAX_ERROR);
    }
    if (rule->validator &&
        rule->validator(shell, node->left, node->right) == 1) {
        destroy_bnode_recursive(node, &destroy_ast_data);
        return (SYNTAX_ERROR);
    }
    return (node);
}

static bnode_t *build_branch(
    shell_t *shell, const ast_rules_t *rule, char *lstr, char *rstr
)
{
    bnode_t *node = ast_create_node(rule->type, rule->token);

    if (node == MALLOC_FAIL || node == SYNTAX_ERROR)
        return (node);
    node->left = parse_recursive(shell, lstr);
    node->right = parse_recursive(shell, rstr);
    return (build_branch_validation(shell, node, rule));
}

static char *extract_right_args(char **remainder, int limit)
{
    char *result = NULL;
    char *str = *remainder;
    char *start;

    if (limit <= 0)
        return my_strdup(str);
    while (*str && (*str == ' ' || *str == '\t' || *str == '\n'))
        str++;
    start = str;
    for (int count = 0; count < limit && *str; count++) {
        while (*str && *str != ' ' && *str != '\t' && *str != '\n')
            str++;
        while (*str && (*str == ' ' || *str == '\t' || *str == '\n'))
            str++;
    }
    result = my_strndup(start, str - start);
    *remainder = str;
    return result;
}

static char *create_left_string(char *lstr, char *remainder, int i)
{
    char *full_lstr;

    if (AST_RULES[i].args_limit > 0 && remainder && *remainder) {
        full_lstr = malloc(my_strlen(lstr) + my_strlen(remainder) + 2);
        if (!full_lstr)
            return (NULL);
        my_strcpy(full_lstr, lstr);
        my_strcat(full_lstr, " ");
        my_strcat(full_lstr, remainder);
    } else {
        full_lstr = my_strdup(lstr);
    }
    my_strtrim(full_lstr, WHITESPACES);
    return (full_lstr);
}

static char *get_two_branch_strings(
    char *lstr, char **rstr_p, int i, char *remainder
)
{
    char *full_lstr;

    *rstr_p = extract_right_args(&remainder, AST_RULES[i].args_limit);
    if (!(*rstr_p)) {
        *rstr_p = NULL;
        return (MALLOC_FAIL);
    }
    full_lstr = create_left_string(lstr, remainder, i);
    if (!full_lstr)
        return (MALLOC_FAIL);
    my_strtrim(*rstr_p, WHITESPACES);
    return (full_lstr);
}

static bnode_t *divide(shell_t *shell, char *str, char *token_pos, int i)
{
    char *lstr = my_strndup(str, token_pos - str);
    char *full_lstr = NULL;
    char *remainder = token_pos + my_strlen(AST_RULES[i].token);
    char *rstr = NULL;
    bnode_t *res = NULL;

    if (!lstr)
        return (MALLOC_FAIL);
    full_lstr = get_two_branch_strings(lstr, &rstr, i, remainder);
    if (full_lstr == MALLOC_FAIL) {
        free(lstr);
        free(rstr);
        return (MALLOC_FAIL);
    }
    res = build_branch(shell, &AST_RULES[i], full_lstr, rstr);
    free(lstr);
    free(rstr);
    free(full_lstr);
    return (res);
}

static bnode_t *search_rule(shell_t *shell, char *dup)
{
    char *token_pos = NULL;

    for (int i = 0; AST_RULES[i].token != NULL; i++) {
        token_pos = AST_RULES[i].search_func(dup, AST_RULES[i].token);
        if (!token_pos)
            continue;
        return (divide(shell, dup, token_pos, i));
    }
    return (ast_create_node(AST_COMMAND, dup));
}

bnode_t *parse_recursive(shell_t *shell, char *str)
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
    res = search_rule(shell, dup);
    free(dup);
    return (res);
}

int create_ast(shell_t *shell, char *str)
{
    shell->ast = btree_create();
    if (!shell->ast)
        return (EXIT_ERROR);
    shell->ast->root = parse_recursive(shell, str);
    if (shell->ast->root == SYNTAX_ERROR) {
        shell->last_errno = 1;
        shell->ast->root = NULL;
        DESTROY_AST(shell->ast);
        shell->ast = NULL;
        return (EXIT_SUCCESS);
    }
    if (shell->ast->root == MALLOC_FAIL) {
        shell->ast->root = NULL;
        DESTROY_AST(shell->ast);
        return (EXIT_ERROR);
    }
    return (EXIT_SUCCESS);
}
