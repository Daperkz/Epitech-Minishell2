/*
** EPITECH PROJECT, 2026
** ast.h
** File description:
** ast
*/

#ifndef AST_H_
    #define AST_H_

    #include "my/graph/binary_tree.h"

    #include "utils.h"

    #define DESTROY_AST(ast) btree_destroy(ast, &destroy_ast_data)

typedef struct minishell_s shell_t;

typedef enum ast_type_e {
    AST_NONE,
    AST_COMMAND,                // builtins or external command
    AST_LSR,                    // Input Redirection
    AST_DLSR,                  // Double Input Redirection / Heredoc
    AST_GRT,                    // Output Redirection
    AST_DGRT,                  // Double Output Redirection / Append
    AST_PIPE,                   // '|'
    AST_CMD_SEPERATOR           // ';'
} ast_type_t;

typedef struct ast_data_s {
    ast_type_t type;
    char *args;         // raw string segment
    char **cmd_args;    // NULL-terminated array for execve
} ast_data_t;

bnode_t *parse_recursive(shell_t *shell, char *str);

ast_data_t *create_ast_data(ast_type_t type, char *args);
void destroy_ast_data(void *data);


typedef char *(*ast_search_t)(char *str, char *seps);
typedef int (*ast_exec_t)(shell_t *shell, bnode_t *node);
typedef int (*ast_validate_t)(shell_t *shell, bnode_t *left, bnode_t *right);

typedef struct ast_rules_s {
    char *token;
    ast_type_t type;
    ast_search_t search_func;
    ast_validate_t validator;
    int args_limit; // 0 for everything, x for x args
    ast_exec_t execute_func;
} ast_rules_t;

int astexec_command_separator(shell_t *shell, bnode_t *node);
int astcheck_command_separator(shell_t *shell, bnode_t *left, bnode_t *right);

int astexec_pipe(shell_t *shell, bnode_t *node);
int astcheck_pipe(shell_t *shell, bnode_t *left, bnode_t *right);

int astexec_dlsr(shell_t *shell, bnode_t *node);
int astcheck_dlsr(shell_t *shell, bnode_t *left, bnode_t *right);

int astexec_lsr(shell_t *shell, bnode_t *node);
int astcheck_lsr(shell_t *shell, bnode_t *left, bnode_t *right);

int astexec_dgrt(shell_t *shell, bnode_t *node);
int astcheck_dgrt(shell_t *shell, bnode_t *left, bnode_t *right);

int astexec_grt(shell_t *shell, bnode_t *node);
int astcheck_grt(shell_t *shell, bnode_t *left, bnode_t *right);

int astexec_command(shell_t *shell, bnode_t *node);

extern const ast_rules_t AST_RULES[];

int create_ast(shell_t *shell, char *str);

#endif /* !AST_H_ */
