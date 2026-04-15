/*
** EPITECH PROJECT, 2026
** minishell.h
** File description:
** minishell
*/

#ifndef SHELL_H_
    #define SHELL_H_

    #include <unistd.h>
    #include <stdio.h>
    #include <stdlib.h>
    #include <signal.h>
    #include <errno.h>
    #include <fcntl.h>
    #include <string.h>
    #include <stdarg.h>
    #include <sys/wait.h>
    #include <stdbool.h>

    #include "my.h"

    #include "shell/macro.h"
    #include "shell/builtins.h"
    #include "shell/utils.h"
    #include "shell/ast.h"

typedef struct minishell_s {
    int last_errno;
    char **env;
    char *cwd; // current working directory
    char *owd; // old working directory
    char *hwd; // home working directory
    char **path_arr;
    pid_t pid;
    char *input;
    ssize_t input_len;
    char **input_array;
    int input_array_len;
    char **commands;
    int nbr_commands;
    btree_t *ast;
    int pipe_fds[2];
    pid_t child;
    int child_status;
    bool is_piped;
} shell_t;

// -_- shell -_-

int init_shell(shell_t *shell, char **env);
void print_the_prompt(shell_t *shell);
void destroy_shell(shell_t *shell);

int exit_mysh(ssize_t nread);

// -_- command -_-

int execute_child(shell_t *shell, char **cmd_args, char *program_path);
int execute_command(shell_t *shell, char **cmd_args, char *program_path);
int exec_command(shell_t *shell, char **cmd_args);

// -_- redirections -_-

int validity_error(shell_t *shell);
int ambiguous_error(shell_t *shell, char *message);
int file_error(shell_t *shell, char *file);

int exec_dgrt(shell_t *shell, bnode_t *node);
int exec_dlsr(shell_t *shell, bnode_t *node);
int exec_grt(shell_t *shell, bnode_t *node);
int exec_lsr(shell_t *shell, bnode_t *node);

// -_- input -_-

int process_input(shell_t *shell);

// -_- pipe -_-

void pipe_child(shell_t *shell, char **pipe_segments, int i, int prev_fd);
int execute_pipe(shell_t *shell, char **pipe_segments);
int pipe_builtin(shell_t *shell, char **pipe_segments, int i, int prev_fd);
int pipe_handler(shell_t *shell, char *command);

#endif /* !SHELL_H_ */
